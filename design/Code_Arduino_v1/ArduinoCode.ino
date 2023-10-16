
bool ch1 = true;
bool ch2 = true;
uint8_t valueCH1;
uint8_t valueCH2;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200); // Valor maximo para arduino (Normalmente 9600)

  pinMode(2,OUTPUT);  // Para escala 10mV @
  pinMode(3,OUTPUT);  // Para escala 1V #
  pinMode(4,OUTPUT);  // Para escala 2.5V $
  pinMode(5,OUTPUT);  // Para escala 5V %
  pinMode(6,OUTPUT);  // Para escala 10V &

  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6, LOW);
}

void loop() {
  ADCSRA |= B00000111; // Prescalar set to 128 -> 125 kHz
  
  //  PARA EL CHANNEL 1 ******************************************************
  ADMUX |= B01000010; // Default VCC Reference Y Se lee el pin A2
  
  ADCSRA |= B11000000; // ADEN and ADSC equal to 1 (Start conversion)

  while (bit_is_set(ADCSRA, ADSC)){  // Espera finalizar conversion
    valueCH1 = ADCL;
  }

  if (ch1) {Serial.print(valueCH1);}
  

  //  PARA EL CHANNEL 2 ******************************************************
  ADMUX |= B01000100; // Default VCC Reference Y Se lee el pin A4

  ADCSRA |= B11000000; // ADEN and ADSC equal to 1 (Start conversion)

  while (bit_is_set(ADCSRA, ADSC)){  // Espera finalizar conversion
    valueCH2 = ADCL;
  } 
  if (ch2) {Serial.println(valueCH2);}


  //  CONTROLES PARA LABVIEW ******************************************************

  if (Serial.available() > 0) {
    char mensajeCPU = Serial.read();

    if (mensajeCPU == '@') {
      digitalWrite(2, HIGH);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      }
    else if (mensajeCPU == '#') {
      digitalWrite(3, HIGH);
      digitalWrite(2, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
    }
    else if (mensajeCPU == '$') {
      digitalWrite(4, HIGH);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
      }
    else if (mensajeCPU == '%') {
      digitalWrite(5, HIGH);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(6, LOW);
      }
    else if (mensajeCPU == '&') {
      digitalWrite(6, HIGH);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      }
    else {
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
      digitalWrite(6, LOW);
    }

    if (mensajeCPU == '*') {ch1 = true;}
    else if (mensajeCPU == '+') {ch1 = false;}
    else if (mensajeCPU == '/') {ch2 = true;}
    else if (mensajeCPU == '-') {ch2 = false;}
  }

  delay(50);
}