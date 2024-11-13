#include <iostream>
#include "../utils.h"

class Average {

 private:
  std::int32_t sum;
  std::int8_t cnt;
  std::int32_t avg;

 public:
  Average(): sum{0},cnt{0},avg{0}{};
  Average(Average &obj) {
    if (this != &obj) {
        sum = obj.sum;
        cnt = obj.cnt;
        avg = obj.avg;
    }
  }
  Average& operator+=(const int &a) {
    this->sum += a;
    this->cnt++;
    return *this;
  }

  friend std::ostream & operator<<(std::ostream &out, const Average &obj);
  ~Average(){}; 

};

 std::ostream & operator<<(std::ostream &out, const Average &obj){

    out << static_cast<float>(static_cast<float>(obj.sum)/static_cast<float>(obj.cnt));
    return out;
 }


int main(){
	Average avg{};

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';



    return 0;
}