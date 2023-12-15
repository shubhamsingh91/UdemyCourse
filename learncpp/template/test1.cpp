#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <algorithm>


using namespace std;

template<typename T>
class Array{

private:
 T* arr;
 size_t len;

 public:
 Array(){
        arr = new T[len];
 };
 Array(size_t n):len{n}{
    arr = new T[len];
 }

 ~Array(){delete [] arr;};
 
  void erase(){
    delete [] arr;
    arr = nullptr;
    len=0;
    
  }
  T& operator[](const int loc){
   assert(loc<len);
   if (loc<len){
    return arr[loc];
   }
  }

  void print(){
    for(int i=0;i<len;i++){
        cout << arr[i] <<  " ";
    }
    cout << endl;
  }
  friend std::ostream& operator<<( std::ostream &out,  Array& a){
    
    for(int i=0;i<a.len;i++){
        out << a[i] << " ";
    }
    return out;
  }
  int get_length();
  
};

template<typename T>
int Array<T>::get_length()
{
    return len;
}

template<typename T, int size>
class StaticArray{

    private:
     T arr[size];
    
    public:
     T* ptr;
    StaticArray(){};
    T& operator[](const int loc){
        assert(loc<=size);
        if(loc<=size){
            return arr[loc];
        }
    }
    void print();
    ~StaticArray(){};


};

template<typename T, int size>
void StaticArray<T,size>::print(){
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// not working for some reason
// template< int size>
// void StaticArray<std::string,size>::print(){
//     for(int i=0;i<size;i++){
//         std::cout << arr[i][0] << " ";
//     }
//     std::cout << endl;
// }


// template specialization for type string
template<int size>
class StaticArray<std::string,size>{
private:
     std::string arr[size];
    
    public:
     std::string* ptr;
    StaticArray(){};
    std::string & operator[](const int loc){
        assert(loc<=size);
        if(loc<=size){
            return arr[loc];
        }
    }
    virtual void print(){
        for(int i=0;i<size;i++){
            cout << arr[i][0] << " ";
        }
        cout << endl;
    }
    ~StaticArray(){};

};



int main(){

  Array<int> a{3};
  a[0]=23;
  a[1]=2;
  a[2] = 6;

  a.print();
  cout << "a len = " << a.get_length() << endl;
  a.erase();

  Array<double> d{4};
  d[0] = 1.2; d[1] = 4.4;

  cout << "d len = " << d.get_length() << endl;
  d.print();

  cout << "-------------1----------------" << endl;
     StaticArray<int,5> a2;
     a2[0]=2;  a2[1]=5; a2[2]=56; a2[3]=34; a2[4]=12;

     a2.print();

     StaticArray<std::string,3> s1;
     s1[0]="Hello";s1[1]= "World";
     s1[2]="there";

     s1.print();





    return 0;
}