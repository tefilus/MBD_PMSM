#define BAUD_RATE 115200

volatile uint8_t buffer[4];
volatile uint8_t index = 0;

volatile bool newSpeedReady = false;
volatile float latestSpeed = 0;

unsigned long lastPrintTime = 0;
unsigned long speed;

void setup() {
  Serial.begin(115200);       // Terminal
  Serial1.begin(BAUD_RATE);   // UART1 để nhận từ F28069M
  Serial.println("UART ready...");
}
void loop(){
//Nhận byte từ UART
    while (Serial1.available() > 0)
    {
        buffer[index++] = Serial1.read();

        // Đủ 4 byte → xử lý 1 gói
        if (index == 4) 
        {
            uint16_t value1 = buffer[0] | (buffer[1] << 8);  // LSB first
            uint16_t value2 = buffer[2] | (buffer[3] << 8);  // LSB first

            // Kiểm tra xem đây có phải gói dữ liệu giữa không (value2 == 0x0000)
            if (value2 == 0x0000 || value2 == 0x4545 || value1 == 0x5353)
            {
                // Gói giữa hoặc đầu/cuối → giá trị thực nằm ở value1 (hoặc value2 nếu value1 là nhãn)
                uint16_t rawVal;
                if (value2 == 0x0000 || value2 == 0x4545)
                {
                    rawVal = value1;
                } 
                else 
                {
                    rawVal = value2;
                }

                // Chuyển về float
                speed = (float)rawVal / 4096.0 * 5100;
                Serial.println(speed);
            }

            if (index >= sizeof(buffer)) index = 0;  // Reset cho gói kế tiếp
        }
    }}