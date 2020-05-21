//
//  Service.h
//  lab 10-12
//
//  Created by Haris Muller Cristea on 12/05/2020.
//  Copyright © 2020 Cristea Muller Haris. All rights reserved.
//

#ifndef Service_h
#define Service_h
#pragma once
#include "Repo.h"
#include "RepoFile.h"
#include "medicament.h"


class ServiceM
{
private:
    RepositoryFileTXT<Medicament> r;
public:
    ServiceM();
    ServiceM(RepositoryFileTXT<Medicament>& r);
    ~ServiceM();
    void setRepo(RepositoryFileTXT<Medicament>& r);
    void addElem(int id,string nume,bool reteta,int numarstoc,string producator);
    void update(Medicament* m1,Medicament* m2);
    void remove(int id);
    void add(Medicament* m);
    Medicament getPoz(int id);
    vector<Medicament> getAll();
    int getSize();
    vector<Medicament> search(string search);
};

#endif /* Service_h */
