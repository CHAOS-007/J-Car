#include <Arduino.h>
// Motor Connections

// Pin Definition
//   IN1 IN2 IN3 IN4 Direction
//    0   0   0   0  Stop
//    1   0   1   0  Forward
//    0   1   0   1  Reverse
//    1   0   0   1  Left
//    0   1   1   0  Right

// Front Motor Controller
#define F_EnL 3 // D3 ENA PWM
#define F_EnR 5 // D5 ENB PWM
#define F_IL1 2 // D2 IN1 Digit
#define F_IL2 4 // D4 IN2 Digit
#define F_IR1 7 // D7 IN4 Digit
#define F_IR2 8 // D8 IN3 Digit

// Back Motor Controller
#define B_EnL 6  // D6 ENA PWM
#define B_EnR 9  // A9 ENB PWM
#define B_IL1 14 // A0 IN3 Digit
#define B_IL2 15 // A1 IN4 Digit
#define B_IR1 16 // A2 IN2 Digit
#define B_IR2 17 // A3 IN1 Digit

class MOTION
{
    public:
    MOTION(){
        speedFL = 125;
        speedFR = 125;
        speedBL = 125;
        speedBR = 125;
    }
    void setSpeed(int motor, int speed);
    void go();
    void start();
    void stop();
    int * checkSpeed();

private:
    int speedFL;
    int speedFR;
    int speedBL;
    int speedBR;
};

void MOTION::setSpeed(int motor, int speed)
{
    switch (motor)
    {
        case 0:
            speedFL = speed;
            break;
        case 1:
            speedFR = speed;
            break;
        case 2:
            speedBL = speed;
            break;
        case 3:
            speedBR = speed;
            break;

        default:
            break;
    }
}

void MOTION::go()
{
    // Turn on Front Motor L
    digitalWrite(F_IL1, HIGH);
    digitalWrite(F_IL2, LOW);
    //// set speed to 100 out 255
    analogWrite(F_EnL, speedFL);

    // Turn on Front Motor R
    digitalWrite(F_IR1, HIGH);
    digitalWrite(F_IR2, LOW);
    //// set speed to 100 out 255
    analogWrite(F_EnR, speedFR);

    // Turn on Back Motor L
    digitalWrite(B_IL1, HIGH);
    digitalWrite(B_IL2, LOW);
    //// set speed to 100 out 255
    analogWrite(B_EnL, speedBL);

    // Turn on Back Motor R
    digitalWrite(B_IR1, HIGH);
    digitalWrite(B_IR2, LOW);
    //// set speed to 100 out 255
    analogWrite(B_EnR, speedBR);
}

void MOTION::start()
{
    setSpeed(0, 125);
    setSpeed(1, 125);
    setSpeed(2, 125);
    setSpeed(3, 125);
    go();
}

void MOTION::stop()
{
    // Turn on Front Motor L
    digitalWrite(F_IL1, LOW);
    digitalWrite(F_IL2, LOW);
    //// set speed to 100 out 255
    analogWrite(F_EnL, 0);

    // Turn on Front Motor R
    digitalWrite(F_IR1, LOW);
    digitalWrite(F_IR2, LOW);
    //// set speed to 100 out 255
    analogWrite(F_EnR, 0);

    // Turn on Back Motor L
    digitalWrite(B_IL1, LOW);
    digitalWrite(B_IL2, LOW);
    //// set speed to 100 out 255
    analogWrite(B_EnL, 0);

    // Turn on Back Motor R
    digitalWrite(B_IR1, LOW);
    digitalWrite(B_IR2, LOW);
    //// set speed to 100 out 255
    analogWrite(B_EnR, 0);
}

int * MOTION::checkSpeed()
{
    static int checkPoint[] = {speedFL, speedFR, speedBL, speedBR};

    return checkPoint;
}