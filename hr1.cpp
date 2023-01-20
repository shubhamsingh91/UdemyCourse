#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

long getTriangleArea(vector<int> x, vector<int> y) {
 
 long int area;
 
 
 
 return area;
}

int main()
{
    
    vector<int> vecx {0,0,99999};
    vector<int> vecy {0,99998,99999};
    vector<int> vec_index;
    int hcord;
    long base;
    long height;
    long area;

    int xory; // 0 for 2 x as 0, 1 for 2 y as 0


//     for (int ii=0;ii<3;ii++)
//     {
//     for (int jj=ii;jj<3;jj++)
//         {
//             if (vecx[ii]==vecx[jj])
//             {
//                 vec_index.push_back(ii);
//                 xory = 0; // x as 0
//                 cout << "its x" << endl;
//             }
//         }
//     }

//      if(vec_index.size()!=2) // if x is not it
//          {  cout << "x is not it" << endl;
//         vec_index.clear();
//            for (int ii=0;ii<3;ii++)
//            {  
//              if (vecy[ii]==0) { 
//             vec_index.push_back(ii);
//               xory = 1; // y as 0 
//              }
//            }

//          }
//     cout << "xory = "<<xory << endl;
//     cout << vec_index[0] << endl;
//     cout << vec_index[1] << endl;
//    cout << "--------------" << endl;
// // check the height coordinate
//  for (int ii=0; ii<3;ii++)
//  {
//   if((  std::count(vec_index.begin(), vec_index.end(), ii))==0)
//   {
//       hcord = ii;
//   }

//  }
//  cout << "hcord = " << hcord << endl;

//     if (xory==0) // x as 0, base y
//     {
//             base = abs(vecy[vec_index[0]]-vecy[vec_index[1]]);
//             height = vecx[hcord];

//     }else if(xory==1) // y as 0, base x
//     {
//              base = abs(vecx[vec_index[0]]-vecx[vec_index[1]]);
//             height = vecy[hcord];

//     } else{
//         cout << "xory is none!" << endl;
//     }
   
//     cout << "base = " << base <<endl;
//     cout << "heght = " << height <<endl;

//     area = base*height*0.5;

//     cout << "area = " << area <<endl;

    


   area=0.5*abs( ((vecx[0]*(vecy[1]-vecy[2])) + 
   (vecx[1]*(vecy[2]-vecy[0])) + (vecx[2]*(vecy[0]-vecy[1]))));
    cout << "area = " << area <<endl;

  return 0;

}