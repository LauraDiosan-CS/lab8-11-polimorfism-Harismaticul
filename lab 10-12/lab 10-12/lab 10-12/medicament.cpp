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
    this->nume="";
    this->reteta=false;
    this->numarstoc=0;
    this->producator="";
}

Medicament::Medicament(int id,string nume,bool reteta,int numarstoc,string producator)
{
    this->id=id;
    this->nume=nume;
    this->reteta=false;
    this->numarstoc=numarstoc;
    this->producator=producator;
}

Medicament::Medicament(const Medicament& m)
{
    this->id=m.id;
    this->nume=m.nume;
    this->reteta=m.reteta;
    this->numarstoc=m.numarstoc;
    this->producator=m.producator;
}

Medicament::~Medicament()
{
    this->id=0;
    this->reteta=false;
    this->numarstoc=false;
}

int Medicament::getid()
{
    return this->id;
}

string Medicament::getnume()
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

string Medicament::getproducator()
{
    return this->producator;
}

void Medicament::setid(int id)
{
    this->id=id;
}

void Medicament::setnume(string nume)
{
    this->nume=nume;
}

void Medicament::setreteta(bool reteta)
{
    this->reteta=reteta;
}

void Medicament::setnumarstoc(int numarstoc)
{
    this->numarstoc=numarstoc;
}

void Medicament::setproducator(string producator)
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
    m->nume=this->nume;
    m->reteta=this->reteta;
    m->numarstoc=this->numarstoc;
    m->producator=this->producator;
    return m;
}

void Medicament::copy(IE* e)
{
    Medicament* m=(Medicament*) e;
    this->id=m->id;
    this->reteta=m->reteta;
    this->numarstoc=m->numarstoc;
    this->nume=m->nume;
    this->producator=m->producator;
}

bool Medicament::equals(IE *pe)
{
    return this->nume.compare(((Medicament*)pe)->nume)==0 && this->id == ((Medicament*)pe)->id && this->reteta==((Medicament*)pe)->reteta
    && this->producator.compare(((Medicament*)pe)->producator)==0 && this->numarstoc==((Medicament*)pe)->numarstoc;
    
}

string Medicament::toString()
{
    string s;
    s="Acesta este un medicament numit";
    s=s+this->nume;
    if(this->reteta==true)
        s=s+"prescris cu reteta";
    else s=s+"prescris fara reteta";
    s=s+"de la producatorul ";
    s=s+this->producator;
    s=s+", cu un numar stoc de ";
    char* aux = new char[6];
    sprintf(aux, "%d", this->numarstoc);
    s=s+aux;
    s=s+".";
    delete[] aux;
    return s;
}
