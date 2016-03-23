//Description: 2x16 LCD display demo 
//Author: Kevin Chiu
//Circuit connections: pls refer to #define comment description

#define RS_D12 12  // connect to LCD RS pin
#define Enable_D11 11  // connect to LCD enable pin
#define D2_pin 2  	// connect to LCD D4 pin
#define D3_pin 3	// connect to LCD D5 pin
#define D4_pin 4	// connect to LCD D6 pin
#define D5_pin 5	// connect to LCD D7 pin

#include <LiquidCrystal.h>

//constructor -> LiquidCrystal(rs, enable, d4, d5, d6, d7) 
LiquidCrystal lcd( RS_D12, Enable_D11, D2_pin, D3_pin, D4_pin, D5_pin  );

const char *text[] = {	"Hi,Arduino Nano!",
						"Good Day!",
						"LCD size 16x2"
					 };

void setup()
{
	Serial.begin(9600);
	lcd.begin(16,2);
	// lcd.print("Hello, Nano!");
}


void loop()
{
	lcd.clear();
	display_text(2000);
}


void display_text(int delay_t)
{
	unsigned long sec;

	for(int i=0; i< 3; i++)
	{
		sec = millis()/1000;

		lcd.clear();
		lcd.print(text[i]);

		lcd.setCursor(0,1);
		lcd.print(sec);

		delay(delay_t);
	}
	

}

