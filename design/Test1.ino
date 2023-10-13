int val;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0,INPUT);
  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(A0);
  //Serial.write(val);
  Serial.println(val);
  delay(50);
}
