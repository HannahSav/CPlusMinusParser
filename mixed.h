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
    //union has troubles with string and float
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


//every time we're asking some <...>+<...> - we create Mixed, and send it to this func
Mixed pluss(Mixed a, Mixed b){
    Mixed mixy;
    if(a.type == b.type){
            //what should do with all this if's?????????
        if(a.type == Inty)
            Mixed mixy = Mixed(a.inty + b.inty, false, "aPlusb");
        if(a.type == Floaty)
            Mixed mixy = Mixed(a.floaty + b.floaty, false, "aPlusb");
        if(a.type == Stringy)
            Mixed mixy = Mixed(a.stringy + b.stringy, false, "aPlusb");
    }else{
        if(a.type != Stringy && b.type != Stringy){
            if(a.type == Inty)
                Mixed mixy = Mixed(a.inty*1.0f+b.floaty, false, "aPlusb");
            else
                Mixed mixy = Mixed(a.floaty+b.inty*1.0f, false, "aPlusb");
        }
        else{
            if(a.type == Stringy){
                    if(b.type == Inty){
                        // mb create new Mixed of number from string and reuse this function)))
                        // !!!if string is BAD return 0!!!
                        //a string, b int;
                    }else{
                        //a string, b float;
                    }
            }else{
                if(a.type == Inty){
                        //b string, a int
                    }else{
                        //b string, a float
                    }
            }
        }
    }
    return mixy;
}

/* bool operator<(Mixed a, Mixed b)
{
    if (a.name < b.name)
        return true;
    return false;
}*/
#endif // MIXED_H_INCLUDED
