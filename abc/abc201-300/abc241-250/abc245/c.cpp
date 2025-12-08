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
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n), b(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) cin >> b[i];
  vector<bool> dpa(n), dpb(n);
  dpa[0] = dpb[0] = true;
  rep(i, 0, n - 1)
  {
    if (dpa[i])
    {
      if (abs(a[i] - a[i + 1]) <= k)
        dpa[i + 1] = true;
      if (abs(a[i] - b[i + 1]) <= k)
        dpb[i + 1] = true;
    }
    if (dpb[i])
    {
      if (abs(b[i] - a[i + 1]) <= k)
        dpa[i + 1] = true;
      if (abs(b[i] - b[i + 1]) <= k)
        dpb[i + 1] = true;
    }
  }
  if (dpa[n - 1] or dpb[n - 1])
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}