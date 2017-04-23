const int pinMotor = 2;
const int pinPasso = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinMotor,OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinMotor,HIGH);
  digitalWrite(LED_BUILTIN, HIGH);
  for(int i=0; i<=10; i++){
    digitalWrite(pinPasso,HIGH);
  }
  digitalWrite(LED_BUILTIN, LOW);
  delay(5000);
  digitalWrite(pinPasso,LOW);

  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(pinMotor, LOW);
  for(int i=0; i<=10; i++){
    digitalWrite(pinPasso,HIGH);
  }
  digitalWrite(LED_BUILTIN, LOW);
  delay(5000);
  digitalWrite(pinPasso,LOW);
}
