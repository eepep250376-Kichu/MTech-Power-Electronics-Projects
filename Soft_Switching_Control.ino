// 25 kHz Staggered PWM for Soft-Switching Boost Converter
// Outputs on Pin 9 (Main Switch S1) and Pin 10 (Auxiliary Switch S1r)

const int mainSwitchPin = 9;   // S1
const int auxSwitchPin = 10;   // S1r

// Variables for Duty Cycle and Dead Time
float dutyCycleMain = 0.57;    // 57% Duty Cycle for Main Switch
int auxPulseWidth = 40;        // Width of the auxiliary pulse (tune for ZCS)
int deadTime = 10;             // Delay between Aux OFF and Main ON (tune for ZVS)

void setup() {
  pinMode(mainSwitchPin, OUTPUT);
  pinMode(auxSwitchPin, OUTPUT);

  // Stop interrupts while setting up Timer1
  cli(); 

  // Clear Timer1 Control Registers
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1  = 0;

  // Set Timer1 to Fast PWM Mode, with ICR1 as TOP (Mode 14)
  // Non-inverting mode on Pins 9 (COM1A1) and 10 (COM1B1)
  TCCR1A = (1 << COM1A1) | (1 << COM1B1) | (1 << WGM11);
  TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS10); // CS10 = No prescaler

  // Set TOP value for 25 kHz
  // f_PWM = f_clk / (Prescaler * (1 + TOP))
  // 25,000 = 16,000,000 / (1 * (1 + TOP))  --> TOP = 639
  ICR1 = 639;

  // Set Duty Cycles
  // OCR1A controls Pin 9 (Main)
  // OCR1B controls Pin 10 (Aux)
  OCR1A = ICR1 * dutyCycleMain; 
  OCR1B = auxPulseWidth; 

  // Re-enable interrupts
  sei(); 
}

void loop() {
  // If you want to tune the dead time or duty cycle dynamically, 
  // you can read from a potentiometer via analogRead() here and 
  // update OCR1A and OCR1B accordingly.
  
  /* Example of live tuning:
  int potValue = analogRead(A0);
  float dynamicDuty = map(potValue, 0, 1023, 100, 500) / 639.0;
  OCR1A = ICR1 * dynamicDuty;
  */
}
