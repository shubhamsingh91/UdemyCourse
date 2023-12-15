#include <stdio.h>
#include <iostream>
using namespace std;

 
 int main() {
 	int arr[5] = {11, 22, 33, 44, 55};
 	int i;
 	
 	for (int i = 0; i < 5; i++) {
 		//cout << *(arr + i);
 	}
    char *c = "Hellosdrd";
    char d[6];

    cout << c << endl;
    cout << *(++c) << endl;

 	return 0;
 }