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


#endif /* RepoFile_h */
