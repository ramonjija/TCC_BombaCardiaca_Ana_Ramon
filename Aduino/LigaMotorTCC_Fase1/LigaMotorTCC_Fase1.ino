const int pinDir = 4;
const int pinStep = 3;


void setup() {
  // put your setup code here, to run once:
  pinMode(pinDir, OUTPUT);
  pinMode(pinStep, OUTPUT);
  digitalWrite(pinDir, HIGH);
  digitalWrite(pinStep, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinStep, HIGH);
  delayMicroseconds(100);
  digitalWrite(pinStep, LOW);
  delayMicroseconds(100);
}
