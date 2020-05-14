//
//  RepoFile.cpp
//  Lab 7
//
//  Created by Haris Muller Cristea on 23/04/2020.
//  Copyright © 2020 Cristea Muller Haris. All rights reserved.
//

#include <stdio.h>
#include "RepoFile.h"
#include "Repo.h"
#include "medicament.h"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

template <class T>
RepositoryFileTXT <T> :: RepositoryFileTXT ()
{
    this->fileName=NULL;
}

template <class T>
RepositoryFileTXT <T> ::RepositoryFileTXT (const char* fileName)
{
    this->fileName = new char[strlen(fileName) + 1];
    strcpy(this->fileName, fileName);
    this->loadFromFile();
}

template <class T>
RepositoryFileTXT <T> :: ~RepositoryFileTXT ()
{
    if(this->fileName!= NULL)
    {
        delete[] this->fileName;
        this->FileName=NULL;
    }
//    this->elements.clear();
}

template <class T>
void RepositoryFileTXT <T> ::setFileName(const char* fileName)
{
    if (this->fileName != NULL)
    {
        delete[] this->fileName;
    }
    this->fileName = new char[strlen(fileName) + 1];
    strcpy_s(this->fileName, strlen(fileName) + 1, fileName);
}

template <class T>
void RepositoryFileTXT <T>::addElement(T* s) {
    this->elements.push_back(*s);
}

template <class T>
vector<T> RepositoryFileTXT <T>::getAll() {
    return this->elements;
}

template <class T>
int RepositoryFileTXT <T>::getSize()
{
    return this->elements.size();
}

template <class T>
T RepositoryFileTXT <T>::getElement(int id)
{
    typename vector<T> :: iterator it;

    for(
        it=this->elements.begin() ;
        it!=this->elements.end();
        it++
        )
        if( (*it).getID() == id )
            return *it;

    return *(this->elements.begin());
}


template <class T>
void RepositoryFileTXT <T>::loadFromFile()
{
    if (this->fileName != NULL)
    {
        this->students.clear();
        ifstream f(this->fileName);
        char* nume = new char[20];
        char* reteta=new char[50];
        char* producator=new char[50];
        int id;
        int numarstoc;
        while (!f.eof())
        {
            f >> id >> nume >> reteta>> numarstoc >> producator;
            if (strlen(nume) > 0)
            {
                this->addElement(Medicament(id,nume,reteta,numarstoc,producator));
            }
        }
        delete[] nume;
        delete[] reteta;
        delete[] producator;
        f.close();
    }
}

template <class T>
void RepositoryFileTXT <T>::updateElement(T oldElement, T newElement)
{
    vector<T> elements = this->elements;
    typename vector<T> :: iterator it;

    it = find(this->students.begin(), this->students.end(), oldElement);
    if (!(it == this->students.end()))
    {
        *it = newElement;
    }
}

template <class T>
void RepositoryFileTXT <T>::deleteElement(int id)
{
    vector<T> elements = this->elements;
    typename vector<T> :: iterator it;

    for( it = elements.begin() ; it!=elements.end(); it++ )
        if( (*it).getID() == id)
        {
            this->elements.erase(it);
            break;
        }
}

