//
//  medicament.cpp
//  lab 10-12
//
//  Created by Haris Muller Cristea on 05/05/2020.
//  Copyright © 2020 Cristea Muller Haris. All rights reserved.
//

#include <stdio.h>
#include"medicament.h"
#include <string>
#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

Medicament::Medicament()
{
    this->id=0;
    this->nume=NULL;
    this->reteta=false;
    this->numarstoc=0;
    this->producator=NULL;
}

Medicament::Medicament(int id,char* nume,bool reteta,int numarstoc,char* producator)
{
    this->id=id;
    this->nume=new char[strlen(nume)+1];
    strcpy(this->nume,nume);
    this->reteta=false;
    this->numarstoc=numarstoc;
    this->producator=new char[strlen(producator)+1];
    strcpy(this->producator,producator);
}

Medicament::Medicament(const Medicament& m)
{
    this->id=m.id;
    this->nume=new char[strlen(m.nume)+1];
    strcpy(this->nume,m.nume);
    this->reteta=m.reteta;
    this->numarstoc=m.numarstoc;
    this->producator=new char[strlen(m.producator)+1];
    strcpy(this->producator,m.producator);
}

Medicament::~Medicament()
{
    this->id=0;
    if(this->nume!=NULL)
    {
        delete[] this->nume;
        this->nume=NULL;
    }
    this->reteta=false;
    this->numarstoc=false;
    if(this->producator!=NULL)
    {
        delete[] this->producator;
        this->producator=NULL;
    }
}

int Medicament::getid()
{
    return this->id;
}

char* Medicament::getnume()
{
    return this->nume;
}

bool Medicament::getreteta()
{
    return this->reteta;
}

int Medicament::getnumarstoc()
{
    return this->numarstoc;
}

char* Medicament::getproducator()
{
    return this->producator;
}

void Medicament::setid(int id)
{
    this->id=id;
}

void Medicament::setnume(char* nume)
{
    this->nume=nume;
}

void Medicament::setreteta(char* reteta)
{
    this->reteta=reteta;
}

void Medicament::setnumarstoc(int numarstoc)
{
    this->numarstoc=numarstoc;
}

void Medicament::setproducator(char* producator)
{
    this->producator=producator;
}

bool Medicament::operator==(const Medicament& m)
{
  return this->id==m.id and this->reteta==m.reteta and this->producator==m.producator and this->nume==m.nume  and this->numarstoc==m.numarstoc;
}

 bool Medicament::operator!=(const Medicament& m)
 {
    return this->id!=m.id and this->reteta!=m.reteta and this->producator!=m.producator and this->nume!=m.nume  and this->numarstoc!=m.numarstoc;
 }

IE* Medicament::clone()
{
    Medicament* m=new Medicament;
    m->id=this->id;
    m->nume=new char[strlen(this->nume)+1];
    strcpy(m->nume,this->nume);
    m->reteta=this->reteta;
    m->numarstoc=this->numarstoc;
    m->producator=new char[strlen(this->producator)+1];
    strcpy(m->producator,this->producator);
    return m;
}

void Medicament::copy(IE* e)
{
    Medicament* m=(Medicament*) e;
    this->id=m->id;
    this->reteta=m->reteta;
    this->numarstoc=m->numarstoc;
    this->nume=new char[strlen(m->nume)+1];
    strcpy(this->nume,m->nume);
    this->producator=new char[strlen(m->producator)+1];
    strcpy(this->producator, m->producator);
}

bool Medicament::equals(IE *pe)
{
    return strcmp(this->nume , ((Medicament*)pe)->nume) && this->id == ((Medicament*)pe)->id && ((strcmp(this->producator, ((Medicament*)pe)->producator) && this->numarstoc == ((Medicament*)pe)->numarstoc)) && this->reteta == ((Medicament*)pe)->reteta;
}

char* Medicament::toString()
{
    char* s=new char[strlen(this->nume)+strlen("Acesta este un medicament numit  fara reteta,producator ,numar stoc")+30];
    strcpy(s,"Acesta este un medicament numit");
    strcat(s,this->nume);
    if(this->reteta==true)
        strcat(s," prescris cu reteta,");
    else strcat(s," prescris fara reteta,");
    strcat(s,"de la producatorul ");
    strcat(s,this->producator);
    strcat(s,", cu un numar stoc de ");
    char* aux = new char[6];
    sprintf(aux, "%d", this->numarstoc);
    strcat(s, aux);
    strcat(s,".");
    delete[] aux;
    return s;
}
