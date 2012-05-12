#ifndef _BTNODE_H_
#define _BTNODE_H_

using namespace std;


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

#endif /* _BTNODE_H_ */
