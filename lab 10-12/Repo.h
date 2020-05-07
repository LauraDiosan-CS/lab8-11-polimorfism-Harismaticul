//
//  Repo.h
//  lab 10-12
//
//  Created by Haris Muller Cristea on 06/05/2020.
//  Copyright © 2020 Cristea Muller Haris. All rights reserved.
//

#ifndef Repo_h
#define Repo_h

#pragma once

#include<vector>
#include<iterator>
using namespace std;


//Repo<Prajitura> repo;

template <class T>
class Repository
{
private:
    vector<T> elements;
    
public:
    Repository()
    {
        this->elements.clear();
    }
    ~Repository()
    {
        this->elements.clear();
    }
    
    virtual int size()
    {
        return this->elements.size();
    }
    
    virtual void add( T element )
    {
        this->elements.push_back(element);
    }
    
    virtual T getElement(int id)
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
    
    virtual vector<T> getAll()
    {
        return this->elements;
    }
    
    virtual void update(T* oldElement, T* newElement)
    {
        vector<T> elements = this->elements;
        typename vector<T> :: iterator it;
        
        it = find(this->elements.begin(), this->elements.end(), *oldElement);
                if (!(it == this->elements.end()))
                {
                    *it = *newElement;
                }
}
    
    
    virtual void del(int id)
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

};




#endif /* Repo_h */
