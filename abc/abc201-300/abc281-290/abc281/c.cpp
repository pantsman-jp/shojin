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
  ll t;
  cin >> n >> t;
  vector<ll> a(n), sum(n + 1);
  rep(i, 0, n) cin >> a[i];
  sum[0] = 0;
  rep(i, 0, n) sum[i + 1] = sum[i] + a[i];
  t %= sum[n];
  rep(i, 0, n + 1)
  {
    if (t < sum[i])
    {
      cout << i << ' ' << t - sum[i - 1] << endl;
      return 0;
    }
  }
}