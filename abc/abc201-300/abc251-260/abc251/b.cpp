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
  int n, w;
  cin >> n >> w;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  vector<bool> check(w + 1, false);
  rep(i, 0, n)
  {
    if (a[i] <= w)
      check[a[i]] = true;
    rep(j, i + 1, n)
    {
      if (a[i] + a[j] <= w)
        check[a[i] + a[j]] = true;
      rep(k, j + 1, n)
      {
        if (a[i] + a[j] + a[k] <= w)
          check[a[i] + a[j] + a[k]] = true;
      }
    }
  }
  int ans = 0;
  rep(i, 1, w + 1) if (check[i]) ans++;
  cout << ans << endl;
}