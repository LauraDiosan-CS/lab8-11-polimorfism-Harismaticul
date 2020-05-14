//
//  ServiceA.cpp
//  lab 10-12
//
//  Created by Haris Muller Cristea on 13/05/2020.
//  Copyright © 2020 Cristea Muller Haris. All rights reserved.
//

#include <stdio.h>
#include "ServiceA.h"
#include <cstring>
#include <string.h>
#include <string>


ServiceA::ServiceA()
{
    
}

ServiceA::ServiceA(RepositoryFileTXT<Angajat> &r)
{
    this->r = r;
}

ServiceA::~ServiceA()
{
    
}

void ServiceA::setRepo(RepositoryFileTXT<Angajat> &r)
{
    this->r=r;
}


//Desc: adauga un obiect
//In: id-ul , numele,ingredientele si pretul prajiturii
//Out: -
void ServiceA::addElem(int id,char* nume,char* email,int grad)
{
    
    Angajat p(id,nume,email,grad);
    this->r.addElement(&p);
}

//Desc: sterge un obiect dupa id
//In: id
//Out: -
void ServiceA::deleteElem(int id)
{
    this->r.deleteElement(id);
}

//Desc: modifica obiectul de pe o pozitie
//In: id-ul obiectului modificat,noul id,noul nume,noile ingrediente,noul pret
//Out: -
void ServiceA::updateElem(int id1,int id2,char* nume,char* email,int grad)
{
    Angajat p(id2,nume,email,grad);
    this->r.updateElement(this->r.getElement(id1),p);
}

//Descr:    acceseaza un element din vector
//In:        pozitia
//Out:        elementul din vector de pe pozitia curenta
Angajat ServiceA::getPoz(int id)
{
    return this->r.getElement(id);
}

//Descr:    acceseaza lungimea vectorului
//In:
//Out:        lungimea vectorului
int ServiceA::getSize()
{
    return this->r.getSize();
}

//Descr:    acceseaza elementele vectorului
//In:
//Out:      toate elementele vectorului
vector<Angajat> ServiceA::getAll()
{
    return this->r.getAll();
}

bool ServiceA::checkUser(string User,string Pass)
{
    vector<Angajat> elements=r.getAll();
    int i;
    for(i=0;i<r.getSize();i++)
    {
        string email;
        string nume;
        string id;
        string password;
        
        password=elements[i].getnume()+elements[i].getid();
        if(elements[i].getemail()==User and password==Pass)
            return true;
    }
    return false;
}

