/*
 * @Author       : yaowenzhou
 * @Date         : 2021-01-17 16:47:03
 * @LastEditors  : yaowenzhou
 * @LastEditTime : 2021-01-17 18:35:44
 * @version      :
 * @Description  :
 */
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const* argv[]) {
  int num = 5;
  int* ptr = &num;
  cout << ptr << " " << ++ptr << endl;
  return 0;
}
