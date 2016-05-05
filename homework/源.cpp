#include <iostream>
using namespace std;
class CType
{
public:
    int n;
    void setvalue(int _n) { n = _n; }
    int operator ++(int tmp) { return n; }
    friend ostream &operator << (ostream &s, const CType &c) { s << c.n * c.n; return s; }
};
int main(int argc, char* argv[])
{
    CType obj;
    int   n;
    cin >> n;
    while (n)
    {
        obj.setvalue(n);
        cout << obj++ << " " << obj << endl;
        cin >> n;
    }
    system("pause");
    return 0;
}