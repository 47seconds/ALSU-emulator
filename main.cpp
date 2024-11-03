#include <iostream>
#include <cmath>

int is2power(int n)
{
    // float power = log2(n);
    if (trunc(log2(n)) == float(log2(n))) return log2(n);
    else return -1;
}

int main()
{
    int a = is2power(33);
    std::cout << a << std::endl;
    return 0;
}