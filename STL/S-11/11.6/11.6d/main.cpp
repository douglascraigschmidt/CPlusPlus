#include <cstdlib>
#include <ctime>
#include <vector>
#include <list>

#include "bubble_sort.h"
#include "insertion_sort.h"

#include "generate_data.h"
#include "time_sort.h"

using namespace std;

/**
 * Demonstrate the time taken to sort various containers using various
 * sorting algorithms.
 */
int main() {
  const int biggest = 100000;
  const int size = 10000;

  srand(time(nullptr));

  vector<int> data = generate_data<int>(size, biggest);
  list<int> list_data (data.begin(), data.end());

  time_sort<int>("bubble_sort(vector)", data, bubble_sort);
  time_sort<int>("bubble_sort(list)", list_data, bubble_sort);

  time_sort<int>("insertion_sort(vector)", data, insertion_sort);
  time_sort<int>("sort(vector)", data);

  return 0;
}
