#include <stdio.h>
#include <iostream>

using namespace std;
int* findCommonElements(const int* arr1, int size1, const int* arr2, int size2){

int size{0};
int *p {nullptr};

for (int i=0;i<size1;i++){
    for (int j=0;j <size2; j++){
        if (*(arr1+i)==*(arr2+j)){
            size+=1;
        }
    }
}

cout << "size = " << size << endl;

if(size>0){
    p = new int[size];
    size=0;
    for (int i=0;i<size1;i++){
        for (int j=0;j <size2; j++){
            if (*(arr1+i)==*(arr2+j)){
                *(p+size)=*(arr1+i);
                size++;
            }
        }
    }
}

return p;
}
int main(){


int arr1[] = {1, 2, 3, 4, 5,45,32,1};
int arr2[] = {2, 7, 8, 9, 10,16,32,34,45};
int size1 = sizeof(arr1) / sizeof(arr1[0]);
int size2 = sizeof(arr2) / sizeof(arr2[0]);

int* commonElements = findCommonElements(arr1, size1, arr2, size2);
if (commonElements == nullptr) {
    std::cout << "No common elements found." << std::endl;
} else {
    std::cout << "Common elements: ";
    for (int i = 0; i < size1; i++) {
        std::cout << commonElements[i] << " ";
    }
    std::cout << std::endl;
    delete[] commonElements; // Don't forget to free the memory!
}


}