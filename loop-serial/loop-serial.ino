#define GPSPowerPin 9

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
  delay(5000);

  pinMode(GPSPowerPin,OUTPUT);
  digitalWrite(GPSPowerPin,LOW);
  Serial.print("Starting loopback of Serial ports\n");
}

int b = 0;

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial1.available() > 0) {
     b = Serial1.read();
     Serial.write(b);
  }
  if (Serial.available() > 0) {
     b = Serial.read();
     Serial1.write(b);
  }

}
