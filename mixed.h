#ifndef MIXED_H_INCLUDED
#define MIXED_H_INCLUDED

#pragma once
#include <iostream>
#include <string>
#include <float.h>

//using namespace std;

enum Type {Inty, Floaty, Stringy};

struct Mixed{
    Type type;
    bool isConst;
    std::string name;
    //union has troubles with string и float
    int inty;
    float floaty;
    std::string stringy;
    Mixed(int inty, bool isConst, std::string name){
        this->type = Inty;
        this->inty = inty;
        this->name = name;
    }
    Mixed(std::string stringy, bool isConst, std::string name){
        this->type = Stringy;
        this->stringy = stringy;
        this->name = name;
    }
    Mixed(float floaty, bool isConst, std::string name){
        this->type = Floaty;
        this->floaty = floaty;
        this->name = name;
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

/* bool operator<(Mixed a, Mixed b)
{
    if (a.name < b.name)
        return true;
    return false;
}*/
#endif // MIXED_H_INCLUDED
