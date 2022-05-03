/*
а) Сортировка выбором
д) Пирамидальная сортировка
е) Быстрая сортировка
 */


#include <iostream>
#include <string>
#include <fstream>
#include <chrono>
#include "favor.h"
#include "sort.h"
#include "searches.h"
void rt(Flower arr[],int size){
    for(int i = 0;i< size;i++){
        arr[i].print();
    }
}
void file_out(Flower arr[], int size, string filename){
    ofstream fout;
    fout.open(filename);
    for(int i = 0; i< size;i++){
        fout << arr[i].get_name() << ' ' << arr[i].get_color() << ' ' << arr[i].get_favor() << ' ' << arr[i].get_regions() << endl;
    }
    fout.close();
}
int main() {
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    Flower *arr = new Flower[30000];
    Flower *arr1 = new Flower[30000];
    Flower *arr2 = new Flower[30000];
    int arr_size = 1000;
    ifstream inFile;
    string name;
    string color;
    string fav;
    string region;
    inFile.open("/Users/vladimr/CLionProjects/sortirovki/30000.csv");
    if (inFile.is_open()) {
        cout << "File has been opened" << endl;
    }
    else {
        cout << "NO FILE HAS BEEN OPENED" << endl;
    }

    int k = 0;
    while (!inFile.eof()) {
        inFile >> name;
        inFile >> color;
        inFile >> fav;
        inFile >> region;
        Favor f = static_cast<Favor>(stoi(fav));
        Flower temp(name,color,f,region);
        arr[k] = temp;
        arr1[k] = temp;
        arr2[k] = temp;
        k++;
    }
    cout << "arr before sort" <<endl;
    file_out(arr,k,"/Users/vladimr/CLionProjects/sortirovki/first_arr_b.txt");
    file_out(arr1,k,"/Users/vladimr/CLionProjects/sortirovki/second_arr_b.txt");
    file_out(arr2,k,"/Users/vladimr/CLionProjects/sortirovki/third_arr_b.txt");
    auto t1 = high_resolution_clock::now();
    vib_sort(arr,k);
    auto t2 = high_resolution_clock::now();
    auto t3 = high_resolution_clock::now();
    quicksort(arr2,k);
    auto t4 = high_resolution_clock::now();
    auto t5 = high_resolution_clock::now();
    piramid_sort(arr1,k);
    auto t6 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - t1;
    duration<double, std::milli> ms_double1 = t4 - t3;
    duration<double, std::milli> ms_double2 = t6 - t5;
    file_out(arr,k,"/Users/vladimr/CLionProjects/sortirovki/first_arr_a.txt");
    file_out(arr1,k,"/Users/vladimr/CLionProjects/sortirovki/second_arr_a.txt");
    file_out(arr2,k,"/Users/vladimr/CLionProjects/sortirovki/third_arr_a.txt");
    cout << k << endl;
    cout << "viborom: ";
    cout << ms_double.count() << "ms\n";
    cout << "bistraya: ";
    cout << ms_double1.count() << "ms\n";
    cout << "piramid: ";
    cout << ms_double2.count() << "ms\n";
    inFile.close();


    return 0;
}
