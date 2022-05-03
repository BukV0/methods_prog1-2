//
// Created by BukV0 on 27.04.2022.
//

#include "searches.h"
int pr_poisk(Flower arr[],int size,string elem){
    for(int i = 0; i < size;i++){
        if(arr[i].get_name() == elem){
            return i;
        }
    }
    return -1;
}
int binarySearch(Flower arr[], int l, int r, string x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid].get_name() == x)
            return mid;
        if (arr[mid].get_name() > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
int keymulmap(Flower arr[],int size){
    multimap<string,Flower> mm;
    for(int i =0; i<size;i++){
        
    }
}