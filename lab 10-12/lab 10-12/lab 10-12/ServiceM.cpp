//
//  Service.cpp
//  lab 10-12
//
//  Created by Haris Muller Cristea on 12/05/2020.
//  Copyright © 2020 Cristea Muller Haris. All rights reserved.
//

#include <stdio.h>
#include "ServiceM.h"
#include <string>


ServiceM::ServiceM()
{
    
}

ServiceM::ServiceM(RepositoryFileTXT<Medicament> &r)
{
    this->r = r;
}



ServiceM::~ServiceM()
{
    
}

void ServiceM::setRepo(RepositoryFileTXT<Medicament> &r)
{
    this->r=r;
}


//Desc: adauga un obiect
//In: id-ul , numele,ingredientele si pretul prajiturii
//Out: -
void ServiceM::addElem(int id,string nume,bool reteta,int numarstoc,string producator)
{
    
    Medicament p(id,nume,reteta,numarstoc,producator);
    this->r.addElement(&p);
}

//Desc: sterge un obiect dupa id
//In: id
//Out: -
void ServiceM::remove(int id)
{
    this->r.deleteElement(id);
}

//Desc: modifica obiectul de pe o pozitie
//In: id-ul obiectului modificat,noul id,noul nume,noile ingrediente,noul pret
//Out: -
void ServiceM::update(Medicament* m1,Medicament* m2)
{

    this->r.updateElement(*m1,*m2);
}

//Descr:    acceseaza un element din vector
//In:        pozitia
//Out:        elementul din vector de pe pozitia curenta
Medicament ServiceM::getPoz(int id)
{
    return this->r.getElement(id);
}

//Descr:    acceseaza lungimea vectorului
//In:
//Out:        lungimea vectorului
int ServiceM::getSize()
{
    return this->r.getSize();
}

//Descr:    acceseaza elementele vectorului
//In:
//Out:      toate elementele vectorului
vector<Medicament> ServiceM::getAll()
{
    return this->r.getAll();
}


vector<Medicament> ServiceM::search(string search)
{
    vector<Medicament> newElements;
    vector<Medicament> elements=r.getAll();
    int i=0;
    for(i=0;i<r.getSize();i++)
    {
        string element;
//        char* nume=new char(strlen(elements[i].getnume()));
        string nume;
        nume=elements[i].getnume();
        int size=elements[i].getnume().size();
        element.assign(nume,size);
        if(element.find(search) != string::npos)
            newElements.push_back(elements[i]);
    }
//    for(int i=0;i<r.getSize();i++)
//    {
//        delete elements[i];
//        elements[i]=NULL:
//    }
    return newElements;
}

void ServiceM::add(Medicament* m)
{
    this->r.addElement(m);
}
