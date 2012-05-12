#include <iostream>

using namespace std;

// Add mutex: readlock, writelock

template <class dataType>
class BTnode
{
public:
  BTnode();
  BTnode(dataType);
  virtual ~BTnode();
  dataType data;
  BTnode *left;
  BTnode *right;
};

template <class dataType>
BTnode<dataType>::BTnode() {
  left = NULL;
  right = NULL;
  data = NULL;
}

template <class dataType>
BTnode<dataType>::BTnode(dataType newData) {
  left = NULL;
  right = NULL;
  data = newData;
}

template <class dataType>
BTnode<dataType>::~BTnode() {
  cout << "removing node: " << data << endl;
  //delete left;
  //delete right;
}

// **************************************************


template <class dataType>
class BinaryTree
{
public:
  BinaryTree();
  BinaryTree(dataType);
  virtual ~BinaryTree();
  bool insert(dataType);
  void preorder();
  void inorder();
  void postorder();
  int size();
  //void printTree();
  dataType min();
  void remove(dataType);
  
  //bool remove(dataType);
  //bool find(dataType);
  //BTnode<dataType> * find(dataType);

  //maxDepth()
  //minValue()
  //maxValue()
  //sameTree() are they mirror copies of each other?
  //treeToList() convert a tree into a circular linked list
  //http://cslibrary.stanford.edu/109/TreeListRecursion.html

private:
  BTnode<dataType> *tree;
  void deleteTree(BTnode<dataType> *);
  bool insert(dataType, BTnode<dataType>*);
  void preorder(BTnode<dataType> *);
  void inorder(BTnode<dataType> *);
  void postorder(BTnode<dataType> *);
  int size(BTnode<dataType> *);
  //void printTree(BTnode<dataType> *);
  dataType min(BTnode<dataType> *);
  BTnode<dataType>* find(BTnode<dataType> *, dataType);
  void deleteNode(BTnode<dataType> *);
  //  BTnode<dataType>* find(BTnode<dataType> *, dataType)
};

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
bool BinaryTree<dataType>::insert(dataType new_data) {
  if (tree == NULL) {
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
void BinaryTree<dataType>::postorder() {
  postorder(tree);
}

template<class dataType>
void BinaryTree<dataType>::postorder(BTnode<dataType> *tree) {
  if (tree->left != NULL)
    postorder(tree->left);
  if (tree->right != NULL)
    postorder(tree->right);
  if (tree->data != -1) 
    cout << tree->data << " ";
}

template<class dataType>
int BinaryTree<dataType>::size() {
  cout << "\nsize() called" << endl;
  return size(tree);
}

template<class dataType>
int BinaryTree<dataType>::size(BTnode<dataType> *node) {
  cout << "size(node) called" << endl;
  int partialSize = 0;
  if (node->left != NULL)
    partialSize+= size(node->left);
  if (node->right != NULL)
    partialSize+= size(node->right);
  if (node->data != -1) 
    return partialSize+=1;
}  

template <class dataType>
dataType BinaryTree<dataType>::min() {
  return min(tree);
}

template <class dataType>
dataType BinaryTree<dataType>::min(BTnode<dataType> *node) {
  if (node->left != NULL)
    return min(node->left);
  return node->data;
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
BTnode<dataType>* BinaryTree<dataType>::find(BTnode<dataType> *node, dataType value) {
  cout << "Seeking: " << value << endl;
  BTnode<dataType> *foo = NULL;
  if (node == NULL)
    return foo;
  if (node->data == value)
    return node;
  if (node->data > value && node->left != NULL)
    return find(node->left, value);
  if (node->data < value && node->right != NULL)
    return find(node->right, value);
  return foo;
}

template<class dataType>
void BinaryTree<dataType>::remove(dataType value) {
  BTnode<dataType> *node = find(tree, value);
  if (node == NULL) {
    cout << "Item not found" << endl;
    return;
  }
  //cout << "Remove placeholder: " << node->data << endl;
  if (node != NULL) {
    cout << "Remove placeholder: " << node->data << endl;
    if (node->left != NULL && node->right == NULL) {
      node->data = node->left->data;
      node->right = node->left->right;
      BTnode<dataType> *trashNode = node->left;
      node->left = node->left->left;
      delete trashNode;
    }
    else if (node->left == NULL && node->right !=NULL) {
      node->data = node->right->data;
      node->left = node->right->left;
      BTnode<dataType> *trashNode = node->right;
      node->right = node->right->right;
      delete trashNode;
    }
    else {
      node->data = node->right->data;
      if (node->right->left == NULL && node->right->right == NULL) {
        delete node->right;
        node->right = NULL;
      }
      else {
        //remove(node->right);
      }
    } 
  }
}


template<class dataType>
void BinaryTree<dataType>::deleteNode(BTnode<dataType> *node) {
  if (node != NULL) {
    if (node->left != NULL && node->right == NULL) {
      node->data = node->left->data;
      node->right = node->left->right;
      BTnode<dataType> *trashNode = node->left;
      node->left = node->left->left;
      delete trashNode;
    }
    else if (node->left == NULL && node->right !=NULL) {
      node->data = node->right->data;
      node->left = node->right->left;
      BTnode<dataType> *trashNode = node->right;
      node->right = node->right->right;
      delete trashNode;
    }
    else {
      node->data = node->right->data;
      if (node->right->left == NULL && node->right->right == NULL) {
        delete node->right;
        node->right = NULL;
      }
      else {
        deleteNode(node->right);
      }
    }
  }
}



//Don't use min and max
//check all for null trees


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



int main(int argc, char *argv[])
{
  cout << "\n********************************" << endl;
  BinaryTree<int> par = BinaryTree<int>(100);
  for (int i = 1; i < 205; i+=25)
    {
      par.insert(i);
    }
  /*  par.insert(1);
  par.insert(2);
  par.insert(150);
  */
  par.inorder();
  cout << "\nSize: " << par.size() << endl;
  cout << "Min: " << par.min() << endl;
  cout << "Removing: " << 150 << endl;
  par.remove(100);
  par.inorder();
  cout << "\n***********************************" << endl;
  return 0;
}


