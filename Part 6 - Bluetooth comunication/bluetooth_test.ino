/*                      Download from Lazy Admin Blog                        */
/* Blog URL:     https://lazyadminblog.blogspot.com                          */
/* Mail:         lazychannelandblog@gmail.com                                */
/* YouTube:      https://www.youtube.com/channel/UC8DB_NVekpEIuG-SAvpXOWQ    */
/* GitHub:       https://github.com/LazyAdminBlog                            */

int BLUETOOTH_SERIAL_INPUT;	/* Variable to save input data from bluetooth module */

void setup()
{
  Serial1.begin(9600);		/* Begin serial port (bluetooth port). Set the data rate in bits (9600 bits per second (baud).	*/
  Serial1.println("Bluetooth X-Bee comunication test sucessful.");		/* Write to serial port (bluetooth) control text.	*/
}

void loop()
{
  if(Serial1.available() >= 0)	/* Check available of serial port (bluetooth) and chack which number was input (if >= go to next step).	*/
  {
      BLUETOOTH_SERIAL_INPUT = Serial1.read(); 	/* Read data from serial port (bluetooth) and save to BLUETOOTH_SERIAL_INPUT variable	*/
  }
  switch(BLUETOOTH_SERIAL_INPUT)              /*  Switch case instruction to control robot                                  */
  {
    case '1':
      Serial1.println("First test pass."); 		/* Write text: "First test pass." if read "1" from serial port (bluetooth).		*/
      break;
    case '2':
      Serial1.println("Second test pass.");		/* Write text: "Second test pass." if read "2" from serial port (bluetooth).	*/
      break;
    default:
      break;
  }
}
