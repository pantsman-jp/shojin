#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

ll calc(ll n, vector<ll> a)
{
  ll ans = 0;
  vector<ll> sum(n + 1);
  sort(a.begin() + 1, a.end());
  rep(i, 1, n + 1) sum[i] = sum[i - 1] + a[i];
  rep(i, 1, n + 1) ans += sum[n] - sum[i] - (n - i) * a[i];
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<ll> x(n + 1), y(n + 1);
  rep(i, 1, n + 1) cin >> x[i] >> y[i];
  cout << calc(n, x) + calc(n, y) << endl;
}