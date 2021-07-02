#define LEDPIN_PINMODE             pinMode(LED_BUILTIN, OUTPUT)
  #define LEDPIN_TOGGLE              gpio_put(LED_BUILTIN, !digitalRead(LED_BUILTIN));
  #define LEDPIN_ON                  gpio_put(LED_BUILTIN, HIGH);
  #define LEDPIN_OFF                 gpio_put(LED_BUILTIN, LOW);
  #define BUZZERPIN_PINMODE            pinMode(4, OUTPUT)
  #if defined PILOTLAMP
    #define PL_PIN_ON                  gpio_put(4, HIGH);
    #define PL_PIN_OFF                 gpio_put(4, LOW);
  #else
    #define BUZZERPIN_ON               gpio_put(4, HIGH);
    #define BUZZERPIN_OFF              gpio_put(4, LOW);
  #endif 
    
  #if !defined(DISABLE_POWER_PIN)
    #define POWERPIN_PINMODE           pinMode(5, OUTPUT)
    #define POWERPIN_ON                gpio_put(5, HIGH);
    #define POWERPIN_OFF               gpio_put(5, LOW);
  #else
    #define POWERPIN_PINMODE           ;
    #define POWERPIN_ON                ;
    #define POWERPIN_OFF               ;
  #endif
  #define I2C_PULLUPS_ENABLE         pinMode(8, INPUT_PULLUP);       // PIN 20&21 (SDA&SCL)
  #define I2C_PULLUPS_DISABLE        pinMode(9, INPUT);
  #define PINMODE_LCD                DDRE |= 1<<0; // Arduino pin 0
  #define LCDPIN_OFF                 PORTE &= ~1; //switch OFF digital PIN 0
  #define LCDPIN_ON                  PORTE |= 1;
  #define STABLEPIN_PINMODE          pinMode(22, OUTPUT); // Arduino pin 31
  #define STABLEPIN_ON               gpio_put(22, HIGH);
  #define STABLEPIN_OFF              gpio_put(22, LOW);
  #if defined(PPM_ON_THROTTLE)
    //configure THROTTLE PIN (A8 pin) as input witch pullup and enabled PCINT interrupt
    #define PPM_PIN_INTERRUPT        DDRK &= ~(1<<0); PORTK |= (1<<0);  PCICR |= (1<<2); PCMSK2 |= (1<<0);
  #else
    #define PPM_PIN_INTERRUPT        attachInterrupt(4, rxInt, RISING);  //PIN 19, also used for Spektrum satellite option
  #endif
  #if !defined(RX_SERIAL_PORT)
    #define RX_SERIAL_PORT           1
  #endif
  //RX PIN assignment inside the port //for PORTK
  #define THROTTLEPIN                26  //PIN 62 =  PIN A8
  #define ROLLPIN                    27  //PIN 63 =  PIN A9
  #define PITCHPIN                   2  //PIN 64 =  PIN A10
  #define YAWPIN                     3  //PIN 65 =  PIN A11
  #define AUX1PIN                    4  //PIN 66 =  PIN A12
  #define AUX2PIN                    5  //PIN 67 =  PIN A13
  #define AUX3PIN                    6  //PIN 68 =  PIN A14
  #define AUX4PIN                    7  //PIN 69 =  PIN A15
  #define V_BATPIN                   A0    // Analog PIN 0
  #define PSENSORPIN                 A2    // Analog PIN 2
  #define PCINT_PIN_COUNT            8
  #define PCINT_RX_BITS              (1<<2),(1<<4),(1<<5),(1<<6),(1<<7),(1<<0),(1<<1),(1<<3)
//   #define PCINT_RX_PORT              PORTK
//   #define PCINT_RX_MASK              PCMSK2
  #define PCIR_PORT_BIT              (1<<2)
  #define RX_PC_INTERRUPT            1
  #define RX_PCINT_PIN_PORT          PINK
  
  #define SERVO_1_PINMODE            pinMode(18, OUTPUT); // Arduino pin 34 , pin 44 // TILT_PITCH - WING left
  #define SERVO_1_PIN_HIGH           gpio_put(18, HIGH);
  #define SERVO_1_PIN_LOW            gpio_put(18, LOW);
  #define SERVO_2_PINMODE            pinMode(19, OUTPUT); // Arduino pin 35 , pin 45 // TILT_ROLL  - WING right
  #define SERVO_2_PIN_HIGH           gpio_put(19, HIGH);
  #define SERVO_2_PIN_LOW            gpio_put(19, LOW);
  #define SERVO_3_PINMODE            pinMode(20, OUTPUT); // Arduino pin 33 , pin 46 // CAM TRIG  - alt TILT_PITCH
  #define SERVO_3_PIN_HIGH           gpio_put(20, HIGH);
  #define SERVO_3_PIN_LOW            gpio_put(20, LOW);
//   #define SERVO_4_PINMODE            DDRC |= 1<<0; DDRH |= 1<<4; // Arduino pin 37 , pin 7 // new       - alt TILT_ROLL
//   #define SERVO_4_PIN_HIGH           PORTC |= 1<<0; PORTH |= 1<<4;
//   #define SERVO_4_PIN_LOW            PORTC &= ~(1<<0);PORTH &= ~(1<<4);

//   #define SERVO_5_PINMODE            DDRH |= 1<<3; // Arduino pin 6                        // BI LEFT
//   #define SERVO_5_PIN_HIGH           PORTH |= 1<<3;
//   #define SERVO_5_PIN_LOW            PORTH &= ~(1<<3);
  #define SERVO_6_PINMODE            pinMode(21, OUTPUT) // Arduino pin 2                        // TRI REAR - BI RIGHT
  #define SERVO_6_PIN_HIGH           gpio_put(21, HIGH);
  #define SERVO_6_PIN_LOW            gpio_put(21, LOW);
//   #define SERVO_7_PINMODE            DDRE |= 1<<3; // Arduino pin 5                        // new
//   #define SERVO_7_PIN_HIGH           PORTE |= 1<<3;
//   #define SERVO_7_PIN_LOW            PORTE &= ~(1<<3);
//   #define SERVO_8_PINMODE            DDRE |= 1<<5; // Arduino pin 3                        // new
//   #define SERVO_8_PIN_HIGH           PORTE |= 1<<5;
//   #define SERVO_8_PIN_LOW            PORTE &= ~(1<<5);