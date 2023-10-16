
bool ch1 = false;
bool ch2 = false;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200); // Valor maximo para arduino (Normalmente 9600)

  pinMode(0,OUTPUT);  // Para escala 10mV
  pinMode(1,OUTPUT);  // Para escala 1V
  pinMode(2,OUTPUT);  // Para escala 2.5V
  pinMode(3,OUTPUT);  // Para escala 5V
  pinMode(4,OUTPUT);  // Para escala 10V

}

void loop() {
  ADCSRA |= B00000111; // Prescalar set to 128 -> 125 kHz
  
  //  PARA EL CHANNEL 1 ******************************************************
  ADMUX |= B01000010; // Default VCC Reference Y Se lee el pin A2
  
  ADCSRA |= B11000000; // ADEN and ADSC equal to 1 (Start conversion)

  while (bit_is_set(ADCSRA, ADSC)){  // Espera finalizar conversion
    uint8_t valueCH1 = ADCL;
  }

  if (ch1) {Serial.write(valueCH1);}
  

  //  PARA EL CHANNEL 2 ******************************************************
  ADMUX |= B01000100; // Default VCC Reference Y Se lee el pin A4

  ADCSRA |= B11000000; // ADEN and ADSC equal to 1 (Start conversion)

  while (bit_is_set(ADCSRA, ADSC)){  // Espera finalizar conversion
    uint8_t valueCH2 = ADCL;
  } 
  if (ch2) {Serial.write(valueCH2);}


  //  CONTROLES PARA LABVIEW ******************************************************

  if (Serial.available() > 0) {
    char mensajeCPU = Serial.read();

    if (mensajeCPU == '@') {digitalWrite(0, HIGH);}
    else if (mensajeCPU == '#') {digitalWrite(1, HIGH);}
    else if (mensajeCPU == '$') {digitalWrite(2, HIGH);}
    else if (mensajeCPU == '%') {digitalWrite(3, HIGH);}
    else if (mensajeCPU == '&') {digitalWrite(4, HIGH);}
    else {
      digitalWrite(0, LOW);
      digitalWrite(1, LOW);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
    }

    if (mensajeCPU == '*') {ch1 = !ch1;}
    else if (mensajeCPU == '/') {ch2 = !ch2;}
  }

  delay(500);
}
