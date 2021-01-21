/*
 * @Author       : yaowenzhou
 * @Date         : 2021-01-17 16:39:31
 * @LastEditors  : yaowenzhou
 * @LastEditTime : 2021-01-17 19:52:20
 * @version      :
 * @Description  :
 */
#ifndef __XY_RED_BLACK_TREE__
#define __XY_RED_BLACK_TREE__

#include <exception>
#include <stack>

namespace xy_red_black_tree {
template <typename T>
class RBTreeNode {
 private:
  T _value;
  // true is black, false is red;
  bool _color;
  RBTreeNode<T>* _lChild;
  RBTreeNode<T>* _rChild;

 public:
  RBTreeNode() : _value{};
  RBTreeNode(const T& value, const bool color = false,
             const RBTreeNode<T> const* lChild = nullptr,
             const RBTreeNode<T> const* rChild = nullptr)
      : _value(value), _color(color), _lChild(lChild), _rChild(rChild){};
  ~RBTreeNode() {}
  const T& value() { return _value; }
  void setValue(const T& value) { _value = value; }
  const RBTreeNode<T>& lChild() { return *_lChild; }
  void setLChild(const RBTreeNode<T> const* lChild) { _lChild = lChild; }
  const RBTreeNode<T>& rChild() { return *_rChild; }
  void setRChild(const RBTreeNode<T> const* rChild) { _rChild = rChild; }
};

#define PTR_POOL_PTR_ARRAY_SIZE 128
template <typename T>
class RBTree {
 private:
  RBTreeNode<T>* _root = nullptr;
  // 保存闲置的RBTreeNode指针
  std::stack<RBTreeNode<T>*> ptrPool;
  // 用于保存RBTreeNode内存池每次申请的RBTreeNode数组首地址
  RBTreeNode<T>* _arr;
  int _size = 0;
  int _maxSize = 0;

 public:
  RBTree()
      : _root(nullptr),
        ptrPool(std::stack<RBTreeNode<T>*>()),
        _size(0),
        _maxSize(0) {
    for (int i = 0; i < PTR_POOL_PTR_ARRAY_SIZE; i++) {
      _arr[i] = nullptr;
    }
  };
  ~RBTree() {
    // 1. 释放内存池
    for (int i = 0; i < PTR_POOL_PTR_ARRAY_SIZE; i++) {
      if (_arr[i] != nullptr) delete[] _arr[i];
    }
    // 2. 将 _root 置空
    _root = nullptr;
    // 3. 将 _arr置空
    _arr = nullptr;
  }
  bool isEmpty() { return _size == 0; }
  // 向红黑树中添加元素
  void realAdd(RBTreeNode<T> const* node) {
    // 默认新节点是红色
    node->_color = false;
    /*TODO:*/
    // 1. 新节点位于根
    if (_size == 0) {
      _root == node;
      node->_color = true;
      node->_lChild = nullptr;
      node->_rChild = nullptr;
    }
    // 2. 新节点
    // 向红黑树中添加完数据后，还需要将size + 1
  }
  void add(const T& value) {
    // 1. 首先检查内存池ptrPool中是否有闲置内存
    // 1.1 如果有闲置内存，则直接ptrPool直接弹出一块内存用于添加数据
    // 1.2 如果没有闲置内存，则需要新申请内存
    if (ptrPool.size() != 0) {
      RBTreeNode<T>* node = ptrPool.pop();
      node->setValue = value;
      return;
    }
    // 内存池中无闲置内存
    for (int i = 0; i < PTR_POOL_PTR_ARRAY_SIZE; i++) {
      if (_arr[i] == nullptr) {
        int newNums = 0;
        RBTreeNode<T>* start = nullptr;
        if (i >= 11) {
          newNums = 2 << 14;
        } else {
          newNums = 2 << (i + 3)
        }
        // 动态分配内存
        start = new RBTreeNode<T>[newNums];
        // 将新分配到的内存的首地址存储 _arr中
        _arr[i] = start;
        // 增加 _maxSize
        _maxSize += newNums;
        // 将新分配到的内存作为闲置内存压如栈中
        for (int i = 0; i < newNums; i++) {
          ptrPool.push(start + i);
        }
        // 从内存池中弹出闲置内存用于添加数据
        RBTreeNode<T>* node = ptrPool.pop();
        node->setValue = value;
        return;
      }
    }
    // 循环内部如果分配到了内存，会进行后续操作并退出
    // 如果没有在循环内部退出，说明超出了最大容量，此处抛出异常
    throw out_of_range(
        "Out of xy_red_black_tree::RBTree supports maximum capacity");
  }

  int size() { return _size; }
  int maxSize() { return _maxSize; }
  const RBTreeNode<T>* const findValue() {
    // TODO:
  }
  // 红黑树一般不包括改操作，只需要删除某个数据然后再添加即可
  // void setValue() {}
  void remove(const T& value) {
    // TODO:
    // 1. 找到目标值
    // 2. 删除该目标值
    // 3. 将删除的数据压入内存池中
  }
};
}  // namespace xy_red_black_tree

#endif