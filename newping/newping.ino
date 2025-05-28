#include <NewPing.h>

//sonar(TrigPin, EchoPin, MaxDistance);
NewPing sonar(2, 3, 200);

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(50);          
  Serial.print("Ping : ");
  Serial.print(sonar.ping_cm());
  Serial.println("cm");
}
