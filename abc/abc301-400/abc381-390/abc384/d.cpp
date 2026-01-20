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
// const ll mod = 1000000007;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  ll s;
  cin >> n >> s;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  vector<ll> sum(2 * n + 1);
  rep(i, 0, n * 2) sum[i + 1] = sum[i] + a[i % n];
  s %= sum[n];
  set<ll> sums;
  rep(i, 0, 2 * n + 1) sums.insert(sum[i]);
  rep(i, 0, 2 * n + 1)
  {
    if (sums.count(sum[i] - s))
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}