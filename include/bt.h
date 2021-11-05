#include <Arduino.h>

class BT
{
public:
    char pos1;
    char pos2;
    int speed;

    BT()
    {
        
    }
    void init(int rate=9600);

    void receive();

private:
    String btReceived;
    void btSplit();
};

void BT::init(int rate)
{
    Serial.begin(rate);
}

void BT::receive()
{
    btReceived = Serial.readString();
    btSplit();
}

void BT::btSplit()
{
    pos1 = btReceived[0];
    pos2 = btReceived[1];

    speed = 0;
    for (int i = 2; i < int(btReceived.length()); i++)
    {
        speed = 10 * speed + String(btReceived[i]).toInt();
    }

    if (speed > 255)
    {
        speed = 255;
    }
}
