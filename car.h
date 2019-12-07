#ifndef CAR_H
#define CAR_H
#include <QString>


class Car
{
public:
    Car();
    Car(QString mod, int msp, int mps);
    int GetSpeed();
    int GetPass();
    void SetSpeed(int sp);
    void SetPass(int p);
    std::string Car::GetString();

private:
   int speed;
   int maxspeed;
   QString model;
   int pass;
   int maxpass;

};

#endif // CAR_H
