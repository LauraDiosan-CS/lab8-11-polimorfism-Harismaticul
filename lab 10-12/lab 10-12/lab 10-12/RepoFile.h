//
//  RepoFile.h
//  lab 10-12
//
//  Created by Haris Muller Cristea on 07/05/2020.
//  Copyright © 2020 Cristea Muller Haris. All rights reserved.
//

#ifndef RepoFile_h
#define RepoFile_h
#include "Repo.h"
#include "medicament.h"
#include <fstream>

template <class T>
class RepositoryFileTXT : public Repository <T>
{
private:
    vector<T> elements;
    char* fileName;
public:
    RepositoryFileTXT();
    RepositoryFileTXT(const char* fileName);
//    RepoF(const RepoFile& r);
    ~RepositoryFileTXT();
    void setFileName(const char* fileName);
    void loadFromFile();
    void updateElement(T oldElement,T newElement);
    void deleteElement(int id);
    T getElement(int id);
    void addElement(T* s);
    int getSize();
    vector <T> getAll();
};

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
        this->fileName=NULL;
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
        if( (*it).getid() == id )
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

    it = find(this->elements.begin(), this->elements.end(), oldElement);
    if (!(it == this->elements.end()))
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
        if( (*it).getid() == id)
        {
            this->elements.erase(it);
            break;
        }
}
#endif /* RepoFile_h */
