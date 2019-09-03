#include "wombling.h"

#define MINA0 127
#define MINA1 127
#define MINA2 127
#define MINA3 127

long s1, s2, s3, s4;
vector v;

void setup()
{
  Serial.begin(9600);
  s1 = 0;
  s2 = 0;
  s3 = 0;
  s4 = 0;
}

void loop() {
  //toma una muestra de varias medidas
  for (int i = 0; i < 200; i++) {
    s1 += vol(A0, MINA0);
    s2 += vol(A1, MINA1);
    s3 += vol(A2, MINA2);
    s4 += vol(A3, MINA3);
  }
      v = gradient(s1, s2, s3, s4);
      Serial.print(v.mag);
      Serial.print(",");
      //angle in radians
      //To point to light
      Serial.println(v.ang);

}

//ejemplo con microfonos para establecer 127 como el 0
int vol(int pin, int m) {
  int val = analogRead(pin)-m ;
  return (abs(val)>3)?1:0;
}
