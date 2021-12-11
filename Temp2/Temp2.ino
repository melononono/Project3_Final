/*tutorials from
https://sensorkit.arduino.cc/sensorkit/module/lessons/lesson/08-the-temperature-sensor
https://www.arduino.cc/reference/en/libraries/arduino_sensorkit/
https://create.arduino.cc/projecthub/Jasleen1429/temperature-sensor-to-control-servo-motor-b770f9?ref=search&ref_id=temperature&offset=2
*/

#include "Arduino_SensorKit.h"

#define BUZZER 5
#define BUTTON 4

int LED = 6;
int button = 4;
int temp;
int humid;
int light_sensor = A3;
int value = 0;

int tempMin = 5;

void setup() {
 Serial.begin(9600);
 Environment.begin();
 
 pinMode(BUZZER, OUTPUT);
 pinMode (BUTTON, INPUT);
 
 pinMode(LED, OUTPUT);
 digitalWrite(LED, HIGH);
 
 Oled.begin();
 Oled.setFlipMode(true);
}
 
void loop() {

  int raw_light = analogRead(light_sensor); // read the raw value from light_sensor pin (A3)
  int light = map(raw_light, 0, 750, 0, 100); // map the value from 0, 75 to 0, 100
  
  Serial.print("Temperature = ");
  Serial.print(Environment.readTemperature()); //print temperature
  Serial.println(" C");
  Serial.print("Humidity = ");
  Serial.print(Environment.readHumidity()); //print humidity
  Serial.println(" %");
  Serial.print("Light level = ");
  Serial.println(light);

  humid = Environment.readHumidity();
  temp = Environment.readTemperature();
  Oled.setFont(u8x8_font_chroma48medium8_r); 
  Oled.setCursor(0, 3);
  Oled.print(temp);
  Oled.println("C - Temp");
  Oled.println();
  Oled.print(humid);
  Oled.println("% - Humidity");
  Oled.println();
  Oled.print(light);
  Oled.println("% - Light");
  
if (temp < tempMin){
  digitalWrite(LED, HIGH);
  }
else if (light < 60){
digitalWrite(LED, HIGH);
  }
else{
  digitalWrite(LED, LOW);
}


/*if (light < 60){
digitalWrite(LED, HIGH);
  }
else {
digitalWrite(LED, LOW);
}*/

delay(1000);

}
