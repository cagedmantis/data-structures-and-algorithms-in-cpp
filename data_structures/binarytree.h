#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

#include "btnode.h"

using namespace std;


template <class dataType>
class BinaryTree
{
public:
  BinaryTree();
  BinaryTree(dataType);
  virtual ~BinaryTree();
  bool insert(dataType);
  //bool remove(dataType);
  //bool find(dataType);
  //BTnode<dataType> * find(dataType);
  void preorder();
  void inorder();
  void postorder();
  BTnode<dataType> *tree;
private:
  void deleteTree(BTnode<dataType> *);
  bool insert(dataType, BTnode<dataType>*);
  void preorder(BTnode<dataType> *);
  void inorder(BTnode<dataType> *);
  void postorder(BTnode<dataType> *);
};


#endif /* _BINARYTREE_H_ */
