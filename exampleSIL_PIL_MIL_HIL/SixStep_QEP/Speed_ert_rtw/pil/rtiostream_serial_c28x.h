// Created on 21-Mar-2025 08:51:55
#ifndef RTIOSTREAM_SERIAL_C28X_H_
#define RTIOSTREAM_SERIAL_C28X_H_

#include "MW_target_hardware_resources.h"

// Baud Rate = 5625000
#define MW_PIL_SCIHBAUD 0
#define MW_PIL_SCILBAUD 1

#define EXT_SCI_RX_PIN 28
#define EXT_SCI_TX_PIN 29

#define RX_PIN_MUX_VAL 1
#define TX_PIN_MUX_VAL 1

extern void init_board(void);

#endif
