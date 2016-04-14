#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;
int main()
{
    long n;
    cin >> n;
    int id1, id2;
    list<int> v[10000];
    while (n--)
    {
        string cmd;
        cin >> cmd >> id1;
        if (cmd == "add")
        {
            cin >> id2;
            v[id1].push_back(id2);
        }
        else if (cmd == "merge")
        {
            cin >> id2;
            v[id1].merge(v[id2]);
        }
        else if (cmd == "unique")
        {
            v[id1].sort();
            v[id1].unique();
        }
        else if (cmd == "out")
        {
            v[id1].sort();
            for (list<int>::iterator i = v[id1].begin(); i != v[id1].end(); ++i)
            {
                cout << *i << ' ';
            }
            cout << endl;
        }
    }
    system("pause");
    return 0;
}