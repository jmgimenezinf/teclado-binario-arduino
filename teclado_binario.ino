
int tecla_cero;
int tecla_uno;
int j=0;
unsigned char num = 0;

void setup() {
  pinMode(4,INPUT); // PULL DOWN 1
  pinMode(2,INPUT);//  PULL UP 0
  Serial.begin(9600);

}


void loop() {
  tecla_uno = digitalRead(4);
  tecla_cero = digitalRead(2);
  delay(250);

  if ((tecla_cero == LOW) or (tecla_uno == HIGH)) {
      Serial.print("bit ");
      Serial.print(j+1, DEC);
      
      if(tecla_cero == LOW){
        Serial.print(": 0");
      }
      
      if (tecla_uno == HIGH){
        num = num | (1 << (7-j));
        Serial.print(": 1");
      }

      Serial.println("");
      j++;
      
      if (j==8) {
        j=0;
        Serial.print("El caracter ingresado es: ");
        Serial.println(num);
        Serial.print("El binario ingresado es: ");
        if(num & (1 << 7) == 0) {
          Serial.print("0");
        }
        Serial.println(num, BIN);
        Serial.print("El numero ingresado es: ");
        Serial.println(num, DEC);
        num = 0;
      }
      delay(250);
   }
}

