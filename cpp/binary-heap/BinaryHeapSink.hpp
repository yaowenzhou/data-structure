/*
 * @Author       : yaowenzhou
 * @Date         : 2021-01-15 14:01:24
 * @LastEditors  : yaowenzhou
 * @LastEditTime : 2021-01-15 19:52:27
 * @version      :
 * @Description  : 二叉堆的下沉操作
 */
#ifndef __BINARY_HEAP_SINK__
#define __BINARY_HEAP_SINK__

// T 可以是一个数组或者支持 []操作符的其它类型数据结构
/**
 * @description: 二叉堆的下沉操作
 * @param { 
 *    arr:  要执行下沉操作的容器，也可以是支持[]操作符的容器
 *          容器的元素必须支持 比较运算符
 *    index:需要执行下沉操作的元素的索引
 *    len:  容器大小
 *    flag: 下沉标志，true表示值更大的元素下沉(小顶堆，默认值)
 *      &emsp;&emsp;&emsp;false表示值更小的元素下沉(大顶堆)
 * }
 * @return 原容器(下沉后)
 */
template <class T>
T& sinkDown(T& arr, int index, int len, bool flag = true) {
  // 保存需要下沉的值
  auto tmp = arr[index];
  // 定位左子节点的位置
  int child = 2 * index + 1;
  // 开始下沉
  while (child < len) {
    // 小顶堆需要将左右子节点中更小的节点上浮
    // 因此当左子节点比右子节点更大时，定位到右子节点
    // 大顶堆需要将左右子节点中更大的节点上浮
    // 因此当左子节点大于右子节点时，不需要定位到右子节点
    // 此处的异或运算符:
    // (arr[child] < arr[child + 1]) ^ true(小顶堆)
    // 左子节点 < 右子节点时，整个表达式返回假，不需要定位到右子节点
    // 左子节点 >= 右子节点时，整个表达式返回真，需要定位到右子节点
    // 更小的节点变成父节点
    // (arr[child] < arr[child + 1]) ^ false(大顶堆)
    // 左子节点 < 右子节点时，整个表达式返回真，需要定位到右子节点
    // 左子节点 >= 右子节点时，整个表达式返回假，不需要定位到右子节点
    // 更大的节点变成父节点
    if (child + 1 < len && ((arr[child] < arr[child + 1]) ^ flag)) {
      child++;
    }

    // 小顶堆: 如果父节点比子节点小或者等于子节点，则下沉结束
    // 大顶堆: 如果父节点比子节点大或者等于子节点，则下沉结束
    // 综合起来
    if (tmp == arr[child]) break;
    if (flag ^ (tmp > arr[child])) break;
    // 当前节点和其子节点交换
    arr[index] = arr[child];
    /* 循环过程中可以暂时只考虑将子节点上浮
    直到最后再将需要下沉的节点放到正确位置
    因此此语句可以省略，放到最后再执行 */
    // arr[child] = tmp;
    // 子节点作为当前节点
    index = child;
    // 更新当前节点的左子节点
    child = child * 2 + 1;
  }
  arr[index] = tmp;
  return arr;
}

#endif