#include <iostream>
#include <string>
using namespace std;
template <class T>
T SumArray(T *a, T *b)
{
    for (int i = 1; i < b - a; i++)
        *a += *(a + i);
    return *a;
}
int main()
{
    string array[4] = {"Tom","Jack","Mary","John"};
    cout << SumArray(array, array + 4) << endl;
    int a[4] = {1, 2, 3, 4};  //ÌáÊ¾£º1+2+3+4 = 10
    cout << SumArray(a, a + 4) << endl;
    return 0;
}