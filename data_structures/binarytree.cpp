#include "binarytree.h"
#include <iostream>

using namespace std;


template<class dataType>
BinaryTree<dataType>::BinaryTree() {
  *tree = NULL;
}

template<class dataType>
BinaryTree<dataType>::BinaryTree(dataType init_data) {
  tree = new BTnode<dataType>(init_data);
}

template<class dataType>
BinaryTree<dataType>::~BinaryTree() {
  cout << "remove everything" << endl;
  deleteTree(tree);
}

template<class dataType>
void BinaryTree<dataType>::deleteTree(BTnode<dataType> *node) {
  if (node == NULL) {
    cout << "null node" << endl;
    //delete node;
  }
  else {
    if (node->left != NULL)
      deleteTree(node->left);
    if (node->right != NULL)
      deleteTree(node->right);
    delete node;
  }
}


template<class dataType>
bool BinaryTree<dataType>::insert(dataType new_data) {
  if (tree->data == NULL) {
    //tree->data = new BTnode<dataType>(new_data);
    tree->data = new_data;
    return true;
  }
  if (tree->data > new_data) {
    if (tree->left != NULL) {
      insert(new_data, tree->left);
    } else {
      tree->left = new BTnode<dataType>(new_data);
      return true;
    }
  } else {
    if (tree->right != NULL) { 
      insert(new_data, tree->right);
    } else {
      tree->right = new BTnode<dataType>(new_data);
      return true;
    }
  }
  return false;
}

template<class dataType>
bool BinaryTree<dataType>::insert(dataType new_data, BTnode<dataType> * node) {
  if (node == NULL) {
    node = new BTnode<dataType>(new_data);
    return true;
  }
  /*
  if (node->data == NULL) {
    //node->data = new BTnode<dataType>(new_data);
    node->data = new_data;
    return true;
    } */
  if (node->data > new_data) {
    if (node->left != NULL) {
      insert(new_data, node->left);
    } else {
      node->left = new BTnode<dataType>(new_data);
      return true;
    }
  } else {
    if (node->right != NULL) { 
      insert(new_data, node->right);
    } else {
      node->right = new BTnode<dataType>(new_data);
      return true;
    }
  }
  return false;
}


template<class dataType>
void BinaryTree<dataType>::inorder() {
  inorder(tree);
}

template<class dataType>
void BinaryTree<dataType>::inorder(BTnode<dataType> *tree) {
  if (tree->left != NULL)
    inorder(tree->left);
  if (tree->data != -1) 
    cout << tree->data << " ";
  if (tree->right != NULL)
    inorder(tree->right);
}

template<class dataType>
void BinaryTree<dataType>::preorder() {
  preorder(tree);
}

template<class dataType>
void BinaryTree<dataType>::preorder(BTnode<dataType> *tree) {
  cout << tree->data << " ";
  if (tree->data != -1) 
    cout << tree->data << " ";
  if (tree->right != NULL)
    inorder(tree->right);
}


/*
bool find(int value, node *tree) {
  if (tree->data == value)
    return true;
  if (tree->data > value) {
    if (tree->left != NULL)
      return find(value, tree->left);
  } else {
    if (tree->right != NULL)
      return find(value, tree->right);
  }
  return false;
}
*/  

