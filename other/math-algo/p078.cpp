#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + 1);
  rep(i, 0, m)
  {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<int> age(n + 1, 0);
  queue<int> q;
  vector<bool> in_queue(n + 1, false);
  q.push(1);
  in_queue[1] = true;
  while (!q.empty())
  {
    int cur = q.front();
    q.pop();
    in_queue[cur] = false;
    for (int nex : g[cur])
    {
      if (age[nex] < age[cur] - 1)
      {
        age[nex] = age[cur] - 1;
        if (!in_queue[nex])
        {
          q.push(nex);
          in_queue[nex] = true;
        }
      }
      if (age[nex] < age[cur] + 1)
      {
        age[nex] = age[cur] + 1;
        if (!in_queue[nex])
        {
          q.push(nex);
          in_queue[nex] = true;
        }
      }
    }
  }
  rep(i, 1, n + 1) cout << age[i] << endl;
}
