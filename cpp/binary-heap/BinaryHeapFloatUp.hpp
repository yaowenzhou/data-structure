/*
 * @Author       : yaowenzhou
 * @Date         : 2021-01-15 19:16:42
 * @LastEditors  : yaowenzhou
 * @LastEditTime : 2021-01-15 19:52:43
 * @version      :
 * @Description  : 二叉堆的上浮操作
 */
#ifndef __BINARY_HEAP_FLOAT_UP__
#define __BINARY_HEAP_FLOAT_UP__
// T 可以是一个数组或者支持 []操作符的其它类型数据结构
/**
 * @description: 用于在二叉堆插入数据后进行上浮操作，以维护二叉堆
 * @param {
 *  arr:    要执行上浮操作的容器，也可以是支持[]操作符的容器
 *          容器的元素必须支持 比较运算符
 *  len:    容器大小
 *  flag:   上浮标志，true表示该二叉堆是小顶堆，false表示该二叉堆是大顶堆
 * }
 * @return {原容器(调整后)}
 */
template <class T>
T& floatUp(T& arr, int len, bool flag = true) {
  // 最后一个节点(刚插入的节点，需要调整的节点)
  int child = len - 1;
  //  最后一个节点的值
  auto tmp = arr[child];
  // 最后一个节点的父节点
  int parent = (child - 1) / 2;
  //  如果最后一个节点和其父节点的值相同，则直接返回
  if (arr[child] == arr[parent]) {
    return arr;
  }
  //  开始上浮
  // flag 为true，小顶堆
  // flag 为false，大顶堆
  while (child > 0 && (flag ^ (arr[parent] > tmp))) {
    // 父节点的值保存到子节点中
    arr[child] = arr[parent];
    // 将父节点的索引作为新的子节点记录下来
    child = parent;
    // parent 保存新的父节点的索引
    parent = (child - 1) / 2;
  }
  // 退出循环表示找到了正确的位置
  arr[child] = tmp;
  return arr;
}

#endif