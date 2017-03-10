
int tecla_cero;
int tecla_uno;
int j=0;
int binario_leido[8];

void setup() {
  // put your setup code here, to run once:
  pinMode(4,INPUT); // PULL DOWN 1
  pinMode(2,INPUT);//  PULL UP 0
  Serial.begin(9600);

}


void loop() {
  // put your main code here, to run repeatedly:

  tecla_uno=digitalRead(4);
  tecla_cero=digitalRead(2);
  delay(250);


  if ((tecla_cero == LOW)or (tecla_uno==HIGH)) {
        Serial.println(j);
      if(tecla_cero==LOW){
         binario_leido[j]=0;
        Serial.println("pulsaste la tecla cero");   
      }
      if (tecla_uno==HIGH){
        binario_leido[j]=1;
        Serial.println("pulsaste la tecla uno");
      }
      if(j==7){
        j=0;
         float num = 0;
            int tempNUM = 0;
            int i;
            for(i = 0; i < 7; i++){
                num = (pow(2, i) * binario_leido[i]) + num;
                Serial.print(num);
            }
            for(i = 1; i < 7; i++){
                tempNUM = num - (pow(10,i) * int(num/pow(10,i))) - tempNUM;
                Serial.print(byte(tempNUM/pow(10,i-1)), 'DEC');
            }
      }else{
       j=j+1;}
      Serial.println(j);
      delay(250);
   }
}
