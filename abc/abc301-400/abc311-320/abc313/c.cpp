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
  vector<ll> a(n);
  ll sum = 0;
  rep(i, 0, n) cin >> a[i], sum += a[i];
  sort(all(a));
  vector<ll> b(n, sum / n);
  rep(i, 0, sum % n) b[n - i - 1]++;
  ll ans = 0;
  rep(i, 0, n) ans += abs(a[i] - b[i]);
  cout << ans / 2 << endl;
}