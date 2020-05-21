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
    string nume;
    bool reteta;
    int numarstoc;
    string producator;
public:
    Medicament();
    Medicament(int id,string nume,bool reteta,int numarstoc,string producator);
    Medicament(const Medicament& m);
    ~Medicament();
    int getid();
    string getnume();
    bool getreteta();
    int getnumarstoc();
    string getproducator();
    void setid(int id);
    void setnume(string nume);
    void setreteta(bool reteta);
    void setnumarstoc(int numarstoc);
    void setproducator(string producator);
    bool operator ==(const Medicament& m);
    bool operator !=(const Medicament& m);
    IE* clone();
    void copy(IE* e);
    bool equals(IE* pe);
//    int compareTo(IE* e);
    string toString();
    
//    friend ostream& operator <<(ostream& os, const Medicament& m);
};


#endif /* medicament_h */
