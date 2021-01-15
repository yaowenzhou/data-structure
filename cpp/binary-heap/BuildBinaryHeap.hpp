/*
 * @Author       : yaowenzhou
 * @Date         : 2021-01-15 15:31:25
 * @LastEditors  : yaowenzhou
 * @LastEditTime : 2021-01-15 19:53:01
 * @version      :
 * @Description  : 构建二叉堆
 */
#ifndef __CREATE_BINARY_HEAP__
#define __CREATE_BINARY_HEAP__

#include "BinaryHeapSink.hpp"
// T 可以是一个数组或者支持 []操作符的其它类型数据结构
/**
 * @description: 创建堆
 * @param {
 *  arr: 需要构建二叉堆的容器，可以使数组，也可以是支持[]操作符的容器
 *        容器的元素必须支持 比较运算符
 *  len: 容器的大小
 *  flag: 创建二叉堆的标志，true表示创建小顶堆，false表示创建大顶堆
 * }
 * @return {原容器(已构建成堆)}
 */
template <class T>
T& buildBinaryHeap(T& arr, int len, bool flag = true) {
  // 从非叶子节点开始下沉
  // 索引最大的节点为len-1
  // 设其对应的父节点的索引为x
  // 则 (x * 2) + 1 = len - 1 (左子节点) || (x * 2) + 2 = len - 1(右子节点)
  for (int i = (len - 2) / 2; i >= 0; i--) {
    sinkDown(arr, i, len, flag);
  }
  return arr;
}

#endif