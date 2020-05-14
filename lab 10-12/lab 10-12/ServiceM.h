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
    void addElem(int id,char* nume,bool reteta,int numarstoc,char* producator);
    void updateElem(int id1,int id2,char* nume,bool reteta,int numarstoc,char* producator);
    void deleteElem(int id);
    Medicament getPoz(int id);
    vector<Medicament> getAll();
    int getSize();
    vector<Medicament> Search(string search);
};

#endif /* Service_h */
