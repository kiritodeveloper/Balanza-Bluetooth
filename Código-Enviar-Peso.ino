#include "HX711.h"
#include <SoftwareSerial.h>

SoftwareSerial mySerial(10,11);

// HX711.DOUT	- pin #A1
// HX711.PD_SCK	- pin #A0

HX711 scale(A1, A0);		// parameter "gain" is ommited; the default value 128 is used by the library

void setup() {
  Serial.begin(38400);
  mySerial.begin(38400);
  Serial.println("HX711 Demo");

  scale.set_scale(29); // this value is obtained by calibrating the scale with known weights; see the README for details
  scale.tare(); // reset the scale to 0

  Serial.print("read: \t\t");
  Serial.println(scale.read()); // print a raw reading from the ADC

  Serial.print("read average: \t\t");
  Serial.println(scale.read_average(20)); // print the average of 20 readings from the ADC

  Serial.println("Readings:");
}

void loop() {
  mySerial.print("\t average(weight):\t");
  mySerial.print(scale.get_units(10));
  mySerial.println("  gram");
  //float pesa=scale.get_units(10);

  //mySerial.print(pesa);
  delay(500);
}





