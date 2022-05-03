//
// Created by BukV0 on 27.04.2022.
//

#ifndef SORTIROVKI_FAVOR_H
#define SORTIROVKI_FAVOR_H
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
enum Favor{
    WEAK,
    MODERATE,
    STRONG
};
class Flower{
    string  name;
    string color;
    Favor fav;
    string regions;
public:
    Flower(){
    }
    Flower(string name_in, string color_in, Favor fav_in, string regions_in){
        name = name_in;
        color =color_in;
        fav = fav_in;
        regions = regions_in;
    }
    Flower(const Flower& fl){
        name=fl.name;
        color = fl.color;
        fav = fl.fav;
        regions = fl.regions;
    }
    string get_name(){
        return name;
    }
    string get_color(){
        return color;
    }
    Favor get_favor(){
        return fav;
    }
    string get_regions(){
        return regions;
    }
    void print(){
        cout << "name " << name << endl;
        cout << "color " << color << endl;
        cout << "fav " << fav << endl;
        cout << "regions " << regions << endl;
    }
    Flower& operator=(const Flower& right){
        name = right.name;
        color = right.color;
        fav = right.fav;
        regions = right.regions;
        return *this;
    }
    friend bool operator<(const Flower& left,const Flower& right);
    friend bool operator>(const Flower& left,const Flower& right);
    friend bool operator<=(const Flower& left,const Flower& right);
    friend bool operator>=(const Flower& left,const Flower& right);
    friend bool operator==(const Flower& left,const Flower& right);
};


#endif //SORTIROVKI_FAVOR_H
