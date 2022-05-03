//
// Created by BukV0 on 27.04.2022.
//

#include "sort.h"
void vib_sort(Flower arr[],int size){
    Flower temp;
    int el_index;
    for(int i = 0; i < size-1;i++){
        temp = arr[i];
        el_index = i;
        for(int j = i+1;j<size;j++){
            if(arr[j] < arr[el_index]){
                el_index=j;
            }
        }
        if(el_index != i){
            arr[i] = arr[el_index];
            arr[el_index] = temp;
        }
    }

}
void piromidify(Flower arr[], int size, int root){
    int lar = root;
    int l = 2*root +1;
    int r = 2*root + 2;
    if(l < size && arr[l] > arr[lar]){
        lar = l;
    }
    if(r < size && arr[r] > arr[lar]){
        lar = r;
    }
    if(lar != root){

        Flower temp;
        temp = arr[root];
        arr[root] = arr[lar];
        arr[lar] = temp;

        piromidify(arr,size,lar);
    }
}
void piramid_sort(Flower arr[],int size){
    for(int i = size/2-1;i>=0;i--){
        piromidify(arr,size,i);
    }
    for(int i = size-1;i>=0;i--){

        Flower temp;
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        piromidify(arr,i,0);
    }

}
void quicksort(Flower arr[],int size){
    int i = 0;
    int j = size - 1;
    Flower mid = arr[size/2];
    do{
        while(arr[i]<mid){
            i++;
        }
        while(arr[j] > mid){
            j--;
        }
        if(i<=j){
            Flower temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }while(i<=j);
    if(j>0){
        quicksort(arr,j);
    }
    if(i < size){
        quicksort(arr,size-i+1);
    }
}