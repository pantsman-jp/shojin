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
  vector<int> t(n);
  vector<vector<int>> a(n);
  rep(i, 0, n)
  {
    int k;
    cin >> t[i] >> k;
    a[i].resize(k);
    rep(j, 0, k) cin >> a[i][j], a[i][j]--;
  }
  vector<bool> need(n);
  need[n - 1] = true;
  for (int i = n - 1; i >= 0; i--)
  {
    if (need[i])
    {
      for (int j : a[i])
        need[j] = true;
    }
  }
  ll ans = 0;
  rep(i, 0, n) if (need[i]) ans += t[i];
  cout << ans << endl;
}