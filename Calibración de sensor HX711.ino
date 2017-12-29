#include "HX711.h"



// HX711.DOUT  - pin #A1

// HX711.PD_SCK - pin #A0



HX711 scale(A1, A0);



float read_ADC;

float read_load;

float read_average;



void setup() {

  Serial.begin(38400);

  scale.set_scale(); // this value is obtained by calibrating the scale with known weights; see the README for details

  scale.tare();               // reset the scale to 0

  //long b=scale.read_average();
  Serial.print("read: \t\t");

  Serial.println("Put 5.6kg");

  delay(5000);
  long x= scale.get_units(10);

  //long x = scale.read_average();
 // long y = 5600;
  //double m = (double )(y-b)/x;
  long m = x/5600;
  Serial.println(x);  // print a raw reading from the ADC

  Serial.println(m);
  /*Serial.print("b: ");
  Serial.println(b);
  Serial.print("x: ");
  Serial.println(x);
  Serial.print("y: ");
  Serial.println(y);
  Serial.print("m: ");
  Serial.println(m);
  */
  
  

}

void loop() {

 


}
