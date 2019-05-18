#include <SoftwareSerial.h>
SoftwareSerial gps (5, 6);

float latitude = 0.0;
float longitude = 0.0;
float route = 0.0;

byte IN1 = 13;
byte IN2 = 12;
byte IN3 = 11;
byte IN4 = 8;
byte ENA = 10;
byte ENB = 9;

double positionsGPS[10];

enum GPS_CODES {
  GPS_SUCCES,
  GPS_FAILURE
};

// functions prototypes
int isGPRMC(String trameGPS);
float parseLat(String latrame);
float parseLong(String latrame);
float parseRoute(String latrame);
int getGPSPos (float *lati, float *longi);
void updateGPS();

String getStringPartByNr(String data, char separator, int index);

void avant();
void arriere();
void droite();
void gauche();
void Stop();
void recep (char lettre);
