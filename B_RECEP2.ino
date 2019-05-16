void recep (char lettre) { // Serial
  if (lettre != 'B') {
     debug(String(lettre)); 
  }
  
  delay(10);
  switch (lettre) {
    case'z':
    avant();
    break;
    case's':
    arriere();
    break;
    case'q':
    droite();
    break;
    case'd':
    gauche();
    break;
    case'K':
    Stop();
    break;
    case 'B':
    {
      while (Serial.available() > 0) {
        delay(10);
        if (Serial.read() == '$') {
          break;
        }
      }
    }
  }
}
