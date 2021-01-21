/*
 * @Author       : yaowenzhou
 * @Date         : 2021-01-17 15:20:08
 * @LastEditors  : yaowenzhou
 * @LastEditTime : 2021-01-17 16:18:23
 * @version      :
 * @Description  :
 */
#ifndef __XY_BINARY_SEARCH_TREE__
#define __XY_BINARY_SEARCH_TREE__
namespace xy_binary_search_tree {
// 二叉搜索树的节点
template <class T>
class BSTreeNode {
 private:
  T _value;
  BSTreeNode<T> _lChild = nullptr;
  BSTreeNode<T> _rChild = nullptr;

 private:
  BSTreeNode(T value) : _value(value){};
  ~BSTreeNode();

 private:
  const T& value();
  void setValue(T val);
  BSTreeNode<T>& lChild();
  void setLChild(BSTreeNode<T>& lChild);
  BSTreeNode<T>& rChild();
  void setRChild(BSTreeNode<T>& rChild);
};

// template <class T>
// class BinarySearchTree {
//  private:
//   BinarySearchTreeNode<T> root = nullptr;
// };
}  // namespace xy_binary_search_tree

#endif