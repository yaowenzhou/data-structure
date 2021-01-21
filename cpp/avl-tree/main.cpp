/*
 * @Author       : yaowenzhou
 * @Date         : 2021-01-17 19:57:03
 * @LastEditors  : yaowenzhou
 * @LastEditTime : 2021-01-18 08:39:35
 * @version      :
 * @Description  :
 */
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class A {
 public:
  int i;
  A(int _i) : i(_i) {}
};
class B {
 public:
  A a;
  B(const A& _a) : a(a){};
  void test() {
    static int a = 10;
    cout << ++a << endl;
  }
};

int main(int argc, char const* argv[]) {
  // A a(10);
  // B b1(a);
  // B b2(a);
  // cout << "b1.test()" << endl;
  // b1.test();
  // b1.test();
  // b1.test();
  // cout << endl;

  // cout << "b2.test() --> ";
  // b2.test();
  int* arr[4] = {nullptr};
  for (int i = 0; i < 4; i++) {
    cout << arr[i] << endl;
    // if (arr[i] == nullptr) {
    //   cout << "true" << endl;
    // } else {
    //   cout << "false" << endl;
    // }
  }

  // srand((int)time(nullptr));
  // for (int i = 0; i < 32; i++) {
  //   cout << rand() % 100 << " ";
  // }
  return 0;
}
