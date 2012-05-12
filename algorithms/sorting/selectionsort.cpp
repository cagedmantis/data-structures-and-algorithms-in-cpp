// Algorithm: Selection Sort
// Complexity: O(n^2)

#include <vector>
#include <iostream>

template <typename T>
void selectionSort( std::vector<T> &vec)
{
  for (size_t index1 = 0; index1 < vec.size(); ++index1)
    {
      size_t minIndex = index1;
      for (size_t index2 = index1; index2 < vec.size(); ++index2)
        {
          if ( vec[minIndex] > vec[index2] )
            {
              minIndex = index2;
            }
        }
      std::swap( vec[index1], vec[minIndex] );
    }
}

