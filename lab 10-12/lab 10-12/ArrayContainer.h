#ifndef ARRAYCONTAINER_H
#define ARRAYCONTAINER_H

#include "IContainer.h"


class ArrayContainer : public IContainer{
private:
    int size;
    int capacity;
    IE* * elements;
    // IE* elements[100];
    void resize();
public:
    ArrayContainer(int c);
    ArrayContainer(const ArrayContainer &ac);
    ~ArrayContainer();
    ArrayContainer& operator=(const ArrayContainer &ac);
    void addElem(IE* e);
    void removeElem(IE* e);
    int getSize();
    bool contains(IE* e);
    IE* getElemPos(int pos);

    friend class ArrayIterator;
    IIterator* getIterator();
};

class ArrayIterator : public IIterator{
private:
    ArrayContainer* container;
    int crtPos;
public:
    ArrayIterator(ArrayContainer* ac){
        this->container = ac;
        this->crtPos = 0;
    }
    ~ArrayIterator(){
    
    }
    void moveNext(){
        this->crtPos++;
    }
    bool hasNext(){
        return (this->crtPos < this->container->getSize() - 1);
    }
    bool isValid(){
        return (this->crtPos < this->container->getSize());
    }
    IE* getCrtElem(){
        return this->container->elements[crtPos];
    }
    void moveFirst(){
        this->crtPos = 0;
    }
};


void ArrayContainer::resize(){
    IE** aux = new IE*[2 * this->capacity];
    for(int i = 0; i < this->capacity; i++)
        aux[i]= this->elements[i]->clone();
    delete[] this->elements;
    this->elements = aux;
    this->capacity *= 2;
}

IE* ArrayContainer::getElemPos(int pos){
    return this->elements[pos]->clone();
}

ArrayContainer::ArrayContainer(int c){
    this->size = 0;
    this->capacity = c;
    this->elements = new IE*[c];
}
ArrayContainer::ArrayContainer(const ArrayContainer &ac){
    this->size = ac.size;
    this->capacity = ac.capacity;
    this->elements = new IE*[ac.capacity];
    for (int i = 0; i < ac.size; i++)
        // this->elements[i] = ac.elements[i];
        this->elements[i] = ac.elements[i]->clone();
}
ArrayContainer::~ArrayContainer(){
    if (this->elements){
        for(int i = 0; i < this->size; i++)
            if (this->elements[i]){
                delete this->elements[i];    //~IE() -> ~Flower()
                this->elements[i] = NULL;
            }
        delete[] this->elements;
        this->elements = NULL;
    }
}
ArrayContainer& ArrayContainer::operator=(const ArrayContainer &ac){
    if (this != &ac){
        this->size = ac.size;
        this->capacity = ac.capacity;
        if (this->elements){
            for(int i = 0; i < this->size; i++)
                if (this->elements[i]){
                    delete this->elements[i];
                    this->elements[i] = NULL;
                }
            delete[] this->elements;
        }
        this->elements = new IE*[ac.capacity];
        for(int i = 0; i < ac.size; i++)
            this->elements[i] = ac.elements[i]->clone();
    }
    return *this;
}
void ArrayContainer::addElem(IE* e){
    if (size >= capacity)
        this->resize();
    this->elements[this->size++] = e->clone();
}
void ArrayContainer::removeElem(IE* e){
    int i = 0;
    while (i < this->size){
        if (e->equals(this->elements[i])){
            delete this->elements[i]; //IE*
            for(int j = i; j < this->size - 1; j++)
                this->elements[j] = this->elements[j + 1];
            this->size--;
        }
        else
            i++;
    }
}
int ArrayContainer::getSize(){
    return this->size;
}
bool ArrayContainer::contains(IE* e){
    for(int i = 0; i < this->size; i++)
        if (e->equals(this->elements[i]))
            return true;
    return false;
}
IIterator* ArrayContainer::getIterator(){
    // return new ArrayIterator(this);
    IIterator* pit = new ArrayIterator(this);
    return pit;
}

#endif

