//
//  ServiceA.h
//  lab 10-12
//
//  Created by Haris Muller Cristea on 13/05/2020.
//  Copyright © 2020 Cristea Muller Haris. All rights reserved.
//

#ifndef ServiceA_h
#define ServiceA_h
#pragma once
#include "Repo.h"
#include "RepoFile.h"
#include "angajat.h"


class ServiceA
{
private:
    RepositoryFileTXT<Angajat> r;
public:
    ServiceA();
    ServiceA(RepositoryFileTXT<Angajat>& r);
    ~ServiceA();
    void setRepo(RepositoryFileTXT<Angajat>& r);
    void addElem(int id,char* nume,char* email,int grad);
    void updateElem(int id1,int id2,char* nume,char* email,int grad);
    void deleteElem(int id);
    Angajat getPoz(int id);
    vector<Angajat> getAll();
    int getSize();
    bool checkUser(string User,string Pass);
};

#endif /* ServiceA_h */
