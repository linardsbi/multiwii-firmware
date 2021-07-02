#include <Wire.h>

uint8_t previous_address = 0;

void i2c_init(void) {
    Wire.begin();
    Wire.setClock(400'000);
}

void __attribute__ ((noinline)) waitTransmissionI2C() {
  auto count = 255;
  while (!Wire.available()) {
    count--;
    if (count==0) {              //we are in a blocking state => we don't insist
      #if defined(WMP)
      neutralizeTime = micros(); //we take a timestamp here to neutralize the value during a short delay
      #endif
      i2c_errors_count++;
      break;
    }
  }
}

// void i2c_write(uint8_t data) {
//     Wire.beginTransmission(previous_address);
//     Wire.write(data);
//     Wire.endTransmission();
// }

void i2c_rep_start(uint8_t address) {
    Wire.beginTransmission(address);
}

void i2c_stop(void) {
    Wire.endTransmission();
}

void i2c_write(uint8_t data ) {
  Wire.write(data);
}

uint8_t i2c_readAck() {
    int timeout = 255;

    do {
        if (Wire.available()) break;
        timeout++;
    } while (timeout > 0);

    return Wire.read();
}

uint8_t i2c_readNak() {
  waitTransmissionI2C();
  uint8_t r = Wire.read();
  i2c_stop();
  return r;
}

void i2c_read_reg_to_buf(uint8_t add, uint8_t reg, uint8_t *buf, uint8_t size) {
  i2c_rep_start(add<<1); // I2C write direction
  i2c_write(reg);        // register selection
  i2c_rep_start((add<<1) | 1);  // I2C read direction
  uint8_t *b = buf;
  while (--size) *b++ = i2c_readAck(); // acknowledge all but the final byte
  *b = i2c_readNak();
}

void i2c_getSixRawADC(uint8_t add, uint8_t reg) {
  i2c_read_reg_to_buf(add, reg, rawADC, 6);
}

void i2c_writeReg(uint8_t add, uint8_t reg, uint8_t val) {
  i2c_rep_start(add<<1); // I2C write direction
  i2c_write(reg);        // register selection
  i2c_write(val);        // value to write in register
  i2c_stop();
}

uint8_t i2c_readReg(uint8_t add, uint8_t reg) {
  uint8_t val;
  i2c_read_reg_to_buf(add, reg, &val, 1);
  return val;
}