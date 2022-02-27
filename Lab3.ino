//**************************//
// Skeleton code of LAB 3   //
//**************************//
//===============================================
//  Connection:
//    (Arduino) PIN 9   -> MOTOR 1 SIGNAL
//    (Arduino) PIN 10  -> MOTOR 2 SIGNAL
//===============================================

void setup() {
  
  pinMode(9, OUTPUT);   
  pinMode(10, OUTPUT);  
 
  /*
   * 
   * How the ATMEGA328p timer works in our experiment :
   * 
   * A 16-bit value (called the counter) is incremented by 1 everytime the timer ticks
   * The frequency at which the timer ticks is given as below:
   * Tick frequency = FclkIO (16 MHz for Arduino Nano) / prescaler (a value we set, can be 1, 8, 64, 256 or 1024)
   * 
   * Initially, the counter starts counting up from 0, and the PWM output pin is set to HIGH
   * When the counter value matches the value stored in register OCR1A, pin 9 is set to LOW, counter continues to count up
   * When the counter value matches the value stored in register OCR1B, pin 10 is set to LOW, counter continues to count up
   * When the counter value matches the value stored in register ICR1, the counter value resets to 0, and both pins are set to HIGH
   * 
   * In order for the TIMER to function as described, TIMER 1 register TCCR1A and TCCR1B must be configured to work at mode 10
   * 
   * Our motor control pin expects a pulse signal every 20 msec (50Hz)
   * the motor spins clockwise at max speed when the signal is HIGH for 500 usec
   * the motor spins anti-clockwise at max speed when the signal is HIGH for 2500 usec
   * the motor does not spin when the output on-time is 1500 usec
   * 
   * Given this information, you need to determine:
   * What value to set TCCR1A and TCCR1B to, for the timer to work at mode 10, and tick at FclkIO / 8
   * What value to set ICR1 to, for the timer PWM output to work at 50Hz
   * What value to set OCR1A to, for pin 9 to be HIGH for a specific time, so that a motor spins clockwise at max speed
   * What value to set OCR1B to, for pin 10 to be HIGH for a specific time, so that a motor spins anti-clockwise at half speed
   * 
   */
  
  // Refer to page 103, 104 and 108 to 110 of the ATMEGA328P datasheet, 
  // configure TCCR1A and TCCR1B so that TIMER 1 works with the following configuration
  // - Waveform generation mode 10 (PWM, phase correct, 16 bit, up counting)
  // - PWM output pins is cleared (set to LOW) on compare match, otherwise the pin is HIGH
  // - TIMER 1 is clocked at FclkIO / 8
  TCCR1A = ; /* mode 10: PWM, phase correct, 16-bit */
  TCCR1B = ; /* prescale TIMER 1 to FclkIO / 8 */
 
  // Given :
  // FclkIO = 16MHz
  // TIMER 1 is clocked at Fclkio / 8
  // Set ICR1 so that the output PWM frequency is 50Hz
  ICR1 = ; /* TOP set to 20000 in order to get 50Hz */
 
  // Given the motor :
  // spins clockwise at max speed when the output on-time is 500usec
  // spins anti-clockwise at max speed when the output on-time is 2500usec
  // does not spin when the output on-time is 1500usec
 
  // OCR1A sets the on-time of pin 9
  // OCR1B sets the on-time of pin 10
 
  // Set the motor connected to pin 9 to spin clockwise at max speed
  // Set the motor connected to pin 10 to spin anti-clockwise at half speed
  
  OCR1A = ;
  OCR1B = ;
 
}
 
void loop() {
 
}
