/*
 * @Author       : yaowenzhou
 * @Date         : 2021-01-15 19:38:21
 * @LastEditors  : yaowenzhou
 * @LastEditTime : 2021-01-15 20:06:59
 * @version      :
 * @Description  :
 */
#ifndef __BINARY_HEAP_SORT__
#define __BINARY_HEAP_SORT__
#include "BinaryHeapFloatUp.hpp"
#include "BinaryHeapSink.hpp"
#include "buildBinaryHeap.hpp"

/**
 * @description: 堆排序
 * @param {
 *  arr:    要执行下沉操作的容器，也可以是支持[]操作符的容器
 *          容器的元素必须支持 比较运算符
 *  len:    容器大小
 *  flag:   排序标志，true表示倒序，false表示正序
 * }
 * @return {*}
 */
template <class T>
T& heapSort(T& arr, int len, bool flag = false) {
  buildBinaryHeap(arr, len, flag);
  auto tmp = arr[0];
  // 进行堆排序
  for (int i = len - 1; i > 0; i--) {
    // 1. 把堆顶的元素和堆的最后一个元素交换
    tmp = arr[i];
    arr[i] = arr[0];
    arr[0] = tmp;
    // 2. 堆顶元素下沉
    sinkDown(arr, 0, i, flag);
  }
  return arr;
}

#endif
