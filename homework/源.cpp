#include <memory>
#include <string>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
template <class T>
void printbybit(const T& ob)
{
    char *p_e = (char *)&ob;
    char *p = p_e + sizeof(T) - 1;
    for (; p >= p_e; p--)
    {
        for (int i = 7; i >= 0; i--)
        {
            cout << (((*p)&(1 << i)) ? 1 : 0);
        }
    }
    cout << endl;
}
inline int GetBit(int c, int i)
{
    return  (c >> i) & 1;
}
inline void SetBit(int & c, int i, int v)
{
    if (v)
        c |= (1 << i);
    else
        c &= ~(1 << i);
}
inline void Flip(int & c, int i)
{
    c ^= (1 << i);
}
int GetCountOf1(int a)
{
    int tmp = 0, i = 17;
    while (i--)
    {
        tmp += (a & 1);
        a = a >> 1;
    }
    return tmp;
}
int T;
const int N = 16;

int main()
{
    int BeginBoard[N];
    int Board[N];
    int Switch;
    char s;
    int Size;
    int SUM = 300, Tsum;
    cin >> T;
    Size = pow(2, T);
    memset(BeginBoard, 0, sizeof(BeginBoard));
    for (int i = 0; i < T; i++)
        for (int j = 0; j < T; j++)
        {
            cin >> s;
            SetBit(BeginBoard[i], j, s == 'y');
        }

    for (int n = 0; n < Size; ++n)
    {
        memcpy(Board, BeginBoard, sizeof(BeginBoard));
        Switch = n;
        Tsum = 0;
        for (int i = 0; i < T; ++i)
        {
            Tsum += GetCountOf1(Switch);
            if (Tsum > SUM) continue;
            for (int j = 0; j < T; ++j)
            {
                if (GetBit(Switch, j))
                {
                    if (j > 0)
                        Flip(Board[i], j - 1);
                    Flip(Board[i], j);
                    if (j < T - 1)
                        Flip(Board[i], j + 1);
                }
            }
            if (i < T - 1)	  
                Board[i + 1] ^= Switch;
            Switch = Board[i] ^ (Size - 1);
        }
        if (Board[T - 1] == Size - 1)
        {
            if (SUM > Tsum)
                SUM = Tsum;
        }
    }
    if (SUM == 300) 
        cout << "inf";
    else 
        cout << SUM;
    system("pause");
    return 0;
}