#include "sistema.h"
#include<sstream>
#include <iostream>
using namespace std;

sistema::sistema()
{
    /*planeta P1(2,0,0,-7000,70);
    planeta P2(0,0,0,0,70000);
    planeta P3(-1.6,1.2,4000,5000,25);   //eje uno
    misistema.push_back(P1);
    misistema.push_back(P2);
    misistema.push_back(P3);*/
    planeta P1(0,0,0,0,50000);
    planeta P2(0,-2,-5000,0,70);
    planeta P3(0,2,5000,0,70);
    planeta P4(2,0,0,-5000,70);     //ejemplo 2;
    planeta P5(-2,0,0,5000,70);
    misistema.push_back(P1);
    misistema.push_back(P2);
    misistema.push_back(P3);
    misistema.push_back(P4);
    misistema.push_back(P5);
}

string sistema::sincronizar()
{
    stringstream s;
    vector<planeta>sistemp;
//    planeta c1=misistema[0]; //1
//    planeta c2=misistema[1];//1
//    planeta c3=misistema[2];//1
    planeta c1=misistema[0];
    planeta c2=misistema[1];
    planeta c3=misistema[2];
    planeta c4=misistema[3];//2
    planeta c5=misistema[4];//2
    sistemp.push_back(c1);
    sistemp.push_back(c2);
    sistemp.push_back(c3);
    sistemp.push_back(c4);//2
    sistemp.push_back(c5);//2
    for(unsigned int i=0;i<misistema.size();i++){
        s<<sistemp[i].getPosX()<<"\t"<<sistemp[i].getPosY()<<"\t";
        for(unsigned int j=0;j<misistema.size();j++){
            if(j!=i){
                sistemp[i].ActualizarAcel(&misistema[j]);
            }
        }
        sistemp[i].ActualizarPos();
    }
    for(unsigned int i=0;i<misistema.size();i++){
        misistema[i]=sistemp[i];
    }
    return s.str();
}
