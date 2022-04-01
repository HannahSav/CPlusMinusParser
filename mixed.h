#ifndef MIXED_H_INCLUDED
#define MIXED_H_INCLUDED

#pragma once
#include <iostream>
#include <string>
#include <float.h>

//using namespace std;


struct Mixed{
    enum {Inty = 1, Floaty, Stringy} type;
    bool isConst;
    //union has troubles with string и float
    int inty;
    float floaty;
    std::string stringy;
    Mixed(int inty, bool isConst){
        this->type = Inty;
        this->inty = inty;
    }
    Mixed(std::string stringy, bool isConst){
        this->type = Stringy;
        this->stringy = stringy;
    }
    Mixed(float floaty, bool isConst){
        this->type = Floaty;
        this->floaty = floaty;
    }
    Mixed(){

    }

    public: void print(){
         switch(type)
        {
        case 1: std::cout << this->inty << '\n'; break;
        case 2: std::cout << this->floaty << '\n'; break;
        case 3: std::cout << this->stringy << '\n'; break;
        }
    }
};


#endif // MIXED_H_INCLUDED
