#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<ll> a(n), b(m);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n - 1) a[i + 1] = min(a[i + 1], a[i]);
  rep(i, 0, m) cin >> b[i];
  rep(i, 0, m)
  {
    int j = lower_bound(all(a), b[i], greater<int>()) - a.begin();
    if (j == n)
      cout << -1 << endl;
    else
      cout << j + 1 << endl;
  }
}