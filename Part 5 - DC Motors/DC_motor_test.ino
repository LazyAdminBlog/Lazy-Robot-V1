/*                      Download from Lazy Admin Blog                        */
/* Blog URL:     https://lazyadminblog.blogspot.com                          */
/* Mail:         lazychannelandblog@gmail.com                                */
/* YouTube:      https://www.youtube.com/channel/UC8DB_NVekpEIuG-SAvpXOWQ    */
/* GitHub:       https://github.com/LazyAdminBlog                            */

int MOTOR_1_RIGHT_DIRECTION = 4;	/*	Variable to save Motor 1 direction.						*/
int MOTOR_1_RIGHT_SPEED = 5;		/*	Variable to save Motor 1 speed (values from 0 to 255).	*/

int MOTOR_2_LEFT_SPEED = 6;			/*	Variable to save Motor 2 speed (values from 0 to 255).	*/
int MOTOR_2_LEFT_DIRECTION = 7;		/*	Variable to save Motor 2 direction						*/

void motor_stop(void) /* Function to stop robot (stop motors) */
{
  digitalWrite(MOTOR_1_RIGHT_SPEED,LOW);	/* Set low signal on right motor                */
  digitalWrite(MOTOR_2_LEFT_SPEED,LOW);		/* Set low signal on left motor                */
}

void motor_drive_forward(char a, char b)      /* Function to driveing forward using motors    */
{
  analogWrite(MOTOR_1_RIGHT_SPEED,a);         /* Set speed of right motor                     */
  digitalWrite(MOTOR_1_RIGHT_DIRECTION,LOW);  /* Set low signal on right motor                */
  analogWrite(MOTOR_2_LEFT_SPEED,b);          /* Set speed of left motor                      */
  digitalWrite(MOTOR_2_LEFT_DIRECTION,LOW);   /* Set low signal on left motor                 */
}

void motor_drive_back(char a, char b)         /* Function to driveing back using motors */
{
  analogWrite(MOTOR_1_RIGHT_SPEED,a);         /* Set speed of right motor               */
  digitalWrite(MOTOR_1_RIGHT_DIRECTION,HIGH); /* Set high signal on right motor         */
  analogWrite(MOTOR_2_LEFT_SPEED,b);          /* Set speed of left motor                */
  digitalWrite(MOTOR_2_LEFT_DIRECTION,HIGH);  /* Set high signal on left motor          */
}

void motor_turn_right(char a, char b)		  /* Fuction to turn right the robot.		*/
{
  analogWrite(MOTOR_1_RIGHT_SPEED,a);         /* Set speed of right motor               */
  digitalWrite(MOTOR_1_RIGHT_DIRECTION,LOW);  /* Set low signal on right motor          */
  analogWrite(MOTOR_2_LEFT_SPEED,b);          /* Set speed of left motor                */
  digitalWrite(MOTOR_2_LEFT_DIRECTION,HIGH);  /* Set high signal on left motor          */
}

void motor_turn_left(char a, char b)		  /* Fuction to turn left the robot.		*/
{
  analogWrite(MOTOR_1_RIGHT_SPEED,a);         /* Set speed of right motor               */
  digitalWrite(MOTOR_1_RIGHT_DIRECTION,HIGH); /* Set high signal on right motor         */
  analogWrite(MOTOR_2_LEFT_SPEED,b);          /* Set speed of left motor                */
  digitalWrite(MOTOR_2_LEFT_DIRECTION,LOW);   /* Set low signal on left motor           */
}

void setup()
{
  /* Set pins 4, 5, 6,7 as OUTPUT (pins for left and right motor */
  for(int i=4; i<=7; ++i)
  {
    pinMode(i,OUTPUT);	/* Mode pin "i" as output pin. */
  }
}

void loop()
{
  motor_drive_forward(255,255);	/*	Drive forwart with maximal speed											*/
  delay(8000);					/*	Wait 8 secound																*/
  motor_stop();					/*	Stop all motos																*/
  delay(8000);					/*	Wait 8 secound 																*/
  motor_drive_back(255,255);	/*	Drive back with maximal speed												*/
  delay(8000);					/*	Wait 8 secound 																*/
  motor_stop();					/*	Stop all motos																*/
  delay(8000);					/*	Wait 8 secound 																*/
  motor_turn_right(150,150);	/*	Turn right with 150/255 speed. It is minimal speed for rotate robot			*/
  delay(8000);					/*	Wait 8 secound 																*/
  motor_stop();					/*	Stop all motos																*/
  delay(8000);					/*	Wait 8 secound 																*/
  motor_turn_left(150,150);		/*	Turn left with 150/255 speed. It is minimal speed for rotate robot			*/
  delay(8000);					/*	Wait 8 secound 																*/
  motor_stop();					/*	Stop all motos																*/
  delay(8000);					/*	Wait 8 secound 																*/
}
