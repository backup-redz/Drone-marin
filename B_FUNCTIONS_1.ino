// splitting a string and return the part nr index split by separator
String getStringPartByNr(String data, char separator, int index) {
    int stringData = 0;        //variable to count data part nr 
    String dataPart = "";      //variable to hole the return text

    for(int i = 0; i<data.length()-1; i++) {    //Walk through the text one letter at a time
        if(data[i]==separator) {
            //Count the number of times separator character appears in the text
            stringData++;
        } else if(stringData==index) {
            //get the text when separator is the rignt one
            dataPart.concat(data[i]);
        } else if(stringData>index) {
            //return text and stop if the next separator appears - to save CPU-time
            return dataPart;
            break;
        }
    }
    //return text if this is the last part
    return dataPart;
}

void avant() {
  // for ( vitesse; vitesse < 150 ; vitesse++) {
  for (int i=79 ; i < vitesse ; i++) {
    analogWrite(IN1, LOW);
    analogWrite(IN2, vitesse);
    analogWrite(IN3, LOW);
    analogWrite(IN4, vitesse);
    delay(1);
  }
}

void arriere() {
  int i;
  for ( i = 50; i < 150 ; i++) {
    vitesse = i;
    analogWrite(IN1, vitesse);
    analogWrite(IN2, LOW);
    analogWrite(IN3, vitesse);
    analogWrite(IN4, LOW);
    delay(1);
  }
}

void droite() {
  analogWrite(IN1, vitesseR);
  analogWrite(IN2, LOW);
  analogWrite(IN3, LOW);
  analogWrite(IN4, vitesseR);
}

void gauche() {
  analogWrite(IN1, LOW);
  analogWrite(IN2, vitesseR);
  analogWrite(IN3, vitesseR);
  analogWrite(IN4, LOW);
}

void Stop() {
  digitalWrite(ENA, HIGH);
  digitalWrite(ENB, HIGH);
  delay(1);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
}
