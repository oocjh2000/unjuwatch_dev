#include <arduwatch.h>


#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX
Hero park;
int atk = 0;
void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(19200);

}
bool seriSt = LOW;
void loop() // run over and over
{
  atk = mySerial.parseInt();
  while (mySerial.available()) {
    if (0 < atk && atk < 20) {
      park.Hero_Discount_HP(atk);
      Serial.print(atk);

      Serial.print("         ");
      Serial.println("doscount");
      Serial.println(park.Hero_print_HP_Now());


      atk = 0;
      delay(500);
      break;
    }

  }
  atk = -1;
}

