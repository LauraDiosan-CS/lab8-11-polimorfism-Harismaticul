//
//  angajati.h
//  lab 10-12
//
//  Created by Haris Muller Cristea on 05/05/2020.
//  Copyright © 2020 Cristea Muller Haris. All rights reserved.
//

#ifndef angajati_h
#define angajati_h
#include <iostream>
#include "IE.h"
using namespace std;

class Angajat: public IE
{
private:
    int id;
    string nume;
    string email;
    int grad;
public:
    Angajat();
    Angajat(int id,string nume,string email,int grad);
    Angajat(const Angajat& a);
    ~Angajat();
    int getid();
    string getnume();
    string getemail();
    int getgrad();
    void setid(int id);
    void setnume(string nume);
    void setemail(string email);
    void setgrad(int grad);
    bool operator ==(const Angajat& a);
    bool operator !=(const Angajat& a);
//    friend ostream& operator <<(ostream& os, const Angajat& a);
    IE* clone();
    void copy(IE* e);
    bool equals(IE* pe);
    int compareTo(IE* e);
    string toString();

};

#endif /* angajati_h */

//polimorfism repo si poate entitati
