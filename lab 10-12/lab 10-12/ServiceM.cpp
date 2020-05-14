//
//  Service.cpp
//  lab 10-12
//
//  Created by Haris Muller Cristea on 12/05/2020.
//  Copyright © 2020 Cristea Muller Haris. All rights reserved.
//

#include <stdio.h>
#include "ServiceM.h"


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
void ServiceM::addElem(int id,char* nume,bool reteta,int numarstoc,char* producator)
{
    
    Medicament p(id,nume,reteta,numarstoc,producator);
    this->r.addElement(&p);
}

//Desc: sterge un obiect dupa id
//In: id
//Out: -
void ServiceM::deleteElem(int id)
{
    this->r.deleteElement(id);
}

//Desc: modifica obiectul de pe o pozitie
//In: id-ul obiectului modificat,noul id,noul nume,noile ingrediente,noul pret
//Out: -
void ServiceM::updateElem(int id1,int id2,char* nume,bool reteta,int numarstoc,char* producator)
{
    Medicament p(id2,nume,reteta,numarstoc,producator);
    this->r.updateElement(this->r.getElement(id1),p);
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


vector<Medicament> ServiceM::Search(string search)
{
    vector<Medicament> newElements;
    vector<Medicament> elements=r.getAll();
    int i=0;
    for(i=0;i<r.getSize();i++)
    {
        string element;
        char* nume=new char(strlen(elements[i].getnume()));
        strcpy(nume,elements[i].getnume());
        int size=strlen(elements[i].getnume());
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
