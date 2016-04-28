#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;
string tmp_num, tmp_dir;
int my_stoi(string str)
{
    stringstream ss;
    ss << str;
    int n;
    ss >> n;
    return n;
}
void cal_str(string str)
{
    int pos;
    for(int i = 0; i < str.length(); i++)
        if(!isdigit(str[i]))
        {
            pos = i;
            break;
        }
    tmp_num = str.substr(0, pos);
    tmp_dir = str.substr(pos, str.length() - 1);
}
int main()
{
    string input;
    int cnt = 1;
    string cmd[1000];
    while (cin >> input && input != "END")
    {
        int n = 1;
        double x = 0, y = 0;
        while (input.find(',') != string::npos)
        {
            int i = input.find(',');
            input[i] = ' ';
            n++;
        }
        input[input.length() - 1] = ' ';
        stringstream ss;
        ss.str(input);
        for (int i = 0; i < n; i++)
            ss >> cmd[i];
        cout << "Map #" << cnt << endl;
        for (int i = 0; i < n; i++)
        {
            cal_str(cmd[i]);
            int dis = my_stoi(tmp_num);
            if (tmp_dir == "N")
                y += dis;
            else if (tmp_dir == "E")
                x += dis;
            else if (tmp_dir == "S")
                y -= dis;
            else if (tmp_dir == "W")
                x -= dis;
            else if (tmp_dir == "NW")
            {
                double tmp = dis / sqrt(2.0);
                x -= tmp;
                y += tmp;
            }
            else if (tmp_dir == "NE")
            {
                double tmp = dis / sqrt(2.0);
                x += tmp;
                y += tmp;
            }
            else if (tmp_dir == "SE")
            {
                double tmp = dis / sqrt(2.0);
                x += tmp;
                y -= tmp;
            }
            else if (tmp_dir == "SW")
            {
                double tmp = dis / sqrt(2.0);
                x -= tmp;
                y -= tmp;
            }
        }
        cout << fixed << setprecision(3) << "The treasure is located at (" << x << ',' << y << ")." << endl;
        cout << fixed << setprecision(3) << "The distance to the treasure is " << sqrt(x*x + y*y) << '.' << endl << endl;
        cnt++;
    }
    system("pause");
    return 0;
}