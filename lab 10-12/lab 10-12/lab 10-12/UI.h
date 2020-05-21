//
//  UI.h
//  lab 10-12
//
//  Created by Haris Muller Cristea on 13/05/2020.
//  Copyright © 2020 Cristea Muller Haris. All rights reserved.
//

#ifndef UI_h
#define UI_h
#include "ServiceM.h"
#include "ServiceA.h"

class UI
{
private:
    ServiceM serviceM;
    ServiceA serviceA;
public:
    UI();
    UI(ServiceM& serviceM,ServiceA& serviceA);
    void login();
    void meniu();
};

#endif /* UI_h */
