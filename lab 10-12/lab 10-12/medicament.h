//
//  medicament.h
//  lab 10-12
//
//  Created by Haris Muller Cristea on 05/05/2020.
//  Copyright © 2020 Cristea Muller Haris. All rights reserved.
//

#ifndef medicament_h
#define medicament_h
#include <iostream>
#include "IE.h"
using namespace std;

class Medicament: public IE
{
    
private:
    int id;
    char* nume;
    bool reteta;
    int numarstoc;
    char* producator;
public:
    Medicament();
    Medicament(int id,char* nume,bool reteta,int numarstoc,char* producator);
    Medicament(const Medicament& m);
    ~Medicament();
    int getid();
    char* getnume();
    bool getreteta();
    int getnumarstoc();
    char* getproducator();
    void setid(int id);
    void setnume(char* nume);
    void setreteta(char* reteta);
    void setnumarstoc(int numarstoc);
    void setproducator(char* producator);
    bool operator ==(const Medicament& m);
    bool operator !=(const Medicament& m);
    IE* clone();
    void copy(IE* e);
    bool equals(IE* pe);
    int compareTo(IE* e);
    char* toString();
    
//    friend ostream& operator <<(ostream& os, const Medicament& m);
};


#endif /* medicament_h */
