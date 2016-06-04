#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 1000001
int s, t, step[MAX];
bool vis[MAX];
int bfs(int s, int t)
{
    queue<int>q;
    q.push(s);
    vis[s] = true;
    while (!q.empty())
    {
        int head = q.front();
        q.pop();
        vis[head] = true;
        if (head == t)
            break;
        if (head - 1 >= 0 && !vis[head - 1])
        {
            vis[head - 1] = true;
            q.push(head - 1);
            step[head - 1] = step[head] + 1;
        }
        if (head + 1 < MAX && !vis[head + 1])
        {
            vis[head + 1] = true;
            q.push(head + 1);
            step[head + 1] = step[head] + 1;
        }
        if (2 * head < MAX && !vis[2 * head])
        {
            vis[2 * head] = true;
            q.push(2 * head);
            step[2 * head] = step[head] + 1;
        }
        if (head % 2 == 0 && !vis[head / 2])
        {
            vis[head / 2] = true;
            q.push(head / 2);
            step[head / 2] = step[head] + 1;
        }
    }
    return step[t];
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        cin >> s >> t;
        memset(vis, 0, sizeof(vis));
        memset(step, 0, sizeof(step));
        int a = bfs(s, t);
        memset(vis, 0, sizeof(vis));
        memset(step, 0, sizeof(step));
        int b = bfs(t, s);
        cout << a + b << endl;
    }
    return 0;
}