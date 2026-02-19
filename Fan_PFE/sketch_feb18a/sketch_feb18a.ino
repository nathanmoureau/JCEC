
const int fan_control_pin = 3;
int CVIN = A7;
int count = 0; 
int pitch = 0;
unsigned long start_time;

void setup() {
  // put your setup code   here, to run once:
  pinMode(fan_control_pin, OUTPUT);
  analogWrite(fan_control_pin, 0);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(2), counter, RISING);
}

void loop() {
  pitch = analogRead(CVIN);
  Serial.println(pitch);
  analogWrite(fan_control_pin, pitch / 4);
}

void counter() {
  count++;
}