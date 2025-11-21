#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<ll>> a(n);
  rep(i, 0, n)
  {
    int f, s;
    cin >> f >> s;
    a[f - 1].push_back(s);
  }
  ll ans = 0;
  rep(i, 0, n)
  {
    sort(all(a[i]), greater<int>());
    if (a[i].size() < 2)
      continue;
    ans = max(ans, a[i][0] + a[i][1] / 2);
  }
  vector<ll> b;
  rep(i, 0, n)
  {
    if (a[i].empty())
      continue;
    b.push_back(a[i][0]);
  }
  sort(all(b), greater<int>());
  if (1 < b.size())
    ans = max(ans, b[0] + b[1]);
  cout << ans << endl;
}