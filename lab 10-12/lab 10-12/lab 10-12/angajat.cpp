//
//  angajat.cpp
//  lab 10-12
//
//  Created by Haris Muller Cristea on 05/05/2020.
//  Copyright © 2020 Cristea Muller Haris. All rights reserved.
//

#include <stdio.h>
#include "angajat.h"
#include <string>
#include <iostream>
using namespace std;

Angajat::Angajat()
{
    this->id=0;
    this->nume="";
    this->email="";
    this->grad=0;
}

Angajat::Angajat(int id,string nume,string email,int grad)
{
    this->id=id;
    this->nume=nume;
    this->email=email;
    this->grad=grad;
}

Angajat::Angajat(const Angajat& a)
{
    this->id=a.id;
    this->nume=a.nume;
    this->email=a.email;
    this->grad=a.grad;
}

Angajat::~Angajat()
{
    this->id=0;

    this->grad=0;
}

int Angajat::getid()
{
    return this->id;
}

string Angajat::getnume()
{
    return this->nume;
}

string Angajat::getemail()
{
    return this->email;
}

int Angajat::getgrad()
{
    return this->grad;
}

void Angajat::setgrad(int grad)
{
    this->grad=grad;
}

void Angajat::setnume(string nume)
{
    this->nume=nume;
}

void Angajat::setemail(string email)
{
    this->email=email;
}

void Angajat::setid(int id)
{
    this->id=id;
}

bool Angajat::operator==(const Angajat& a)
{
    return this->id==a.id and this->nume==a.nume and this->grad==a.grad and this->email==email;
}

bool Angajat::operator!=(const Angajat& a)
{
    return this->id!=a.id and this->nume!=a.nume and this->grad!=a.grad and this->email!=email;
}

IE* Angajat::clone()
{
    Angajat* m=new Angajat;
    m->id=this->id;
//    m->nume=new char[strlen(this->nume)+1];
    m->email=this->email;
    m->grad=this->grad;
//    m->email=new char[strlen(this->email)+1];
    m->email=this->email;
    return m;
}

void Angajat::copy(IE* e)
{
    Angajat* m=(Angajat*) e;
    this->id=m->id;
    this->grad=m->grad;
//    this->nume=new char[strlen(m->nume)+1];
    this->nume=m->nume;
//    this->email=new char[strlen(m->email)+1];
    this->email=m->email;
}

bool Angajat::equals(IE *pe)
{
    return this->nume.compare(((Angajat*)pe)->nume)==0 && this->id == ((Angajat*)pe)->id && this->email.compare(((Angajat*)pe)->email)==0 & this->grad==((Angajat*)pe)->grad;
}

string Angajat::toString()
{
//    char* s=new char[strlen(this->nume)+strlen("Acesta este un angajat numit  de gradul,cu e-mailul:")+30];
    string s;
    s="Acesta este un angajat numit";
    s=s+this->nume;
    s=s+" ,de gradul ";
    char* aux = new char[6];
    sprintf(aux, "%d", this->grad);
    s=s+aux;
    s=s+" ,cu e-mailul:";
    s=s+this->email;
    s=s+".";
    delete[] aux;
    return s;
}




//ostream operator<<(ostream& os,const Angajat& a)
//{
//    os<<a.id<<' '<<a.nume<<' '<<a.email<<' '<<a.grad<<endl;
//    return os;
//}
