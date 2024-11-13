#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'flippingMatrix' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY matrix as parameter.
 */
void print_mat (vector<vector<int>> matrix) {
  for (int i = 0; i< matrix.size(); i++) {
    for (int j = 0; j< matrix.size(); j++) {
        std::cout << matrix[i][j] << ", ";
    }
    std::cout << endl;
  }
}

void reverse_col (vector<vector<int>> matrix, const int j) {
    
    int n = matrix.size();
    
    for (int i = 0; i < (n/2); i++) {
        int temp = matrix[i][j];
        matrix[n-(i+1)][j] = temp;
    }
}

void reverse_row (vector<vector<int>> matrix, const int j)  {
    int n = matrix.size();
    
    for (int i = 0; i < (n/2); i++) {
        int temp = matrix[j][i];
        matrix[j][n-(i+1)] = temp;
    }
}

int flippingMatrix(vector<vector<int>> matrix) {
    
    int sum_first {0};
    int sum_sec {0};
    int two_n = matrix.size();
    int n = two_n/2;
    
    // vector <vector <int>> submat;
    // submat.resize(n);
    // submat[0].resize(n);
    int sum_final {0};

    // reverse all cols if needed
    for (int i = 0; i < two_n; i++){ // all cols
        sum_first = sum_sec = 0;
        for (int j = 0; j < n; j++) { // rows 1-n
            sum_first += matrix[j][i];
        }
        for (int j = n; j<two_n; j++) { // rows n-2n
            sum_sec +=matrix[j][i];
        }
        
        if (sum_sec > sum_first) {
            reverse_col(matrix, i);
        }
        
    }

    print_mat(matrix);

    // reverse first n rows if needed
    for (int  i = 0; i < n; i++) { // rows 1-n
        sum_first = sum_sec = 0;
        for (int j = 0; j < n; j++) { // cols 1-n
            sum_first += matrix[i][j];
        }
        for (int j = n; j < two_n; j++) { // cols n-2n
            sum_sec += matrix[i][j];
        }        

        if (sum_sec > sum_first) {
            reverse_row(matrix, i);
        }
    }
    print_mat(matrix);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum_final+= matrix[i][j];
        }
    }
    return sum_final;


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<int>> matrix(2 * n);

        for (int i = 0; i < 2 * n; i++) {
            matrix[i].resize(2 * n);

            string matrix_row_temp_temp;
            getline(cin, matrix_row_temp_temp);

            vector<string> matrix_row_temp = split(rtrim(matrix_row_temp_temp));

            for (int j = 0; j < 2 * n; j++) {
                int matrix_row_item = stoi(matrix_row_temp[j]);

                matrix[i][j] = matrix_row_item;
            }
        }

        int result = flippingMatrix(matrix);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
