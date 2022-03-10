/*
а) Сортировка выбором
д) Пирамидальная сортировка
е) Быстрая сортировка
 */


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
      cout << "Kopirovnie worked";
  }
  string get_name(){
      return name;
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

        // If the element is present at the middle
        // itself
        if (arr[mid].get_name() == x)
            return mid;

        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid].get_name() > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when element is not
    // present in array
    return -1;
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
void rt(Flower arr[],int size){
    for(int i = 0;i< size;i++){
        arr[i].print();
    }
}

int main() {
    Flower *arr = new Flower[16];
    Flower *arr1 = new Flower[16];
    Flower *arr2 = new Flower[16];

    //vib_sort(&arr);
    ifstream inFile;
    string name;
    string color;
    string fav;
    string region;
    inFile.open("/Users/vladimr/CLionProjects/sortirovki/worldcities.csv");
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
//        cout << "name: " << name << endl;
//        cout << "Color: " << color << endl;
//        cout << "Region: " << region << endl;
//        cout << "fav: " << stoi(fav) << endl;
        Favor f = static_cast<Favor>(stoi(fav));
        Flower temp(name,color,f,region);
        //temp.print();
        arr[k] = temp;
        arr1[k] = temp;
        arr2[k] = temp;
        k++;
    }
    cout << "arr before sort" <<endl;
    for(int i = 0; i <k;i++){
        arr[i].print();
    }
//    cout << "arr1 before sort" <<endl;
//    for(int i = 0; i <k;i++){
//        arr1[i].print();
//    }
//    cout << "arr2 before sort" <<endl;
//    for(int i = 0; i <k;i++){
//        arr2[i].print();
//    }
    vib_sort(arr,k);
    quicksort(arr2,k);
    piramid_sort(arr1,k);
    cout << "arr after sort" <<endl;
    for(int i = 0; i <k;i++){
        arr[i].print();
        cout << endl;
        cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << "arr1 after sort" <<endl;
    for(int i = 0; i <k;i++){
        arr1[i].print();
        cout << endl;
        cout << endl;
        cout << endl;
    }
    cout << endl;
    cout << endl;
    cout << "arr2 after sort" <<endl;
    for(int i = 0; i <k;i++){
        arr2[i].print();
    }

    cout << k;
    inFile.close();


    return 0;
}
