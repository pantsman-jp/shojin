#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, ans = 0;
  cin >> n;
  vector<ll> a(n + 1), sum(n + 1);
  rep(i, 1, n + 1) cin >> a[i];
  sort(a.begin() + 1, a.end());
  rep(i, 1, n + 1) sum[i] = sum[i - 1] + a[i];
  rep(i, 1, n + 1) ans += sum[n] - sum[i] - (n - i) * a[i];
  cout << ans << endl;
}