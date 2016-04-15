#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
string s[21];
int my_find();
int my_rfind();
string my_add();
string my_copy();
int my_stoi(string s)
{
    stringstream ss;
    int n;
    ss << s;
    ss >> n;
    return n;
}
bool is_valid(string str)
{
    if (str.length() > 5)
        return false;
    for (int i = 0; i < str.size(); i++)
    {
        if (!(str[i] >= '0' && str[i] <= '9'))
            return false;
    }
    return true;
}
int cal_int(string tmp)
{
    if (tmp == "find")
        return my_find();
    else if (tmp == "rfind")
        return my_rfind();
    else
        return my_stoi(tmp);
}
string cal_str(string tmp)
{
    if (tmp == "add")
        return my_add();
    else if (tmp == "copy")
        return my_copy();
    else
        return tmp;
}
int my_find()
{
    string tmp1, tmp2, a;
    int b;
    cin >> tmp1;
    a = cal_str(tmp1);
    cin >> tmp2;
    b = cal_int(tmp2);
    if (s[b].find(a) == string::npos)
        return s[b].length();
    else
        return s[b].find(a);
}
int my_rfind()
{
    string tmp1, tmp2, a;
    int b;
    cin >> tmp1;
    a = cal_str(tmp1);
    cin >> tmp2;
    b = cal_int(tmp2);
    if (s[b].rfind(a) == string::npos)
        return s[b].length();
    else
        return s[b].rfind(a);
}
string my_add()
{
    string a, b, tmp1, tmp2;
    cin >> a;
    tmp1 = cal_str(a);
    cin >> b;
    tmp2 = cal_str(b);
    if (is_valid(tmp1) && is_valid(tmp2))
    {
        int tmp = my_stoi(tmp1) + my_stoi(tmp2);
        string tmp_str;
        stringstream ss;
        ss << tmp;
        ss >> tmp_str;
        return tmp_str;
    }
    else
        return tmp1 + tmp2;
}
string my_copy()
{
    string tmp1, tmp2, tmp3;
    int a, b, c;
    cin >> tmp1;
    a = cal_int(tmp1);
    cin >> tmp2;
    b = cal_int(tmp2);
    cin >> tmp3;
    c = cal_int(tmp3);
    return s[a].substr(b, c);
}
void my_insert()
{
    string tmp1, tmp2, tmp3, a;
    int b, c;
    cin >> tmp1;
    a = cal_str(tmp1);
    cin >> tmp2;
    b = cal_int(tmp2);
    cin >> tmp3;
    c = cal_int(tmp3);
    s[b].insert(c, a);
}
void my_reset()
{
    string tmp1, tmp2, a;
    int b;
    cin >> tmp1;
    a = cal_str(tmp1);
    cin >> tmp2;
    b = cal_int(tmp2);
    s[b].assign(a);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    string cmd;
    cin >> cmd;
    while (cmd != "over")
    {
        if (cmd == "copy")
            my_copy();
        else if (cmd == "insert")
            my_insert();
        else if (cmd == "add")
            my_add();
        else if (cmd == "find")
            my_find();
        else if (cmd == "rfind")
            my_rfind();
        else if (cmd == "reset")
            my_reset();
        else if (cmd == "print")
        {
            int tmp;
            cin >> tmp;
            cout << s[tmp] << endl;
        }
        else if (cmd == "printall")
        {
            for (int i = 1; i <= n; i++)
                cout << s[i] << endl;
        }
        cin >> cmd;
    }
    system("pause");
    return 0;
}