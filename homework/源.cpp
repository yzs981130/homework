#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int totalTime, number, v[101], t[101], maxValue[1005];
int main()
{
    cin >> totalTime >> number;
    for (int i = 0; i < number; i++)
        cin >> t[i] >> v[i];
    for (int i = 0; i < number; i++)
        for (int j = 1000; j >= t[i]; j--)
            maxValue[j] = max(maxValue[j], maxValue[j - t[i]] + v[i]);
    cout << maxValue[totalTime] << endl;
    return 0;
}