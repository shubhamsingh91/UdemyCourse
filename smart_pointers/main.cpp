#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Test {

private:
  int data;

public:
  Test() : data{0} { cout << "Test constructor (" << data << "}" << endl; }
  Test(int data) : data{data} {
    cout << "Test constructor (" << data << "}" << endl;
  }
  int get_data() const { return data; }
  ~Test() { cout << "Test Destructor!" << endl; }
};

std::unique_ptr<std::vector<std::shared_ptr<Test>>> make() {
  std::unique_ptr<std::vector<std::shared_ptr<Test>>> ptr{
      new std::vector<std::shared_ptr<Test>>()};

  return ptr;
};

void fill(std::vector<std::shared_ptr<Test>> &vec, int num) {
  int num_enter;

  for (int ii = 0; ii < num; ii++) {
    cout << "Enter the number: ";
    cin >> num_enter;
    vec.push_back(std::shared_ptr<Test>{new Test(num_enter)});
  }
}
void display(const std::vector<std::shared_ptr<Test>> &vec) {
  cout << "---------------------------------" << endl;
  cout << "The data points are: \n";

  for (int i = 0; i < vec.size(); i++) {
    cout << vec[i]->get_data() << endl;
  }
  cout << "---------------------------------" << endl;
}

int main() {

  std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
  vec_ptr = make();
  cout << "How many data points do you want to enter? ";
  int num;
  cin >> num;
  fill(*vec_ptr, num);
  display(*vec_ptr);

  return 0;
}