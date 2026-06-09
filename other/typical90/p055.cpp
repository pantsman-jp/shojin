#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a) - 1; i >= b; i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
// const ll mod =;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  ll p, q;
  cin >> n >> p >> q;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  int ans = 0;
  rep(i, 0, n) rep(j, i + 1, n) rep(k, j + 1, n) rep(l, k + 1, n) rep(m, l + 1, n)
  {
    if (a[i] % p * a[j] % p * a[k] % p * a[l] % p * a[m] % p == q)
      ans++;
  }
  cout << ans << endl;
}