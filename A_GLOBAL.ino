#include <SoftwareSerial.h>
SoftwareSerial gps (12, 13);

float latitude = 0.0;
float longitude = 0.0;
float route = 0.0;

float targetX = 0.0;
float targetY = 0.0;

double positionsGPS[10];

enum AUTONOMOUS_MODE {
  ENABLED,
  DISABLED
};

int autonomous = DISABLED;

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

#define BRAKE 0
#define CW    1
#define CCW   2
#define CS_THRESHOLD 15   // Definition of safety current (Check: "1.3 Monster Shield Example").

//MOTOR 1
#define MOTOR_A1_PIN 7
#define MOTOR_B1_PIN 8

//MOTOR 2
#define MOTOR_A2_PIN 4
#define MOTOR_B2_PIN 9

#define PWM_MOTOR_1 5
#define PWM_MOTOR_2 6

#define CURRENT_SEN_1 A2
#define CURRENT_SEN_2 A3

#define EN_PIN_1 A0
#define EN_PIN_2 A1

#define MOTOR_1 0
#define MOTOR_2 1

short usSpeed = 150;  //default motor speed
unsigned short usMotor_Status = BRAKE;
void motorGo(uint8_t motor, uint8_t direct, uint8_t pwm);

void debug(String str);

float eucliDist(float x1, float y1, float x2, float y2);
float degToRad (float degr);
float radToDeg(float rad);
int8_t sign(int val);
float my_acos(float x);
