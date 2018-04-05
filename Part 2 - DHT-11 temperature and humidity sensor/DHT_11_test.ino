/*                      Download from Lazy Admin Blog                        */
/* Blog URL:     https://lazyadminblog.blogspot.com                          */
/* Mail:         lazychannelandblog@gmail.com                                */
/* YouTube:      https://www.youtube.com/channel/UC8DB_NVekpEIuG-SAvpXOWQ    */
/* GitHub:       https://github.com/LazyAdminBlog                            */

#include "DHT.h" /*Include (add to sketch) DHT.h library for DHT sensor*/

#define DTH_SENSOR_PIN 9  /*Set witch pin connect to DHT11 sensor*/
#define DHTTYPE DHT11     /*Set sensor type (model): DHT11*/

DHT dht(DTH_SENSOR_PIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);                /*Initial serio port (COM) for arduino.*/
  Serial.println("DHT11 test!");     /*Write initial success test/*/
  dht.begin();                       /*Initial dht sensor.*/
}

void loop()
{
  delay(2000); /*Wait a few seconds between measurements.*/
  
  float h = dht.readHumidity();         /*Read humidity from sensor*/
  float t = dht.readTemperature();      /*Read temperature as Celsius (the default)*/
  float f = dht.readTemperature(true);  /*Read temperature as Fahrenheit (isFahrenheit = true)*/
  
  /* Check if any reads failed and exit early (to try again).*/
  if (isnan(h) || isnan(t) || isnan(f))
  {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  
  float hif = dht.computeHeatIndex(f, h);         /* Compute heat index in Fahrenheit (the default)*/
  float hic = dht.computeHeatIndex(t, h, false);  /* Compute heat index in Celsius (isFahreheit = false) */

  /*Start show read value on serial port.*/
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" °C ");
  Serial.print(f);
  Serial.print(" °F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" °C ");
  Serial.print(hif);
  Serial.println(" °F");
  /*End of show data.*/
}
