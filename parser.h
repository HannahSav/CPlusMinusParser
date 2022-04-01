#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>

//std::multiset <Mixed> mixes;

int stoi(std::string s){
    int res = 0;
    for(int i = 0; i < s.size(); i++){
        res = res*10;
        res = res + (s[i] - '0');
    }
    std::cout << "res of stoi is "<< res<< std::endl;
    return res;
}

int stof(std::string s){
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
    std::cout << "res of ftoi is "<< res<< std::endl;
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
    std::cout<< "end parse"<< std::endl;
    return s1;
}

void parse_new(std::vector<std::string>* parts, bool isVal){

    std::cout<< (*parts)[3];
    //Mixed mixi = new Mixed();
    if((*parts)[3][0] == '"'){
        std::cout<< "its string"<< std::endl;
        Mixed mixi = Mixed((*parts)[3], isVal);
        //mixes.insert(mixi);
    }
    else{
        if((*parts)[3].find('.') == std::string::npos){
            std::cout<< "its int"<< std::endl;
            //had to made my own stoi and stof, because of compiler version
            Mixed mixi = Mixed(stoi(((*parts)[3]).substr(0, ((*parts)[3]).size())), isVal);
            //mixes.insert(mixi);
        }else{
            std::cout<< "its float"<< std::endl;
            Mixed mixi = Mixed(stof(((*parts)[3]).substr(0, ((*parts)[3]).size())), isVal);
            //mixes.insert(mixi);
        }
    }
    std::cout << "end parse new"<< std::endl;
}

void parse(std::string s){
    std::vector<std::string> parts_s = parse_space(s);
    /*for(int i = 0; i < parts_s.size(); i++){
        std::cout << parts_s[i]<< "...\n";
    }*/
    if(parts_s[0] == "val")
        parse_new(&parts_s, false);
    if(parts_s[0] == "var")
        parse_new(&parts_s, true);
    if(parts_s[0].size() >=5 && parts_s[0].substr(0, 5) == "print")
        parse_new(&parts_s, false);
}

#endif // PARSER_H_INCLUDED
