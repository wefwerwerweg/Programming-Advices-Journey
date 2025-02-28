// https://programmingadvices.com/courses/1936515/lectures/44025441/comments/25922385

#include <iostream>
#include <string>

class Calculator {
 public:
  void add(int num) {
    result_ += num;
    lastOperation_ = "adding " + std::to_string(num);
  }

  void subtract(int num) {
    result_ -= num;
    lastOperation_ = "subtracting " + std::to_string(num);
  }

  void multiply(int num) {
    result_ *= num;
    lastOperation_ = "multiplying by " + std::to_string(num);
  }

  void divide(int num) {
    if (num == 0) num = 1;
    result_ /= num;
    lastOperation_ = "dividing by " + std::to_string(num);
  }

  void clear() {
    result_ = 0;
    lastOperation_ = "clearing";
  }

  void printResult() {
    printf("Final result after %s is: %d\n", lastOperation_.c_str(), result_);
  }

  int result() { return result_; }

 private:
  int result_ = 0;
  std::string lastOperation_ = "clearing";
};

int main() {
  Calculator calculator;
  calculator.clear();      // 0
  calculator.add(10);      // 10
  calculator.subtract(2);  // 8
  calculator.multiply(3);  // 24
  calculator.divide(4);    // 6
  calculator.printResult();
  return 0;
}
