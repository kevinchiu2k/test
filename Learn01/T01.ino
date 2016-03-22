
#define Led_pin 13

String str("");
long num;


void setup()
{
	Serial.begin(9600);
	Serial.println("nano ready...");

	pinMode(Led_pin , OUTPUT );
}


void loop()
{

	if(Serial.available())
	{
		str = Serial.readString();
		num = str.toInt();
		Serial.print("blink time (msec) = "); Serial.println(num);
		delay(100);
	}

	if(num >0 )	Blink(num);
}

void Blink(unsigned int tt)
{
	digitalWrite(Led_pin, HIGH );
	delay(tt);
	digitalWrite(Led_pin, LOW );
	delay(tt);

}