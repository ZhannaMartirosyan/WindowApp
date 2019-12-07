#include "car.h"


Car::Car()
{
    speed = 0;
    maxspeed = 100;
    pass = 0;
    maxpass = 5;
    model = "";

}
Car::Car(QString mod, int msp, int mps)
{
    model = mod;
    maxspeed = msp;
    maxpass = mps;
    speed = 0;
    pass = 0;

}

int Car::GetSpeed()
{
    return speed;
}

int Car::GetPass()
{
    return pass;
}

void Car::SetSpeed(int sp)
{
    if(sp <= maxspeed)
    {
        speed = sp;
    }
}

void Car::SetPass(int p)
{
    if(p <= maxpass)
    {
        pass = p;
    }
}
std::string Car::GetString()
{
     return (QString::number(speed) + " " +
             QString::number(maxspeed) + " " + QString::number(pass) + " " +
             QString::number(maxpass)+ model).toStdString();

}
