#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n, vector<int>(n, 0));
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a][b] = 1, adj[b][a] = -1;
  }
  for (int k = 0; k < n; k++)
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (adj[i][k] == 1 and adj[k][j] == 1)
          adj[i][j] = 1;
  vector<int> win(n, 0);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      if (adj[i][j] == 1)
        win[i]++;
  int cnt = 0, ans = -1;
  for (int i = 0; i < n; i++)
    if (win[i] == n - 1)
      cnt++, ans = i + 1;
  if (cnt == 1)
    cout << ans << endl;
  else
    cout << -1 << endl;
}
