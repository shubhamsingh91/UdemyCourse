#include <iostream>
#include <cmath> // math library
#include <cstdlib> // for random numbers
#include <ctime> // for time
#include <vector>
#include <string>
#include <algorithm>    // std::min_element, std::max_element

// Udemy course- section 9,11- last challenge

using namespace std;

void print(vector<int> vec1);
void add(vector<int> &vec1);
double mean(vector<int> &vec1);
void smallest(vector<int> &vec1);
void largest(vector<int> &vec1);

int main()
{
    vector<int> vec1 {};
    char case_in {};

    while ((case_in != 'Q')&&(case_in != 'q'))
    {
        cout << "\n"<<"P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl;
        cout << "\n" << endl;
        cout << "Enter your choice:" << endl;

        cin >> case_in;
        cout << endl;

      switch(case_in) {
          //-------------------- Case Print-------------------------//
      case 'P' :
      {
         print(vec1);
         break;
      }
      case 'p' :
      {
         print(vec1);        
         break;
      }
        //-------------------- Case Add-------------------------//
      case 'A' :
      {
         add(vec1);
         break;
      }
      case 'a' :
      {
         add(vec1);        
         break;
      }      
      //-------------------- Case Mean-------------------------//

      case 'M' :
      {
         mean(vec1);
         break;
      }
      case 'm' :
      {
         mean(vec1);        
         break;
      }     
      //-------------------- Case Smallest-------------------------//

      case 'S' :
      {
         smallest(vec1);
         break;
      }
      case 's' :
      {
         smallest(vec1);        
         break;
      }        
     //-------------------- Case Largest-------------------------//

      case 'L' :
      {
         largest(vec1);
         break;
      }
      case 'l' :
      {
         largest(vec1);        
         break;
      }              
      //-------------------- Case Quit-------------------------//

    case 'Q' :
    {
        cout <<"Goodbye!" << endl;
        break;
    }
    case 'q' :
     {
        cout <<"Goodbye!" << endl;
        break;
     }    
     //-------------------- Case Default-------------------------//

            default :
         cout << "Invalid choice, please try again!" << endl;
   }
      

    }


}

void print(vector<int> vec1)
{
if (vec1.size()==0)
         {
             cout << "No integers present in the list!" << endl;
         } else{
            
            cout << "\n [";
             for (int ii=0; ii<vec1.size(); ii++)
             {
                 cout << vec1[ii] << " ";
             }
             cout << "]"<< endl;
         }

}

void add(vector<int> &vec1){

    int num1;
    cout << "Enter the number: " << endl;
    cin >> num1;
    vec1.push_back(num1);
    cout << num1<<" Added!" << endl;

        
}

double mean(vector<int> &vec1)
{

    double num1,sum=0.0;
    
    if (vec1.size()==0){
          cout << "Unable to calculate the mean - no data!" << endl;
         } else{
            for (int ii=0; ii<vec1.size(); ii++)
            {
                sum=sum+vec1.at(ii);
            }
            cout << "Mean of the list is " << sum/vec1.size() << endl; 
         }

    
}



void smallest(vector<int> &vec1)
{
      std::cout << "The smallest element is " << *std::min_element(vec1.begin(),vec1.end()) << '\n';

}


void largest(vector<int> &vec1)
{
      std::cout << "The largest element is " << *std::max_element(vec1.begin(),vec1.end()) << '\n';

}
