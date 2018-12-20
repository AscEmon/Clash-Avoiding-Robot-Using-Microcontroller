#define F_CPU 1000000UL   //set your clock speed
#include <avr/io.h>
#include <util/delay.h>

int right_turn=0b00000101;
int left_turn=0b00000101;
int left_sensor_off=0b00000001;
int right_sensor_off=0b00000010;
int left_sensor_on=0b00000000;
int right_sensor_on=0b00000000;

int main ()
{
     /Output port
	DDRA = 0b00000000; //input port
	int left_sensor = 0;
	int right_sensor = 0;

	while(1)   //create an infinite loop
	{
		left_sensor = (PINA & 0b00000001);
		right_sensor = (PINA & 0b00000010);

		if(( left_sensor==left_sensor_off) & (right_sensor==right_sensor_off))
         {
			PORTD=0b00000101;
			_delay_ms(100);         //move forward
		}
        if(( left_sensor==left_sensor_off) & (right_sensor==right_sensor_on))
        {
			PORTD=0b000001001;      //turn right
			_delay_ms(200);
			PORTD=right_turn;
		}
		if(( left_sensor==left_sensor_on) & (right_sensor==right_sensor_off))
		{
			PORTD=0b00000110;
			_delay_ms(200);           //turn left
			PORTD=left_turn;
        }
		if((left_sensor==left_sensor_on) & (right_sensor==right_sensor_on))
		{
			PORTD=0b00000000;
			_delay_ms(100);            //stop
		}
	}
}
