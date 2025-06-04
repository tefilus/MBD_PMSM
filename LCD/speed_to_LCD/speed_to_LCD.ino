// #define BAUD_RATE 115200
// float speed;

// void setup() {
//   Serial.begin(115200);       // Terminal
//   Serial1.begin(BAUD_RATE); // UART1 để nhận từ F28069M

//   Serial.println("Done setup!");
// }

// void loop() {
//   static uint8_t buffer[4];
//   static uint8_t index = 0;

//   // Nhận byte từ UART
//   while (Serial1.available() > 0) {
//     buffer[index++] = Serial1.read();

//     // Đủ 4 byte → xử lý 1 gói
//     if (index == 4) {
//       uint16_t value1 = buffer[0] | (buffer[1] << 8);  // LSB first
//       uint16_t value2 = buffer[2] | (buffer[3] << 8);  // LSB first

//       // Kiểm tra xem đây có phải gói dữ liệu giữa không (value2 == 0x0000)
//       if (value2 == 0x0000 || value2 == 0x4545 || value1 == 0x5353) {
//         // Gói giữa hoặc đầu/cuối → giá trị thực nằm ở value1 (hoặc value2 nếu value1 là nhãn)
//         uint16_t rawVal;
//         if (value2 == 0x0000 || value2 == 0x4545) {
//           rawVal = value1;
//         } else {
//           rawVal = value2;
//         }

//         // Chuyển về float
//         speed = (float)rawVal / 4096.0 * 5159;

//         // In ra terminal
//         Serial.print("Speed = ");
//         Serial.println(speed, 3);
//       }
        
//       index = 0;  // Reset cho gói kế tiếp
//     }
//   }
// }
#define BAUD_RATE   115200
#define BASE_SPEED  (5159.0)
#define BASE_IDC    (10.417)

float speed;
float idc;

void setup() {
  Serial.begin(115200);        // Terminal
  Serial1.begin(BAUD_RATE);    // UART1 để nhận từ F28069M

  Serial.println("UART ready...");
}

void loop() {
  static uint8_t buffer[6];
  static uint8_t index = 0;

  while (Serial1.available() > 0) {
    buffer[index++] = Serial1.read();

    // Khi đã đủ 6 byte
    if (index == 6) {
      uint16_t val0 = buffer[0] | (buffer[1] << 8);  // marker hoặc giá trị
      uint16_t val1 = buffer[2] | (buffer[3] << 8);  // có thể là speed
      uint16_t val2 = buffer[4] | (buffer[5] << 8);  // có thể là idc hoặc marker

      int16_t rawSpeed = 0;
      uint16_t rawIdc = 0;

      // Xác định đúng vị trí dữ liệu
      if (val0 == 0x5353 || val0 == 0x0000 || val0 == 0x4545) {
        rawSpeed = val1;
        rawIdc = val2;
      } else if (val2 == 0x5353 || val2 == 0x0000 || val2 == 0x4545) {
        rawSpeed = val0;
        rawIdc = val1;
      } else {
        // Trường hợp không có marker → tạm bỏ qua
        index = 0;
        return;
      }

      // Chuyển về giá trị float (giả sử scale như F28069M dùng)
      speed = (float)rawSpeed / 4096.0 * BASE_SPEED;
      idc   = (float)rawIdc / 4096.0 * BASE_IDC;  // có thể scale lại nếu cần

      // In ra terminal
      Serial.print("Speed = ");
      Serial.print(speed, 3);
      Serial.print(" RPM | Idc = ");
      Serial.println(idc, 3);

      index = 0;  // reset để đọc gói tiếp theo
    }
  }
}
