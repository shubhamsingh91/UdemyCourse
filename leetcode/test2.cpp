
#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<deque>

using namespace std;
class Solution {
public:
    int lengthLongestPath(string input) {
        deque<int> dq;
        int len = 0, res = 0, level = 0;
        bool file = false;
        for(char c: input){
            cout << c << endl;
            if(c == '\n'){
                cout << "n here" << endl;
                cout << len << endl;
                dq.push_back(len);
                level = len = file = 0;
                cout << " level = " << level << endl;
            }
            else if(c == '\t'){ ++level;
            cout << "t here, level = " << level << endl;}
            else if(c == '.') {++len, file = true;
             cout << "file here, len = " << len <<  " level = " << level<<endl;
            }
            else{
                ++len;
                 cout << "len = " << len <<  " level = " << level<<endl;
               
                if(file) res = max(res, len + accumulate(dq.begin(), dq.end(), 0) + level);
                while(level < dq.size()){
                    dq.pop_back();
                    cout << "popping dq" << endl;
                }
            }
        }        
        return res;
    }
};

int main()
{

    string input = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    Solution sol;
    cout << sol.lengthLongestPath(input) << endl;

 


    return 0;
}