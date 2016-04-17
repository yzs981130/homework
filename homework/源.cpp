#include<iostream>
#include<stdio.h>
#include<queue>
#include<iterator>
#include<algorithm>
#include<cmath>
using namespace std;
bool CheckPrimer(int a)
{
    int q = sqrt(a);
    for (int i = 2; i <= q; i++)
    {
        if (a % i == 0)
            return false;
    }
    return true;
}
int ct(int a)
{
    int sum = 0, k;
    for (int i = 2; i <= sqrt(a); i++)
    {
        if (a % i == 0)
        {
            k = a / i;
            if (i != k && CheckPrimer(k))
                sum++;
            if (CheckPrimer(i))
                sum++;
        }
    }
    return sum;
}
class cmp1
{
public:
    bool operator() (int a, int b)
    {
        int p = ct(a);
        int q = ct(b);
        if (p < q)
            return true;
        else if (p == q)
        {
            if (a < b)
                return true;
            else
                return false;
        }
        else
            return false;
    }
};
class cmp2
{
public:
    bool operator() (int a, int b)
    {
        int p = ct(a);
        int q = ct(b);
        if (p < q)
            return false;
        else if (p == q)
        {
            if (a < b)
                return false;
            else
                return true;
        }
        else
            return true;
    }
};
int main()
{
    int num;
    cin >> num;
    int n;
    priority_queue<int, vector<int>, cmp1> pq1;
    priority_queue<int, vector<int>, cmp2> pq2;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> n;
            pq1.push(n);
            pq2.push(n);
        }
        cout << pq1.top() << " ";
        pq1.pop();
        cout << pq2.top() << endl;
        pq2.pop();
    }
    system("pause");
    return 0;
}