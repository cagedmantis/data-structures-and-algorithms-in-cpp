#include "btnode.h"
#include <iostream>


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
  //cout << "removing node: " << data << endl;
  //delete left;
  //delete right;
}
