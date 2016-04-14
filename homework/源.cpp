#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <set>
using namespace std;
int main()
{
    long n;
    cin >> n;
    int id1;
    multiset<int> v;
    multiset<int> a;
    while (n--)
    {
        string cmd;
        cin >> cmd >> id1;
        if (cmd == "add")
        {
            v.insert(id1);
            a.insert(id1);
            cout << v.count(id1) << endl;
        }
        else if (cmd == "del")
        {
            cout << v.count(id1) << endl;
            v.erase(id1);
        }
        else if (cmd == "ask")
        {
            if (a.find(id1) == a.end())
                cout << 0 << ' ' << v.count(id1) << endl;
            else
                cout << 1 << ' ' << v.count(id1) << endl;
        }
    }
    system("pause");
    return 0;
}