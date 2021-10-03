#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif	

int main(void) {
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port B's 8 pins as outputs, initialize to 0s

	while(1) {
		unsigned char spaces_taken = ((PINA & 0x08) >> 3) + 
								((PINA & 0x04) >> 2) + 
								((PINA & 0x02) >> 1) +
								((PINA & 0x01));
								
		PORTC = (PORTC & 0xF0) | (4 - spaces_taken);

		if (spaces_taken == 4) {
			PORTC = PORTC | 0x80;
		}
	}
	return 0;
}
