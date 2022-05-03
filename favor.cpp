//
// Created by BukV0 on 27.04.2022.
//

#include "favor.h"
bool operator==(const Flower& left,const Flower& right){
    if(left.name == right.name && left.color == right.color && left.fav == right.fav && left.regions == right.regions) return true;
    return false;
}
bool operator>=(const Flower& left,const Flower& right){
    if(left.name == right.name){
        if(left.color == right.color){
            return left.fav >= right.fav;
        }
        else{
            return left.color > right.color;
        }
    }
    else{
        return  left.name > right.name;
    }
}
bool operator<=(const Flower& left,const Flower& right){
    if(left.name == right.name){
        if(left.color == right.color){
            return left.fav <= right.fav;
        }
        else{
            return left.color < right.color;
        }
    }
    else{
        return  left.name < right.name;
    }
}
bool operator>(const Flower& left,const Flower& right){
    if(left.name == right.name){
        if(left.color == right.color){
            return left.fav > right.fav;
        }
        else{
            return left.color > right.color;
        }
    }
    else{
        return  left.name > right.name;
    }
}
bool operator<(const Flower& left,const Flower& right){
    if(left.name == right.name){
        if(left.color == right.color){
            return left.fav < right.fav;
        }
        else{
            return left.color < right.color;
        }
    }
    else{
        return  left.name < right.name;
    }
}