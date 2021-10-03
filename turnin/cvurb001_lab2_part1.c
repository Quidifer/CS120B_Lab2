#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif	

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRB = 0xFF; PORTB = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s


	unsigned char tempA01 = 0x00;
	unsigned char tempB = 0x00;
	while(1) {
		tempA01 = PINA & 0x03;
		switch (tempA01) {
			case 0x00:
				tempB = 0x00;
				break;
			case 0x01:
				tempB = 0x01;
				break;
			case 0x02:
				tempB = 0x00;
				break;
			case 0x03:
				tempB = 0x00;
				break;
		}

		PORTB = tempB;
	}
	return 0;
}
