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
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  for (int i = 255; i > 80; i--) {
    analogWrite(ENA, i);
    analogWrite(ENB, i);
    delay(2);
  }
}

void arriere() {
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);  
  for (int i = 255; i > 80; i--) {
    analogWrite(ENA, i);
    analogWrite(ENB, i);
    delay(2);
  }
}

void droite() {
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  for (int i = 255; i > 80; i--) {
    analogWrite(ENA, i);
    analogWrite(ENB, i);
    delay(2);
  }
}

void gauche() {
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  for (int i = 255; i > 80; i--) {
    analogWrite(ENA, i);
    analogWrite(ENB, i);
    delay(2);
  }
}

void Stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(ENA, LOW);
  digitalWrite(ENB, LOW);
}

void debug(String str) {
  //Serial.print('B');
  //Serial.print(" drone : ");
  //Serial.print(str);
  //Serial.println(" $");
}

