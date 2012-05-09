// Algorithm: Quick Sort
// Complexity: O( n log n )

#include <vector>
#include <iostream>

template <typename T>
int partition( std::vector<T> &vec, int start, int end )
{
  int line = start - 1;
  for (int index = start; index < end; ++index)
    {
      if (vec[index] <= vec[end])
        {
          line++;
          std::swap( vec[line], vec[index] );
        }
    }
  return line + 1;
}

template <typename T>
void quickSort( std::vector<T> &vec, int start, int end)
{
  if (start < end)
    {
      int pivot = partition(vec, start, end);
      quickSort( vec, start, pivot-1);
      quickSort( vec, pivot+1, end);
    }
}
