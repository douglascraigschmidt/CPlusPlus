#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <queue>

#include "heap_sort.h"
#include "time_sort.h"
#include "generate_data.h"

using namespace std;

/**
 * Compare the performance of heap_sort() and sort().
 */
int main() {
  const int biggest = 100000;
  const int size = 200000;

  srand(time(nullptr));

  vector<int> data = generate_data<int>(size, biggest);

  time_sort<int>("heap_sort(vector)", data, heap_sort);
  time_sort<int>("sort(vector)", data, sort);

  return 0;
}
