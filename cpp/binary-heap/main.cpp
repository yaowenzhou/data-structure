/*
 * @Author       : yaowenzhou
 * @Date         : 2021-01-15 15:48:05
 * @LastEditors  : yaowenzhou
 * @LastEditTime : 2021-01-15 20:00:31
 * @version      :
 * @Description  :
 */
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "BuildBinaryHeap.hpp"
#include "BinaryHeapSink.hpp"
#include "BinaryHeapSort.hpp"

using namespace std;
int main(int argc, char const *argv[]) {
  vector<int> vec;
  srand((int)time(0));
  for (int i = 0; i < 10; i++) {
    vec.push_back(rand() % 100);
  }
  for (size_t i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
  heapSort(vec, vec.size(), true);
  for (size_t i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << endl;
  heapSort(vec, vec.size(), false);
  for (size_t i = 0; i < vec.size(); i++) {
    cout << vec[i] << " ";
  }
  cout << endl;

  return 0;
}
/*
 */