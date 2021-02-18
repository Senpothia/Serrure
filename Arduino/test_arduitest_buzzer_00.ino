/*
  
Programme pour test fiabilité des cartes D866/D867
Permet de commander carte relais
SORTIE ACTIVE: DIGITAL 2
 
*/
/**
const int R1=22;  // Cablâge: Sortie Digital 22
  const int R2=23;  // Cablâge: Sortie Digital 23
   const int R3=29;  // Cablâge: Sortie Digital 29
    const int R4=39;  // Cablâge: Sortie Digital 39
     const int R5=49;  // Cablâge: Sortie Digital 49
      const int R6=51;  // Cablâge: Sortie Digital 51
       const int R7=52;  // Cablâge: Sortie Digital 52
        const int R8=53;  // Cablâge: Sortie Digital 53

*/

/**
const int R1=22;  // Cablâge: Sortie Digital 22
const int R2=23;  // Cablâge: Sortie Digital 23
const int R3=29;  // Cablâge: Sortie Digital 29
const int I1 = 9;
const int I2 = 8;
const int I3 = 7;
const int I4 = 6;
const int I5 = 5;
const int I6 = 4;
const int I7 = 3;
const int I8 = 2;

int e1;
int e2;
int e3;
int e4;
int e5;
int e6;
int e7;
int e8;
*/

const int an0 = 7;
int volt0 =0;
const int R1=22;  // Cablâge: Sortie Digital 22
const int R2=23;  // Cablâge: Sortie Digital 23
const int R3=29;  // Cablâge: Sortie Digital 29
const int R4=39;  // Cablâge: Sortie Digital 39
const int buzzer = 10;
char mot[5]; 
bool ACT_BUZZ = false;
const int I8 = 2;
int e8;
int front = 1;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output

 /**
  pinMode(R1, OUTPUT);
   pinMode(R2, OUTPUT);
    pinMode(R3, OUTPUT);
     pinMode(R4, OUTPUT);
      pinMode(R5, OUTPUT);
       pinMode(R6, OUTPUT);
        pinMode(R7, OUTPUT);
         pinMode(R8, OUTPUT);
         */
 /**
pinMode(I1, INPUT);
pinMode(I2, INPUT);
pinMode(I3, INPUT);
pinMode(I4, INPUT);
pinMode(I5, INPUT);
pinMode(I6, INPUT);
pinMode(I7, INPUT);
pinMode(I8, INPUT);

*/
 pinMode(R1, OUTPUT);
   pinMode(R2, OUTPUT);
    pinMode(R3, OUTPUT);
Serial.begin(9600);
Serial.println(9);
 pinMode(buzzer,OUTPUT); //on prépare le pin 3 en mode sortie
}


// the loop function runs over and over again forever
void loop() {
/**
  digitalWrite(R1, HIGH);   // Relais inactif 10s
   digitalWrite(R2, HIGH);   // Relais inactif 10s
    digitalWrite(R3, HIGH);   // Relais inactif 10s
     digitalWrite(R4, HIGH);   // Relais inactif 10s
      digitalWrite(R5, HIGH);   // Relais inactif 10s
       digitalWrite(R6, HIGH);   // Relais inactif 10s
        digitalWrite(R7, HIGH);   // Relais inactif 10s
         digitalWrite(R8, HIGH);   // Relais inactif 10s
  delay(5000);                       // 
  digitalWrite(R1, LOW);    // Relais actif 50s
   digitalWrite(R2, LOW);    // Relais actif 50s
    digitalWrite(R3, LOW);    // Relais actif 50s
     digitalWrite(R4, LOW);    // Relais actif 50s
      digitalWrite(R5, LOW);    // Relais actif 50s
       digitalWrite(R6, LOW);    // Relais actif 50s
        digitalWrite(R7, LOW);    // Relais actif 50s
         digitalWrite(R8, LOW);    // Relais actif 50s
  delay(5000);         

 */
 /**
 e1 = digitalRead(I1); 
 e2 = digitalRead(I2); 
 e3 = digitalRead(I3); 
 e4 = digitalRead(I4); 
 e5 = digitalRead(I5); 
 e6 = digitalRead(I6); 
 e7 = digitalRead(I7); 
 e8 = digitalRead(I8); 

 if (e8 == LOW) {
  
  digitalWrite(R1, HIGH);   // Relais inactif 10s
   digitalWrite(R2, HIGH);   // Relais inactif 10s
    digitalWrite(R3, HIGH);   // Relais inactif 10s
    delay(5000);
   digitalWrite(R1, LOW);    // Relais actif 50s
     digitalWrite(R2, LOW);    // Relais actif 50s
       digitalWrite(R3, LOW);    // Relais actif 50s
     delay(1000);
     */
volt0 = analogRead(an0);


if (volt0>300 && volt0<400){
   digitalWrite(R1, HIGH);   
  } else {
     digitalWrite(R1, LOW);  }

     if (volt0>500 && volt0<650){
   digitalWrite(R2, HIGH);   
  } else {
     digitalWrite(R2, LOW);  }
     
    if (volt0>800 && volt0<950){
   digitalWrite(R3, HIGH);   
  } else {
     digitalWrite(R3, LOW);  }
int i = 0;
while (Serial.available() > 0 && i <= 4)
      {
          mot[i] = Serial.read(); 
          delay(10); 
          i++; 
       }
        mot[i] = '\0'; 
   
if (strcmp(mot,"1") == 0 ){
           digitalWrite(R4, HIGH);  
                      }         
  
if (strcmp(mot,"0") == 0 ){
           digitalWrite(R4, LOW);  
                      }  
          
if (strcmp(mot,"b") == 0 )   {

  ACT_BUZZ = true;
  }

  if (strcmp(mot,"c") == 0 )   {

  ACT_BUZZ = false;
  }

if (ACT_BUZZ){
   digitalWrite(buzzer,0); // état bas
    delayMicroseconds(125); //
    digitalWrite(buzzer,1); // état haut
    delayMicroseconds(125); // 

  }
e8 = digitalRead(I8); 
if (e8 == 0 & front == 1){
  front = 0;
  if (front == 0){ 
    ACT_BUZZ = !ACT_BUZZ;}

}
e8 = digitalRead(I8); 
if (e8 == 1){
  front =1;}

}// fin loop



