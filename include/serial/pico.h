#include <Serial.h>
void SerialOpen(uint8_t, uint32_t baud) {
  Serial.begin(baud);
}

void UartSendData(uint8_t) {
  Serial.write(serialBufferTX[serialTailTX[0]], 1);
}

void SerialEnd(uint8_t) {
  Serial.end();
}

void store_uart_in_buf(uint8_t, uint8_t) {

}

uint8_t SerialRead(uint8_t) {
  return Serial.read();
}

uint8_t SerialPeek(uint8_t) {
    return Serial.peek();
}

uint8_t SerialAvailable(uint8_t) {
  return Serial.available();
}