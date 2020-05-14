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
    this->nume=NULL;
    this->email=NULL;
    this->grad=0;
}

Angajat::Angajat(int id,char* nume,char* email,int grad)
{
    this->id=id;
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->email=new char[strlen(email)+1];
    strcpy(this->email,email);
    this->grad=grad;
}

Angajat::Angajat(const Angajat& a)
{
    this->id=a.id;
    this->nume=new char[strlen(a.nume)+1];
    strcpy(this->nume,a.nume);
    this->email=new char[strlen(a.email)+1];
    strcpy(this->email,a.email);
    this->grad=a.grad;
}

Angajat::~Angajat()
{
    this->id=0;
    if(this->nume!=NULL)
    {
        delete[] this->nume;
        this->nume=NULL;
    }
    if(this->email!=NULL)
    {
        delete[] this->email;
        this->email=NULL;
    }
    this->grad=0;
}

int Angajat::getid()
{
    return this->id;
}

char* Angajat::getnume()
{
    return this->nume;
}

char* Angajat::getemail()
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

void Angajat::setnume(char* nume)
{
    this->nume=nume;
}

void Angajat::setemail(char* email)
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
    m->nume=new char[strlen(this->nume)+1];
    strcpy(m->nume,this->nume);
    m->grad=this->grad;
    m->email=new char[strlen(this->email)+1];
    strcpy(m->email,this->email);
    return m;
}

void Angajat::copy(IE* e)
{
    Angajat* m=(Angajat*) e;
    this->id=m->id;
    this->grad=m->grad;
    this->nume=new char[strlen(m->nume)+1];
    strcpy(this->nume,m->nume);
    this->email=new char[strlen(m->email)+1];
    strcpy(this->email, m->email);
}

bool Angajat::equals(IE *pe)
{
    return strcmp(this->nume , ((Angajat*)pe)->nume) && this->id == ((Angajat*)pe)->id && ((strcmp(this->email, ((Angajat*)pe)->email) && this->grad == ((Angajat*)pe)->grad));
}

char* Angajat::toString()
{
    char* s=new char[strlen(this->nume)+strlen("Acesta este un angajat numit  de gradul,cu e-mailul:")+30];
    strcpy(s,"Acesta este un angajat numit");
    strcat(s,this->nume);
    strcat(s," ,de gradul ");
    char* aux = new char[6];
    sprintf(aux, "%d", this->grad);
    strcat(s, aux);
    strcat(s," ,cu e-mailul:");
    strcat(s,this->email);
    strcat(s,".");
    delete[] aux;
    return s;
}




//ostream operator<<(ostream& os,const Angajat& a)
//{
//    os<<a.id<<' '<<a.nume<<' '<<a.email<<' '<<a.grad<<endl;
//    return os;
//}
