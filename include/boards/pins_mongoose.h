#define LEDPIN_PINMODE             pinMode (4, OUTPUT);
  #define LEDPIN_TOGGLE              PIND |= 1<<4;     //switch LEDPIN state (digital PIN 13)
  #define LEDPIN_OFF                 PORTD &= ~(1<<4);  
  #define LEDPIN_ON                  PORTD |= (1<<4);     
  #define SPEK_BAUD_SET              UCSR0A  = (1<<U2X0); UBRR0H = ((F_CPU  / 4 / 115200 -1) / 2) >> 8; UBRR0L = ((F_CPU  / 4 / 115200 -1) / 2);
  #define RX_SERIAL_PORT             0

  /* Unavailable pins on MONGOOSE1_0 */
  #define BUZZERPIN_PINMODE          ; // D8
  #define BUZZERPIN_ON               ;
  #define BUZZERPIN_OFF              ;
  #define POWERPIN_PINMODE           ; // D12
  #define POWERPIN_ON                ;
  #define POWERPIN_OFF               ;
  #define STABLEPIN_PINMODE          ; //
  #define STABLEPIN_ON               ;
  #define STABLEPIN_OFF              ; 
  #define PINMODE_LCD                ; //
  #define LCDPIN_OFF                 ;
  #define LCDPIN_ON                  ; 
  
  
  #define SERVO_4_PINMODE            ;                   // Not available
  #define SERVO_4_PIN_HIGH           ;
  #define SERVO_4_PIN_LOW            ;