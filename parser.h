#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#pragma once
#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

std::multimap <std::string, Mixed> mixes;

std::vector<std::string> reserved;

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

std::vector<std::string> parse_space(std::string s){
    size_t start = 0;
    size_t finish = 0;
    std::vector<std::string> s1;
    while(finish < s.size()){
        if(s[finish] == ' ' && start != finish){
            s1.push_back(s.substr(start, finish - start));
        }
        if(s[finish] == ' ')
            start = finish + 1;
        finish++;
    }
    if(s[finish - 1] != ' '){
        s1.push_back(s.substr(start, finish - start));
    }
    //std::cout<< "end parse"<< std::endl;
    return s1;
}

void parse_new(std::vector<std::string>* parts, bool isVal){
    if(mixes.find((*parts)[1]) != mixes.end()){
        std::cout << "Variable"<< (*parts)[1] <<"already exist\n";
        return;
    }
    //need more checking if name conteins only letters and numbers
    //string mb consists spaces... hmm
    if(std::find(reserved.begin(), reserved.end(), (*parts)[1]) != reserved.end()){
        std::cout << "Do not call the variable like "<< (*parts)[1] << ". It's reserved word\n";
    }
    if((*parts)[3][0] == '"'){
        //std::cout<< "its string"<< std::endl;
        Mixed mixi = Mixed((*parts)[3].substr(1,(*parts)[3].size() - 2), isVal, (*parts)[1]);
        mixes.insert({mixi.name, mixi});
    }
    else{
        if((*parts)[3].find('.') == std::string::npos){
            //std::cout<< "its int"<< std::endl;
            //had to made my own stoi and stof, because of compiler version
            Mixed mixi = Mixed(stoi(((*parts)[3])), isVal, (*parts)[1]);
            mixes.insert({mixi.name, mixi});
        }else{
            //std::cout<< "its float"<< std::endl;
            Mixed mixi = Mixed(stof(((*parts)[3])), isVal, (*parts)[1]);
            mixes.insert({mixi.name,mixi});
        }
    }
    //std::cout << "end parse new"<< std::endl;
}


/*
var x = 123;
print(x);
*/

void parse_print(std::vector<std::string>* parts){
    //right to make more checking. Not every input code is perfect
    if((*parts).size() == 1 && (*parts)[0][6] != '"'){
        std::string key = (*parts)[0].substr(6, (*parts)[0].size() - 7);
        std::multimap<std::string, Mixed>::iterator it = mixes.find(key);
        if(it == mixes.end()){
            std::cout<< "I don't know this variable\n";
            return;
        }
        Mixed mix = it->second;
        if(mix.type == Inty)
            std::cout << mix.inty;
        if(mix.type == Floaty)
            std::cout << mix.floaty;
        if(mix.type == Stringy)
            std::cout << mix.stringy;
        std::cout<<"\n";
    }else{
        //case with pluses, minuses and " " inside
    }
}

void parse(std::string s){
    std::vector<std::string> parts_s = parse_space(s);
    if(parts_s[0] == "val")
        parse_new(&parts_s, false);
    if(parts_s[0] == "var")
        parse_new(&parts_s, true);
    if(parts_s[0].size() >=5 && parts_s[0].substr(0, 5) == "print")
        parse_print(&parts_s);
}

#endif // PARSER_H_INCLUDED
