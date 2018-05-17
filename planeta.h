#ifndef PLANETA_H
#define PLANETA_H

#include <math.h>
#define g 1
#define delta 1

class planeta
{
private:
    double ViniX,ViniY,vX,vY;
    double x;
    double y;
    double angulo;
    double aX,aY;
    double masa;
    double dist;
    double aYsuma;
    double aXsuma;
public:
    planeta();
    planeta(const planeta& Copy);
    planeta(double v_iniX,double v_iniY,double _x, double _y, double _m);
    void CalVelocidad();
    void CalAceleracion(planeta* c);
    void CalDistancia(planeta* c);
    void ActualizarPos();
    void ActualizarAcel(planeta* c);
    double getPosX();
    double getPosY();
    double getAngu();
    double getmasa();
};

#endif // PLANETA_H
