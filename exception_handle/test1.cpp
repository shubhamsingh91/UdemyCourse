// basics of exception handling here
#include <stdio.h>
#include <iostream>
#include "../utils.h"

class Book{

    public:
      int isbn;
      float price;

      Book (){};
      Book (int n): isbn{n}{};
      Book (int n, float m): isbn{n}, price{m}{};

      ~Book(){};
};

int main(){

    Book b1{122, 34.1};
    Book b2{124, 46.1};

    try
    {
       if (b1.isbn!=b2.isbn){
            throw std::runtime_error{"The isbn of the two books is not same!"};
       } else {
           print("The isbn of the two books is same!");
       }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        std::cout << "change isbn of book-1? ";
        char c;
        std::cin >> c;
        if (c=='y'){
            b1.isbn = b2.isbn;
            print("isbn changed!");
            print("isbn book-1 = ", b1.isbn);
            print("isbn book-2 = ", b2.isbn);
        } else if (c=='n'){

        }
    }
    

    
}