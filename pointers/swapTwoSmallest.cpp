#include <stdio.h>
#include <iostream>

using namespace std;

void swapTwoSmallest(int* arr, int size){

int num1{0};
int count[2];
int *p{count};

 for (int i=0;i<size-1;i++){
   num1 = *(arr+i);
   if(*(arr+i+1)<=num1){
    num1=*(arr+i+1);
    *p=arr+i+1;
    p++;

   } 

 }
 cout << *(count) << " " << *(count+1) << endl;

}


int main(){

    int arr[] = {9, 5, 3, 8, 6};
int size = sizeof(arr) / sizeof(arr[0]);

swapTwoSmallest(arr, size);

std::cout << "Swapped array: ";
for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
}
std::cout << std::endl;
}