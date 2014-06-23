/*******************************************************
This program was created by the
CodeWizardAVR V2.60 Evaluation
Automatic Program Generator
© Copyright 1998-2012 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : DC Electrode Multiplexer
Version : 1.0
Date    : 10/25/2013
Author  : 
Company : 
Comments: 


Chip type               : ATmega32L
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*******************************************************/

#include <mega32.h>

// Declare your global variables here
global int pulse_received = 0;
global int Num_Outputs = 22;
//
//// External Interrupt 1 service routine
interrupt [EXT_INT1] void ext_int1_isr(void)
{
pulse_received = 1;
}

void main(void)
{
// Declare your local variables here
int i = 0;
int scanning = 0;
int pulse_sent = 0;

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRA=(1<<DDA7) | (1<<DDA6) | (1<<DDA5) | (1<<DDA4) | (1<<DDA3) | (1<<DDA2) | (1<<DDA1) | (1<<DDA0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=1 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (1<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRB=(1<<DDB7) | (1<<DDB6) | (1<<DDB5) | (1<<DDB4) | (1<<DDB3) | (1<<DDB2) | (1<<DDB1) | (1<<DDB0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=1 Bit3=0 Bit2=0 Bit1=0 Bit0=1 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (1<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (1<<PORTB0);

// Port C initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRC=(1<<DDC7) | (1<<DDC6) | (1<<DDC5) | (1<<DDC4) | (1<<DDC3) | (1<<DDC2) | (1<<DDC1) | (1<<DDC0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=(0<<WGM00) | (0<<COM01) | (0<<COM00) | (0<<WGM01) | (0<<CS02) | (0<<CS01) | (0<<CS00);
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Disconnected
// OC1B output: Disconnected
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=(0<<COM1A1) | (0<<COM1A0) | (0<<COM1B1) | (0<<COM1B0) | (0<<WGM11) | (0<<WGM10);
TCCR1B=(0<<ICNC1) | (0<<ICES1) | (0<<WGM13) | (0<<WGM12) | (0<<CS12) | (0<<CS11) | (0<<CS10);
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0<<AS2;
TCCR2=(0<<PWM2) | (0<<COM21) | (0<<COM20) | (0<<CTC2) | (0<<CS22) | (0<<CS21) | (0<<CS20);
TCNT2=0x00;
OCR2=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=(0<<OCIE2) | (0<<TOIE2) | (0<<TICIE1) | (0<<OCIE1A) | (0<<OCIE1B) | (0<<TOIE1) | (0<<OCIE0) | (0<<TOIE0);

// External Interrupt(s) initialization
// INT0: On
// INT0 Mode: Rising Edge
// INT1: Off
// INT2: Off
GICR|=(0<<INT1) | (1<<INT0) | (0<<INT2);
MCUCR=(0<<ISC11) | (0<<ISC10) | (1<<ISC01) | (1<<ISC00);
MCUCSR=(0<<ISC2);
GIFR=(0<<INTF1) | (1<<INTF0) | (0<<INTF2);

// USART initialization
// USART disabled
UCSRB=(0<<RXCIE) | (0<<TXCIE) | (0<<UDRIE) | (0<<RXEN) | (0<<TXEN) | (0<<UCSZ2) | (0<<RXB8) | (0<<TXB8);

// Analog Comparator initialization
// Analog Comparator: Off
ACSR=(1<<ACD) | (0<<ACBG) | (0<<ACO) | (0<<ACI) | (0<<ACIE) | (0<<ACIC) | (0<<ACIS1) | (0<<ACIS0);
SFIOR=(0<<ACME);

// ADC initialization
// ADC disabled
ADCSRA=(0<<ADEN) | (0<<ADSC) | (0<<ADATE) | (0<<ADIF) | (0<<ADIE) | (0<<ADPS2) | (0<<ADPS1) | (0<<ADPS0);

// SPI initialization
// SPI disabled
SPCR=(0<<SPIE) | (0<<SPE) | (0<<DORD) | (0<<MSTR) | (0<<CPOL) | (0<<CPHA) | (0<<SPR1) | (0<<SPR0);

// TWI initialization
// TWI disabled
TWCR=(0<<TWEA) | (0<<TWSTA) | (0<<TWSTO) | (0<<TWEN) | (0<<TWIE);

// Global enable interrupts
#asm("sei")

void Assign_Chip_Output(i)
{
    PORTB |= 0b00010000; //inhibit multiplexer 1 (B4=1), controlled by C2, C1, C0
    PORTB |= 0b00000001; //inhibit multiplexer 2 (B0=1), controlled by B1, B2, B3
    PORTA |= 0b00010000; //inhibit multiplexer 3 (A4=1), controlled by A7, A6, A5
    
    if (i = 1) {
        PORTB &= 0b11101111; //uninhibit multiplexer 1 (B4=0)
        PORTC &= 0b11111000; //C2=0, C1=0, C0=0
    }//output 1, multiplexer 1
    else if (i = 2) {
        PORTB &= 0b11101111; //B4=0
        PORTC |= 0b00000100; //C2=1
        PORTC &= 0b11111100; //C1=0, C0=0
    }//output 2, multiplexer 1
    else if (i = 3) {
        PORTB &= 0b11101111; //B4=0
        PORTC |= 0b00000010; //C1=1
        PORTC &= 0b11111010; //C2=0, C0=0
    }//output 3, multiplexer 1
    else if (i = 4) {
        PORTB &= 0b11101111; //B4=0
        PORTC |= 0b00000110; //C2=1, C1=1
        PORTC &= 0b11111110; //C0=0
    }//output 4, multiplexer 1
    else if (i = 5) {
        PORTB &= 0b11101111; //B4=0
        PORTC |= 0b00000001; //C0=1
        PORTC &= 0b11111001; //C2=0, C1=0
    }//output 5, multiplexer 1
    else if (i = 6) {
        PORTB &= 0b11101111; //B4=0
        PORTC |= 0b00000101; //C2=1, C0=1
        PORTC &= 0b11111101; //C1=0
    }//output 6, multiplexer 1
    else if (i = 7) {
        PORTB &= 0b11101111; //B4=0
        PORTC |= 0b00000011; //C1=1, C0=1
        PORTC &= 0b11111011; //C2=0
    }//output 7, multiplexer 1
    else if (i = 8) {
        PORTB &= 0b11101111; //B4=0
        PORTC |= 0b00000111; //C2=1, C1=1, C0=1
    }//output 8, multiplexer 1
    else if (i = 9) {
        PORTB &= 0b11110000; //uninhibit multiplexer 2 (B0=0), B1=0, B2=0, B3=0
    }//output 1, multiplexer 2
    else if (i = 10) {
        PORTB &= 0b11110010; //B0=0, B2=0, B3=0
        PORTB |= 0b00000010; //B1=1
    }//output 2, multiplexer 2
    else if (i = 11) {
        PORTB &= 0b11110100; //B0=0, B1=0, B3=0
        PORTB |= 0b00000100; //B2=1
    }//output 3, multiplexer 2
    else if (i = 12) {
        PORTB &= 0b11110110; //B0=0, B3=0
        PORTB |= 0b00000110; //B1=1, B2=1
    }//output 4, multiplexer 2
    else if (i = 13) {
        PORTB &= 0b11111000; //B0=0, B1=0, B2=0
        PORTB |= 0b00001000; //B3=1
    }//output 5, multiplexer 2
    else if (i = 14) {
        PORTB &= 0b11111010; //B0=0, B2=0
        PORTB |= 0b00001010; //B1=1, B3=1
    }//output 6, multiplexer 2
    else if (i = 15) {
        PORTB &= 0b11111100; //B0=0, B1=0
        PORTB |= 0b00001100; //B2=1, B3=1
    }//output 7, multiplexer 2
    else if (i = 16) {
        PORTB &= 0b11111110; //B0=0
        PORTB |= 0b00001110; //B1=1, B2=1, B3=1
    }//output 8, multiplexer 2
    else if (i = 17) {
        PORTA &= 0b00001111; //uninhibit multiplexer 3 (A4=0), A7=0, A6=0, A5=0
    } //output 1, multiplexer 3
    else if (i = 18) {
        PORTA &= 0b10001111; //A4=0, A6=0, A5=0
        PORTA |= 0b10000000; //A7=1
    } //output 2, multiplexer 3
    else if (i = 19) {
        PORTA &= 0b01001111; //A4=0, A7=0, A5=0
        PORTA |= 0b01000000; //A6=1
    } //output 3, multiplexer 3
    else if (i = 20) {
        PORTA &= 0b11001111; //A4=0, A5=0
        PORTA |= 0b11000000; //A7=1, A6=1
    } //output 4, multiplexer 3
    else if (i = 21) {
        PORTA &= 0b00101111; //A4=0, A7=0, A6=0
        PORTA |= 0b00100000; //A5=1
    } //output 5, multiplexer 3
    else if (i = 22) {         
        PORTA &= 0b10101111; //A4=0, A6=0
        PORTA |= 0b10100000; //A7=1, A5=1
    } //output 6, multiplexer 3
    else if (i = 23) {
        PORTA &= 0b01101111; //A4=0, A7=0
        PORTA |= 0b01100000; //A6=1, A5=1
    } //output 7, multiplexer 3
    else if (i = 24) {
        PORTA &= 0b11101111; //A4=0
        PORTA |= 0b11100000; //A5=1, A6=1, A7=1
    } //output 8, multiplexer 3
           
}

while (1)
      {
      if (pulse_received == 1 && scanning == 0) { //if INT1 pulse comes in, and not currently scanning, begin scanning
         pulse_received = 0;
         scanning = 1;
         i = 1;
      }           
      
      if (scanning == 1 && pulse_sent == 0) { //if currently scanning, but not waiting for output
         Assign_Chip_Output(i);  //Depending on i, assign certain microcontroller ports to output 1, allowing one voltage through one multiplexer
         pulse_sent = 1;
      }
      
      if (pulse_received == 1 && scanning == 1) { //if INT1 pulse comes in, and currently scanning, advance to next output
        pulse_received = 0;
        pulse_sent = 0;
        i++;
        if i > Num_Outputs {
            i = 0;
            scanning = 0;
            PORTB |= 0b00010001; //B4=1, B0=1
            PORTA |= 0b00010000; //A4=1
            //inhibit all outputs
        }
      }

      }
}