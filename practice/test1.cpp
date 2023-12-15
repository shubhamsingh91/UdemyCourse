#include <iostream>
#include <stdio.h>

using namespace std;
extern int num = 45;

int main() {

  wchar_t c1 = 'x';
  cout << sizeof(c1) << endl; // size is 4 bytes
  int i = 0;
  do {
    cout << "i=" << i << endl;
    i++;

  } while (i < 4);

  cout << num + 1 << endl;
  i = 0;
label:
  cout << "test1" << endl;
  i++;
  cout << "under label" << endl;
  cout << "this is also executed" << endl;
  if (i < 3) {
    goto label;
  }
}