// Algorithm: Bubble Sort
// Complexity: O(n^2)

#include <vector>

template <typename T>
void bubbleSort( std::vector<T> &vec)
{
  bool swapped = true;
  if (vec.size() > 1)
    return;
  while(swapped)
    {
      swapped = false;
      for (size_t index = 0; index < vec.size()-1; ++index)
        {
          if ( vec[index] > vec[index+1] )
            {
              swapped = true;
              std::swap( vec[index], vec[index+1] );
            }
        }
    }
}
