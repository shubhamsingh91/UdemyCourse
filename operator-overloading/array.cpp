#include <iostream>
#include "../utils.h"


class IntArray {
  
  private:
   int size;
   int* arr [nullptr];

  public:
   IntArray(int n):size{n}{
    print("single arg constructor called!");
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
   }
   IntArray(int n, int t):size{n}{
    print("Double arg constructor called!");
    arr = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = t;
    }
   }
   IntArray(IntArray &obj) { // copy constructor
    print("copy constructor called!");
    if (this != &obj) {
      this->size = obj.size;
      this->arr = obj.arr;
    }
   } 
   int& operator[](const int& p) {
    return *(arr+p);
   }
   IntArray& operator=(IntArray& obj) {
    if (this != &obj) {
      this->size = obj.size;
      for (int i = 0; i < obj.size; i++) {
        this->arr[i] = obj[i];
      }
    } 
    return *this;
   }

   friend std::ostream& operator<<(std::ostream &out, IntArray& obj);

   ~IntArray(){
    delete []arr;
   }

};
 std::ostream& operator<<(std::ostream &out,IntArray& obj) {
    // print("arr = ",obj.arr);
    for (int i = 0; i < obj.size; i++) {
        out << obj[i] << " ";
    }
    return out;
 }

IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main() {

	IntArray a{ fillArray() };

	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;
	// std::cout << ref << '\n';

	IntArray b(1);
	b = a;

	a[4] = 7;

	std::cout << b << '\n';

    return 0;
}