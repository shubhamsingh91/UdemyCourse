#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    int n_arr;
    int n_quer;
    
    cin >> n_arr;
    cin >> n_quer;

  //  cout << "n_arr is" << n_arr<<endl;
   // cout << "n_quer is" << n_quer <<endl;
    
    vector <vector <int> > vec1 (n_arr);

    for (int ii=0; ii<n_arr; ii++)
    {
        int size_vec;

      cin >> size_vec;
     // cout << "size_vec is" << size_vec <<endl;

        for (int jj=0; jj<size_vec; jj++)
        {
            int num1;
            cin >> num1;
            vec1[ii].push_back(num1);
        }


    }

   // cout <<  "Beginning queries now!" << endl;

       vector<int> numi_vec,numj_vec;
       int numi,numj;

    for (int ii=0; ii<n_quer; ii++)
    {
        cin >> numi;
        cin >> numj;

        numi_vec.push_back(numi);
        numj_vec.push_back(numj);
    }

    for (int kk=0; kk<n_quer; kk++)
    {
        cout << vec1[numi_vec[kk]][numj_vec[kk]] << endl;

    }

    return 0;
}