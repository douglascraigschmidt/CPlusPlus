#include <iostream>
// using namespace std;

#define MIN(i, j) (((i) < (j)) ? (i) : (j))

template<typename T> T min(const T &i, const T &j) {
    return i < j ? i : j;
}

int main() {
    int a = 10, b = 20;

    std::cout << "min = " << min(a++, b++) << std::endl;
    std::cout << "MIN = " << MIN(a++, b++) << std::endl;

    return 0;
}

