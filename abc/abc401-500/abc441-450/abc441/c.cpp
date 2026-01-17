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
// const ll mod = 998244353;
// const ll mod = 1e9 + 7;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  ll x;
  cin >> n >> k >> x;
  vector<ll> a(n), sum(n + 1);
  rep(i, 0, n) cin >> a[i];
  sort(all(a));
  sum[0] = 0;
  rep(i, 0, n) sum[i + 1] = sum[i] + a[i];
  rep(m, 1, n + 1)
  {
    int t = max(0, k - (n - m));
    if (t > m)
      continue;
    int l = n - m;
    int r = l + t;
    if (sum[r] - sum[l] >= x)
    {
      cout << m << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}