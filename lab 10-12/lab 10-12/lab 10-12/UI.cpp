//
//  UI.cpp
//  lab 10-12
//
//  Created by Haris Muller Cristea on 13/05/2020.
//  Copyright © 2020 Cristea Muller Haris. All rights reserved.
//

#include <stdio.h>
#include "UI.h"

using namespace std;

UI::UI()
{
}

UI::UI(ServiceM& serviceM,ServiceA& ServiceA)
{
    this->serviceM = serviceM;
    this->serviceA = serviceA;
}

void UI::login()
{
    cout<<"User: ";
    string user,pass;
    cin>>user;
    cout<<"Pass: ";
    cin>>pass;
    cout<<serviceA.checkUser(user, pass);
    if(this->serviceA.checkUser(user, pass)==true)
    {
        cout<<"Login reusit! "<<endl;
        this->meniu();
    }
    else
    {
        cout<<endl;
        cout<<"Logarea a esuat! "<<endl;
        this->login();
    }
}

void UI::meniu()
{
    cout<<"1.Adauga medicament"<<endl;
    cout<<"2.Sterge medicament"<<endl;
    cout<<"3.Modifica medicament"<<endl;
    cout<<"4.Gaseste medicament"<<endl;
    cout<<"5.Afisati toate medicamentele"<<endl;
    cout<<"6.Cautare";
    cout<<"7.Logout"<<endl;
    int optiune;
    cin>>optiune;
    if(optiune<1 and optiune>8)
    {
        cout<<"optiunea nu exista";
        this->meniu();
    }
    else if(optiune==1)
    {
        int id,numarstoc;
        string nume,producator;
        bool reteta;
        cout<<"id: ";
        cin>>id;
        cout<<endl;
        cout<<"nume: ";
        cin>>nume;
        cout<<endl;
        cout<<"reteta: ";
        cin>>reteta;
        cout<<endl;
        cout<<"numar stoc: ";
        cin>>numarstoc;
        cout<<endl;
        cout<<"producator: ";
        cin>>producator;
        cout<<endl;
        this->serviceM.addElem(id, nume, reteta, numarstoc, producator);
    }
    else if(optiune==2)
    {
        cout<<"id: ";
        int id;
        cin>>id;
        this->serviceM.remove(id);
    }
    else if(optiune==3)
    {
        cout<<"modifica elememntul cu id-ul: ";
        int id1;
        cin>>id1;
        Medicament old= this->serviceM.getPoz(id1);
        int id,numarstoc;
        string nume,producator;
        bool reteta;
        cout<<"id: ";
        cin>>id;
        cout<<endl;
        cout<<"nume: ";
        cin>>nume;
        cout<<endl;
        cout<<"reteta: ";
        cin>>reteta;
        cout<<endl;
        cout<<"numar stoc: ";
        cin>>numarstoc;
        cout<<endl;
        cout<<"producator: ";
        cin>>producator;
        cout<<endl;
        Medicament neww(id,nume,reteta,numarstoc,producator);
        this->serviceM.update(&old, &neww);
    }
    else if(optiune==4)
    {
        cout<<"gaseste medicament dupa id: ";
        int id;
        cin>>id;
        Medicament m=this->serviceM.getPoz(id);
        cout<<m.getid()<<" "<<m.getnume()<<" "<<m.getreteta()<<" "<<m.getnumarstoc()<<" "<<m.getproducator()<<endl;
    }
    else if(optiune==5)
    {
        int i;
        int size=this->serviceM.getSize();
        vector<Medicament> elements=this->serviceM.getAll();
        for(i=0;i<size;i++)
            cout<<elements[i].getid()<<" "<<elements[i].getnume()<<" "<<elements[i].getreteta()<<" "<<elements[i].getnumarstoc()<<" "<<elements[i].getproducator()<<endl;
    }
    else if(optiune==6)
    {
        cout<<"Cauta cuvant in medicament: ";
        string search;
        cin>>search;
        vector<Medicament> elements=serviceM.search(search);
        int i=0;
        while(true)
        {
            cout<<elements[i].getid()<<" "<<elements[i].getnume()<<" "<<elements[i].getreteta()<<" "<<elements[i].getnumarstoc()<<" "<<elements[i].getproducator()<<endl;
            i++;
        }
    }
    else if(optiune==7)
    {
        cout<<"Logout reusit!"<<endl;
        this->login();
    }
    
    
}
