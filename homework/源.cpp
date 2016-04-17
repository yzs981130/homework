#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <set>
using namespace std;
int main()
{
    int n;
    cin >> n;
    set<pair<int, int> >people;
    set<pair<int, int> >::iterator ptr;
    set<pair<int, int> >::iterator left;
    set<pair<int, int> >::iterator right;
    people.insert(make_pair(1000000000, 1));
    while (n--)
    {
        int tmp_id, tmp_force;
        int a, b;
        scanf("%d %d", &tmp_id, &tmp_force);
        people.insert(make_pair(tmp_force, tmp_id));
        ptr = people.find(make_pair(tmp_force, tmp_id));
        right = people.end();
        --right;
        if (ptr == people.begin())
        {
            right = ptr;
            ++right;
            printf("%d %d\n", tmp_id, right->second);
            if (tmp_force == right->first)
                people.erase(right);
        }
        else if (ptr == right)
        {
            left = ptr;
            --left;
            printf("%d %d\n", tmp_id, left->second);
            if (tmp_force == left->first)
                people.erase(left);
        }
        else
        {
            left = right = ptr;
            --left;
            ++right;
            if ((tmp_force - left->first) < (right->first - tmp_force))
                printf("%d %d\n", tmp_id, left->second);
            else if ((tmp_force - left->first) > (right->first - tmp_force))
                printf("%d %d\n", tmp_id, right->second);
            else
            {
                if (left->second < right->second)
                    printf("%d %d\n", tmp_id, left->second);
                else
                    printf("%d %d\n", tmp_id, right->second);
            }
            if (tmp_force == right->first)
                people.erase(right);
            if (tmp_force == left->first)
                people.erase(ptr);
        }
    }
    return 0;
}