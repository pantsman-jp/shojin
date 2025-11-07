#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

void solve()
{
  int n;
  string s;
  cin >> n >> s;
  int pow2 = 1 << n;
  vector<bool> visited(pow2, false);
  queue<int> q;
  visited[0] = true, q.push(0);
  while (!q.empty())
  {
    int t = q.front();
    q.pop();
    rep(i, 0, n)
    {
      int nt = t | 1 << i;
      if (nt == t)
        continue;
      if (s[nt - 1] == '1')
        continue;
      if (visited[nt])
        continue;
      visited[nt] = true;
      q.push(nt);
    }
  }
  if (visited[pow2 - 1])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  rep(_, 0, t) solve();
}