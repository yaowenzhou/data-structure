/*
 * @Author       : yaowenzhou
 * @Date         : 2021-01-17 19:57:25
 * @LastEditors  : yaowenzhou
 * @LastEditTime : 2021-01-18 16:28:02
 * @version      :
 * @Description  :
 */
#ifndef __XY_AVL_TREE__
#define __XY_AVL_TREE__

#include <cstring>

namespace xy_avl_tree {
template <typename T>
class AVLTree {
 private:
  class Node {
   public:
    T _value;
    Node* _left;
    Node* _right;
    int _height;
    Node() : _left(nullptr), _right(nullptr), _height(1){};
    Node(const T& value)
        : _value(value), _left(nullptr), _right(nullptr), _height(1){};
  };

 public:
  Node* _root = nullptr;
  int _size = 0;
  AVLTree(){};
  ~AVLTree() {
    // TODO: 注意释放资源
  }

 private:
  // 获取某一节点的高度
  int getHeight(Node const* node) {
    if (node == nullptr) return 0;
    return node->_height;
  }
  int size() { return _size; }
  bool isEmpty() { return size == 0; }
  // 获取某个节点的平衡因子
  int getBalanceFactor(Node const* node) {
    if (node == nullptr) {
      return 0;
    }
    return getHeight(node->_left) - getHeight(node->_height);
  }
  // 判断树是否为平衡二叉树
  bool isBalanced(Node const* node = _root) {
    if (node == nullptr) {
      return true;
    }
    int fac = getBalanceFactor(node);
    if (fac < -1 || fac > 1) return false;
    return isBalanced(node->_left) && isBalanced(node->_right);
  }
  // 调整avl-tree，使得其符合avl-tree的要求
  // 插入操作中，失衡节点失衡的原因是其子树高度增加了1，要想办法让该子树高度-1即可
  // 定义四个方法用于调整val-tree
  // node为失衡节点，parent为失衡节点的父节点
  void adjustLL(Node const* node, Node const* parent) {
    // 失衡节点必定存在左子节点
    Node* left = node->_left;
    // 父节点为空表示失衡节点即为root节点
    // 此时
    // 失衡节点称为其子节点的右子节点
    left->_right = node;

    //
  }
  void adjustLR(Node const* node, Node const* parent) {}
  void adjustRL(Node const* node, Node const* parent) {}
  void adjustRR(Node const* node, Node const* parent) {}

  // 插入操作，对于复杂的数据类型有可能执行的是替换操作，因此需要将旧的节点返回
  Node* realInsert(Node const* newNode) {
    // 如果当前size为0，则直接将新节点设置为根节点并返回nullptr
    if (_size == 0) {
      _root = newNode;
      _root->_height = 1;
      return nullptr;
    }
    // 1. 定义一个数组用于保存从 root 到目标节点的路径
    // 设avl-tree的规模为sum，层数为k，则sum和k的关系大致可以描述为 2 的 k 次幂
    // 本类中使用 int 保存avl-tree的size，而int类型的最大值为 2的32次幂
    // 因此将此数组设置为32个元素已经足够
    Node* path[32] = {nullptr};
    // 为了跨平台，全部手动初始化为nullptr
    memset(path, 0, sizeof(path));
    Node* node = _root;
    int i = 0;
    // 此变量表示新节点插入到node的左边还是右边
    bool isLeft = true;
    while (node != nullptr) {
      path[i] = node;
      // 如果找到了，则用新节点取代旧节点
      // 并直接返回
      if (newNode->_value == node->_value) {
        // 1. 如果取代的是根节点，则需要将根节点替换为新节点
        if (node == _root) {
          _root = newNode;
        }
        // 2. 如果取代的不是根节点，则还需要额外进行一步父节点的替换
        else {
          Node* father = path[i - 1];
          if (father->_left == node) {
            father->_left == newNode;
          } else {
            father->_right == newNode;
          }
        }
        // 将原来的节点的左右子节点分别赋值给新节点
        newNode->_left = node->_left;
        newNode->_right = node->_right;
        // 更新新节点的height
        newNode->_height = node->_height;
        // 返回旧节点
        return node;
      }
      // 如果newNode->_value > node->_value，则插入到node的右边
      if (newNode->_value > node->_value) {
        node = node->right;
        isLeft = false;
      }
      // 否则插入到node的左边
      else {
        node = node->left;
        isLeft = true;
      }
      // 下次循环之前需要将 i +1
      i++;
    }
    if (isLeft) {
      node->_left = newNode;
    } else {
      node->_right = newNode;
    }
    newNode->_left = nullptr;
    newNode->_right = nullptr;
    newNode->_height = 1;
    Node* parent = path[i - 1];
    // 如果新插入节点的父节点原本就存在一个子节点，则可以不用更新树，直接返回即可
    if (parent->_left != nullptr && parent->_right != nullptr) {
      return;
    }
    // 插入后可能不再符合avl-tree的要求需要调整avl-tree
    // 回溯path，找到距离插入节点最近的失衡节点
    // 一共有三个子节点需要关注:
    // 失衡节点、失衡节点的的左子节点、失衡节点的右子节点
    
  }

  Node* realRemove(const T& value) {
    // 对avl-tree的删除操作
  }

 public:
  // 查询操作
  bool contains(T& value) {
    // 找到该值返回true，否则返回false
    Node* node = _root;
    while (node != nullptr) {
      if (node->_value == value) {
        return true;
      } else if (node->_value < value) {
        node = node->_left;
      } else {
        node = node->_right;
      }
    }
    // 退出循环说明avl-tree中没有存储该值
    return false;
  }
  void insert(T& value) {
    // 构建一个新的节点并调用realInsert()
    // TODO: 后期改造成内存池的操作
    Node* node = new Node(value);
    // 对于复杂数据类型，有可能执行的是替换操作，因此需要将旧节点进行回收
    Node* oldNode = realInsert(node);
    // 如果返回的旧节点不为nullptr，则需要delete
    // TODO: 内存池需要将其回收到内存池。
    if (oldNode != nullptr) {
      delete oldNode;
    }
  }

  // 删除操作
  T remove(T& value) {
    // TODO: 使用内存池时注意内存回收，暂且直接销毁内存
  }
};
}  // namespace xy_avl_tree
#endif