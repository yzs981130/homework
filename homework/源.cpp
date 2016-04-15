#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin >> n;
    map<int, int>people;
    map<int, int>::iterator p;
    map<int, int>::iterator q;
    people.insert(map<int, int>::value_type(1000000000, 1));
    while (n--)
    {
        int tmp_id, tmp_force;
        cin >> tmp_id >> tmp_force;
        people.insert(map<int, int>::value_type(tmp_force, tmp_id));
        p = people.lower_bound(tmp_force);
        q = people.upper_bound(tmp_force);
        if (p != people.begin())
        {
            --p;
            if ((tmp_force - p->first) <= (q->first - tmp_force))
                cout << tmp_id << ' ' << p->second << endl;
            else
                cout << tmp_id << ' ' << q->second << endl;
        }
        else
            cout << tmp_id << ' ' << q->second << endl;
    }
    system("pause");
    return 0;
}