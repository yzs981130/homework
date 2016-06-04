#include <iostream>
using namespace std;
#define MAX 102
int final[MAX], cnt_a, cnt_b;
int a[MAX], b[MAX];
int main()
{    
    int n, na, nb;
    cin >> n >> na >> nb;
    for (int i = 0; i < na; i++)
        cin >> a[i];
    for (int i = 0; i < nb; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
    {
        if ((a[i%na] == 5 && b[i%nb] == 0) || (a[i%na] == 0 && b[i%nb] == 2) || (a[i%na] == 2 && b[i%nb] == 5))
            cnt_a++;
        if ((a[i%na] == 0 && b[i%nb] == 5) || (a[i%na] == 2 && b[i%nb] == 0) || (a[i%na] == 5 && b[i%nb] == 2))
            cnt_b++;
    }
    if (cnt_a > cnt_b)
        cout << 'A' << endl;
    else if (cnt_a < cnt_b)
        cout << 'B' << endl;
    else
        cout << "draw" << endl;
    system("pause");
    return 0;
}