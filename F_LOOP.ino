void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    char charac = Serial.read();
    recep(charac);
  }
  if (autonomous == DISABLED) {
    gps.flush();
  } else {
    updateGPS();
    float distance = eucliDist(longitude, latitude, targetX, targetY);
    Serial.print("B dist eucli : ");
    Serial.print(distance);
    Serial.print('$');
    
    if (distance < 10) {
      Stop();
      autonomous = DISABLED;
      Serial.print('*'); // lancer la pompe
    } else {
      int tRoute = (int) route;
      int angle = (450 - tRoute) % 360;
      
      float point1_X = longitude + ( cos(degToRad(angle)) * 50 );
      float point1_Y = latitude + ( sin(degToRad(angle)) * 50 );
      float v1_x = point1_X - longitude;
      float v1_y = point1_Y - latitude;

      float v2_x = targetX - longitude;
      float v2_y = targetY - latitude;

      float cosAngle = ( (v1_x * v2_x) + (v1_y * v2_y) ) / (sqrt( (v1_x * v1_x) + (v1_y * v1_y) ) * sqrt( (v2_x * v2_x) + (v2_y * v2_y) ));
      float angleToGoal = my_acos(cosAngle);

      //savoir de quel cote de la droite AB est le point M
      float aX = longitude;
      float aY = latitude;
      float bX = longitude + v1_x;
      float bY = latitude + v1_y;
      float mX = targetX;
      float mY = targetY;

      int8_t orientation = sign((bX - aX) * (mY - aY) - (bY - aY) * (mX - aX)) * -1;
      angleToGoal *= orientation;

      Serial.print("B angle : ");
      Serial.print(angleToGoal);
      Serial.print('$');

      if ( angleToGoal < -5) {
        droite();
      } else if (angleToGoal > 5) {
        gauche();
      } else {
        avant();
      }
    }
  }

}
