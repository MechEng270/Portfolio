#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//sets variables
const uint16_t arrayMax = 1500;
uint8_t ring[arrayMax];
uint16_t counter = 0;
uint16_t head = 0;
uint16_t tail = arrayMax-1;
int pop();
void push(uint8_t n);
int butt = 1;
uint8_t tim = 0;
bool LED = 0;




int main(){
  cli();
  // setting pin 13 as output 
  DDRB |= (1 << PB5);
  DDRB |= (1 << PB4);
  //sets button as in
  DDRD &= ~(1 << PD2);

  // using analog input A0
  ADMUX = 0x0;
  // setting the adc clock speed to 500kHz by using a prescalar of 16
  ADCSRA |= (1<<ADPS2) | (1<<ADPS1);
  // left adjusting the ADC 
  ADMUX |= (1<<ADLAR);
  // setting the reference voltage to 5V
  ADMUX |= (1<<REFS0);
  // enabling the ADC
  ADCSRA |= (1<<ADEN);

  

    // Set up Timer1 to trigger an interrupt every 5ms
  // TCCR1B = (1 << WGM12) | (1 << CS12); // CTC mode, prescaler 256
  // OCR1A = 10000; // 5ms interrupt interval
  // TIMSK1 = (1 << OCIE1A); // Enable Timer1 output compare match A interrupt

  // setting timer 1 to default states
  TCCR1A = 0; 
  TCCR1B = 0;
  // setting timer 1 to start counting from 0 
  TCNT1 = 0;
  // setting timer 1 to CTC mode and the prescaler to 256
  TCCR1B = (1<<WGM12) | (1<<CS12);
  // setting the compare register to 312, 312 == 5ms
  OCR1A = 312;
  // setting interrupt to occur when counter matches to OCR1A
  TIMSK1 |= (1 << OCIE1A);

  Serial.begin(9600);
  sei();

  //loop
  while(1){
    //if transferings, turns led on
  }
  return 0;
}

//interrupts
ISR(TIMER1_COMPA_vect){

  //sets timer count in bunches if 5ms, 200 tim = 1000ms , and caps out at 200 tims
  tim = (tim + 1) % 200;

  //if recording
  if(butt){
    //every 1000ms(1Hz) it switches led state
    if(!tim){
      flop();
    }


  //IF TRANSFERRING
  }else if(!butt){
    if(!(tim % 100)){
      //erry 500ms(2Hz) it switches led state
      flop();
    }
  }



   //if the button is pressed, switches state(between transfering and recording)
    if(PIND & (1 << PD2)){
      //waits for button to be unpressed
      while(PIND & (1 << PD2)){
      }
    butt = (butt + 1) % 2; 
    if(butt == 1){
      //if switching state from transferring to recording, resets the buffer ring
      memset(ring, 0, sizeof ring);
    }
    }
  
  //records data 
  if(butt){
    //sets counter to 0 for the transferring
    counter = 0;
    //activates the adc conversion
    ADCSRA |= (1 << ADEN);
     // start the adc conversion
    ADCSRA |= (1 << ADSC);
     // waiting for the conversion to complete
    while (ADCSRA & (1 << ADSC));
    // adjusting positions of the ring buffer, the head and tail
    push(ADCH);
    pop();

    //transfers data
  }else if(!butt){
    //stops adc conversion
    ADCSRA &= ~(1 << ADEN);
    //PORTB &= ~(1 << PB5);
    //prints out the values 
    if (counter < arrayMax){
      Serial.println(ring[counter]);
    counter++;
    //if reached end of array, stops printing
    }else if(counter == arrayMax){
      counter = 1501;
    }
  }
  }
//pushes the head forward while rewriting neks value
void push(uint8_t n){
  ring[head] = n;
  head = (head + 1) % arrayMax;
}

//pops the tail to the next
int pop(){
  int value = ring[tail];
  tail = (tail+1) % arrayMax;
  return value;
}

//switches the led state
void flop(){
  if(LED == 0){
    PORTB |= (1 << PB5);
    LED = 1;
  }else {
    PORTB &= ~(1 << PB5);
    LED = 0;
  }
  

}

