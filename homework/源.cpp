#include <iostream>
#include <string>

using namespace std;
template <class T>
class CMyistream_iterator
{
private:
    T data;
    istream &is;
public:
    CMyistream_iterator(istream &i):is(i) { is >> data; }
    T operator *() { return data; }
    void operator ++ (int)
    {
        is >> data;
    }
};



int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        CMyistream_iterator<int> inputInt(cin);
        int n1, n2, n3;
        n1 = *inputInt; //∂¡»Î n1
        int tmp = *inputInt;
        cout << tmp << endl;
        inputInt++;
        n2 = *inputInt; //∂¡»Î n2
        inputInt++;
        n3 = *inputInt; //∂¡»Î n3
        cout << n1 << " " << n2 << " " << n3 << " ";
        CMyistream_iterator<string> inputStr(cin);
        string s1, s2;
        s1 = *inputStr;
        inputStr++;
        s2 = *inputStr;
        cout << s1 << " " << s2 << endl;
    }
    return 0;
}