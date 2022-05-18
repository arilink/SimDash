#ifndef AC_H
#define AC_H
struct handshaker
{
    int identifier;
    int version;
    int operationID;
};

struct handshakerResponse
{
    char carName[50];
    char driverName[50];
    int  identifier;
    int  version;
    char trackName[50];
    char trackConfig[50];
};

struct RTCarInfo
{
    char identifier;
    int  size;

    float speed_Kmh;
    float speed_Mph;
    float speed_Ms;

    bool isAbsEnabled;
    bool isAbsInAction;
    bool isTcInAction;
    bool isTcEnabled;
    bool isInPit;
    bool isEngineLimiterOn;

    float accG_vertical;
    float accG_horizontal;
    float accG_frontal;

    int lapTime;
    int lastLap;
    int bestLap;
    int lapCount;

    float gas;
    float brake;
    float cluth;
    float engineRPM;
    float steer;
    int   gear;
    float cgHeight;

    float wheelAngularSpeed[4];
    float slipAngle[4];
    float sliAngle_ContactPatch[4];
    float slipRatio[4];
    float tyreSlip[4];
    float ndSlip[4];
    float load[4];
    float Dy[4];
    float Mz[4];
    float tyreDirtyLevel[4];
    float camberRAD[4];
    float tyreRadius[4];
    float tyreLoadRadius[4];
    float suspensionHeight[4];
    float carPositionNormalized;
    float carSlope;
    float carCoordinates[3];
};

struct RTLap
{
    int  carIdentifierNumber;
    int  lap;
    char driverName[50];
    char carName[50];
    int  time;
};

#endif // AC_H
