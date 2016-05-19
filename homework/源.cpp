#include <memory>
#include <string>
#include <cstring>
#include <iostream>
#include <memory>
#include <cmath>
using namespace std;
int CClock[10];
int tmp_clock[10];
int Move[10][5] = {{0}, { 1, 2, 4, 5 }, {1, 2, 3}, {2, 3, 5, 6}, {1, 4, 7}, {2, 4, 5, 6, 8}, {3, 6, 9}, {4, 5, 7, 8}, {7, 8, 9}, {5, 6, 8, 9}};
void flip(int n)
{
    for (int i = 0; i < 5; i++)
        tmp_clock[Move[n][i]]++;
}
bool check_clock()
{
    for (int i = 1; i < 10; i++)
        if (tmp_clock[i] % 4 != 0)
            return false;
    return true;
}
int main()
{
    for (int i = 1; i < 10; i++)
        cin >> CClock[i];
    int tmp_ans[10], tmp_min = 10000, ans[10];
    memcpy(tmp_clock, CClock, sizeof(CClock));
    int a[10] = {0};
    for(a[0] = 0; a[0] < 4; a[0]++)
        for (a[1] = 0; a[1] < 4; a[1]++)
            for (a[2] = 0; a[2] < 4; a[2]++)
                for (a[3] = 0; a[3] < 4; a[3]++)
                    for (a[4] = 0; a[4] < 4; a[4]++)
                        for (a[5] = 0; a[5] < 4; a[5]++)
                            for (a[6] = 0; a[6] < 4; a[6]++)
                                for (a[7] = 0; a[7] < 4; a[7]++)
                                    for (a[8] = 0; a[8] < 4; a[8]++)
                                    {
                                        int tmp_sum = 0;
                                        for (int i = 0; i < 9; i++)
                                        {
                                            for (int j = 0; j < a[i]; j++)
                                                flip(i + 1);
                                            tmp_sum += a[i];
                                        }
                                        if (check_clock())
                                        {
                                            if (tmp_sum < tmp_min)
                                            {
                                                memcpy(tmp_ans, a, sizeof(a));
                                                tmp_min = tmp_sum;
                                            }
                                        }
                                        memcpy(tmp_clock, CClock, sizeof(CClock));
                                    }
    for (int i = 0; i < 9; i++)
        if (tmp_ans[i] != 0)
            for (int j = 0; j < tmp_ans[i]; j++)
                cout << i + 1 << ' ';
    cout << endl;
    system("pause");
    return 0;
}