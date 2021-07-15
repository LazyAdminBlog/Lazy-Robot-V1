#include <Servo.h>      /* Attach library for using SERVO  */

#define SERVO_1_PIN 8   /* Set pin 8 as SERVO pin     */
#define TIME_OUT 10000L
Servo SERVO_1;          /* Create a Servo type structure  */

int rotate = 0;

void setup() {
    SERVO_1.attach(SERVO_1_PIN);  /* Set pin for SERVO_1            */
    SERVO_1.write(90);            /* Set 90 degree SERVO_1 (forward state). */
    Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
    while (!Serial);
    Serial.println("Enter servo rotation from 0 to 180");
    Serial.print("Rotation = ");
    Serial.println(rotate);
}

void loop() {
    static unsigned long timeLastInput = 0;
    unsigned long now = millis();
    static char buffer[10];
    static int index = 0;
    int value;
    if (Serial.available() > 0) {
        char x = Serial.read();
        timeLastInput = now;

        if (isDigit(x) || x == '-') {
            buffer[index++] = x;
        } else {
            if (index > 0) {
                buffer[index] = 0;
                if (0 <= atoi(buffer) && atoi(buffer) <= 180) {
                    rotate = atoi(buffer);
                    Serial.print("Rotation = ");
                    Serial.println(rotate);
                } else {
                    Serial.println("Rotation should be between 0 and 180");
                    Serial.print("Rotation = ");
                    Serial.println(rotate);
                }
                index = 0;
            }
        }
    }
    if (now - timeLastInput > TIME_OUT) {
        index = 0;
        timeLastInput = now;
    }
    delay(1000);          /* Wait one second  */
    SERVO_1.write(rotate);    /* Set rotate degree  */
}
