/*                      Download from Lazy Admin Blog                        */
/* Blog URL:     https://lazyadminblog.blogspot.com                          */
/* Mail:         lazychannelandblog@gmail.com                                */
/* YouTube:      https://www.youtube.com/channel/UC8DB_NVekpEIuG-SAvpXOWQ    */
/* GitHub:       https://github.com/LazyAdminBlog                            */

#include <Servo.h>      /* Attach library for using SERVO	*/

#define SERVO_1_PIN 8   /* Set pin 8 as SERVO pin			*/

Servo SERVO_1;          /* Create a Servo type structure	*/

void setup()
{
  SERVO_1.attach(SERVO_1_PIN);  /* Set pin for SERVO_1						*/
  SERVO_1.write(90);            /* Set 90 degree SERVO_1 (forward state).	*/
}

void loop()
{
  delay(2000);          /* Wait two second	*/
  SERVO_1.write(180);   /* Set 180 degree	*/
  delay(2000);          /* Wait two second	*/
  SERVO_1.write(90);    /* Set 90 degree	*/
  delay(2000);          /* Wait two second	*/
  SERVO_1.write(0);     /* Set 0 degree		*/
  delay(2000);          /* Wait two second	*/
  SERVO_1.write(90);    /* Set 90 degree	*/
}
