#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> e(m);
  rep(i, m)
  {
    int u, v;
    cin >> u >> v;
    e[i] = {--u, --v};
  }
  int max_cross = 0;
  for (int bit = 0; bit < (1 << n); bit++)
  {
    int count = 0;
    rep(i, m)
    {
      int u = e[i].first, v = e[i].second;
      if (((bit >> u) & 1) != ((bit >> v) & 1))
        count++;
    }
    max_cross = max(max_cross, count);
  }
  cout << m - max_cross << endl;
}