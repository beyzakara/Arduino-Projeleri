void setup() {
  Serial.begin(9600);
}
void loop(){
  if(Serial.read() == 'a'){
    digitalWrite(13,HIGH);
    Serial.println("LED==> ON");
  }
   else if (Serial.read() == 'b'){
    digitalWrite(13,LOW);
    Serial.println("LED ==> OFF");
   }
 }







  
