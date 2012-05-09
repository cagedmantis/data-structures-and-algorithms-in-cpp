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
      for (int i = 0; i < vec.size()-1; ++i)
        {
          if ( vec[i] > vec[i+1] )
            {
              swapped = true;
              std::swap( vec[i], vec[i+1] );
            }
        }
    }
}
