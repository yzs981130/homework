#include <iostream>
using namespace std;
class MyCin
{
private:
    istream &is;
    bool tmp;
public:
    MyCin():is(cin), tmp(true){}
    friend MyCin &operator >> (MyCin &o, int &a)
    {
        o.is >> a;
        if(a == -1) 
            o.tmp = false;
        return o;
    }
    operator bool() const { return tmp; }
};
int main()
{
    MyCin m;
    int n1, n2;
    while (m >> n1 >> n2)
        cout << n1 << " " << n2 << endl;
    return 0;
}