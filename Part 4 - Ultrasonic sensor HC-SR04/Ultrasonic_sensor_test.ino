/*                      Download from Lazy Admin Blog                        */
/* Blog URL:     https://lazyadminblog.blogspot.com                          */
/* Mail:         lazychannelandblog@gmail.com                                */
/* YouTube:      https://www.youtube.com/channel/UC8DB_NVekpEIuG-SAvpXOWQ    */
/* GitHub:       https://github.com/LazyAdminBlog                            */

#define ULTRASONIC_TRIG_PIN 11	/* Define witch pin will be HC-SR04 TRIG */
#define ULTRASONIC_ECHO_PIN 12	/* Define witch pin will be HC-SR04 ECHO */

int read_disaince()
{
  long duration, distance;							/* Declarete duratuion and distance variable long type	*/
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);			/* Chance TRIG pin state to LOW							*/
  delayMicroseconds(2);								/* Wait 2 miliseconds									*/
  digitalWrite(ULTRASONIC_TRIG_PIN, HIGH);			/* Chance TRIG pin state to HIGH						*/
  delayMicroseconds(10);							/* Wait 10 miliseconds									*/
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);			/* Chance TRIG pin state to LOW							*/
  duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH);	/* pulseln() on ECHO pin to HIGH						*/
  distance = (duration/2) / 29.1;					/* distaince calculation								*/
  
  if (distance >= 200 || distance <= 0)		/* If read value is >=200 or >=0	*/
  {
    return 999;			/*  Function return 999 it's error (out of range)		*/
  }
  else
  {
    return distance;	/* Function return correct distaince					*/
  }
}

void setup()
{
	Serial.begin(9600);		/* Initial serial port (COM) for arduino with 9600 bits per second speed */
	pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);	/* Set TRIG pin as output*/
	pinMode(ULTRASONIC_ECHO_PIN, INPUT);	/* Set ECHO pin as input*/
}

void loop()
{
	Serial.println(read_disaince());	/* Print for serial result of function read_disaince() */
	delay(500);							/* Wait 0.5 second	*/
}
