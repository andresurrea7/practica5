#include "planeta.h"
#define PI 3.14159265

planeta::planeta()
{
    ViniX=0;
    ViniY=0;
    x=0;
    y=0;
    vX=0;
    vY=0;
    masa=0;
    aX=0;
    aY=0;
    angulo=0;
    aXsuma=0;
    aYsuma=0;
}

planeta::planeta(const planeta &Copy)
{
    ViniX=Copy.ViniX;
    ViniY=Copy.ViniY;
    x=Copy.x;
    y=Copy.y;
    masa=Copy.masa;
    vX=Copy.vX;
    vY=Copy.vY;
    aX=Copy.aX;
    aY=Copy.aY;
    angulo=Copy.angulo;
    aXsuma=Copy.aXsuma;
    aYsuma=Copy.aYsuma;

}
planeta::planeta(double v_iniX,double v_iniY,double _x, double _y, double _m)
{
    ViniX=v_iniX;
    ViniY=v_iniY;
    x=_x;
    y=_y;
    masa=_m;
    vX=0;
    vY=0;
    aX=0;
    aY=0;
    angulo=0;
    aXsuma=0;
    aYsuma=0;
    dist=0;
}
void planeta::CalDistancia(planeta *c)
{
    dist=sqrt(pow(c->getPosX()-x,2)+pow((c->getPosY()-y),2));
}

void planeta::CalVelocidad()
{
    vX=ViniX+(aXsuma*delta);
    vY=ViniY+(aYsuma*delta);
//    vini=(sqrt(pow(vX,2)+pow(vY,2)));
    ViniX=vX;
    ViniY=vY;
}

void planeta::CalAceleracion(planeta*c)
{
    aX=((g*c->getmasa())/pow(dist,2))*cos(angulo);
    aY=((g*c->getmasa())/pow(dist,2))*sin(angulo);
}

void planeta::ActualizarPos()
{
    CalVelocidad();
    x=x+(vX*delta)+((aXsuma*delta*delta)/2);
    y=y+(vY*delta)+((aYsuma*delta*delta)/2);
    aXsuma=0;
    aYsuma=0;
}

void planeta::ActualizarAcel(planeta *c)
{
    double xdis=(c->getPosX()-x);
    double ydis=(c->getPosY()-y);
    if(xdis==0)
        xdis=1;
    angulo=atan2(ydis,xdis);
    CalDistancia(c);
    CalAceleracion(c);
    aXsuma+=aX;
    aYsuma+=aY;

}

double planeta::getPosX()
{
    return x;
}

double planeta::getPosY()
{
    return y;
}

double planeta::getAngu()
{
    return angulo;
}

double planeta::getmasa()
{
    return masa;
}
