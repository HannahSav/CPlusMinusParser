#ifndef MIXED_H_INCLUDED
#define MIXED_H_INCLUDED

#pragma once
#include <iostream>
#include <string>
#include <float.h>

//using namespace std;

enum Type {Inty, Floaty, Stringy};

int stoi(std::string s){
    int res = 0;
    for(int i = 0; i < s.size(); i++){
        res = res*10;
        res = res + (s[i] - '0');
    }
    //std::cout << "res of stoi is "<< res<< std::endl;
    return res;
}

float stof(std::string s){
    float res = 0.0;
    int i = 0;
    while(s[i] != '.'){
        res = res*10;
        res = res + (s[i] - '0');
        i++;
    }
    int i2 = s.size()-1;
    float res1 = 0;
    while(i2>i){
        res1 = res1 + (s[i2] - '0');
        res1 = res1/10;
        i2--;
    }
    res += res1;
    //std::cout << "res of stof is "<< res<< std::endl;
    return res;
}

bool intString(std::string s){
    if(s[0] == '0' && s.size() > 1)
        return 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] > '9' || s[i] < '0')
            return 0;
    }
    return 1;
}

bool floatString(std::string s){
    if(s.size() < 3 || (s[0] == '0' && s[1] != '.'))
        return 0;
    bool had_point = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '.'){
            if(had_point)
                return 0;
            else
                return 1;
        }
        else if(s[i] < '0' || s[i] > '9')
            return 0;
    }
    if(s[s.size()-1] == '.')
        return 0;
    return 1;
}

struct Mixed{
    Type type;
    bool isConst;
    std::string name;
    //union has troubles with string and float
    int inty;
    float floaty;
    std::string stringy;
    //for strings:
    bool isInt = false;
    bool isFloat = false;
    Mixed(int inty, bool isConst, std::string name){
        this->type = Inty;
        this->inty = inty;
        this->name = name;
    }
    Mixed(std::string stringy, bool isConst, std::string name){
        this->type = Stringy;
        this->stringy = stringy;
        this->name = name;
        isInt = intString(stringy);
        isFloat = floatString(stringy);
        if(isInt){
            this->inty = stoi(stringy);
            isFloat = 1;
            this->floaty = (this->inty)*1.0f;
        }else if(isFloat){
            this->floaty = stof(stringy);
        }else{
             this->inty = 0;
             this->floaty = 0.0f;
        }
    }
    Mixed(float floaty, bool isConst, std::string name){
        this->type = Floaty;
        this->floaty = floaty;
        this->name = name;
    }
    Mixed(){

    }

    public: void print(){
        if(this->type == Inty)
            std::cout << this->inty << '\n';
        else if(this->type == Floaty)
            std::cout << this->floaty << '\n';
        else if(this->type == Stringy)
            std::cout << this->stringy << '\n';
        }
};


//every time we're asking some <...>+<...> - we create Mixed, and send it to this func
Mixed pluss(Mixed a, Mixed b){
    //TODO: if minus send b as -b
    Mixed mixy;
    if(a.type == b.type){
            //what should do with all this if's?????????
        if(a.type == Inty)
            mixy = Mixed(a.inty + b.inty, false, "aPlusb");
        if(a.type == Floaty)
            mixy = Mixed(a.floaty + b.floaty, false, "aPlusb");
        if(a.type == Stringy)
            mixy = Mixed(a.stringy + b.stringy, false, "aPlusb");
    }else{
        if(a.type != Stringy && b.type != Stringy){
            if(a.type == Inty)
                mixy = Mixed(a.inty*1.0f+b.floaty, false, "aPlusb");
            else
                mixy = Mixed(a.floaty+b.inty*1.0f, false, "aPlusb");
        }
        else{
            if(a.type == Stringy){
                    if(!a.isFloat)
                        mixy = b;
                    else{
                        if(a.type == Inty && a.isInt)
                                mixy = Mixed(a.inty+b.inty, false, "aPlusb");
                        else
                            mixy = Mixed(a.floaty+b.inty*1.0f, false, "aPlusb");
                        //a string, b float;
                    }
            }else{
               mixy = pluss(b, a); //the same with b;
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
