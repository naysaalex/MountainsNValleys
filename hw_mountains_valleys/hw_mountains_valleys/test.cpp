#include "functions.h"

#include <iostream>

int main()
{
    int testNum = 0;
    std::cin >> testNum;
    char val = classify_mv_range_type(testNum);
    std::cout << val << std::endl;
    return 0;
}