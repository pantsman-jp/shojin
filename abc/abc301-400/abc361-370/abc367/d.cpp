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
  ll m;
  cin >> n >> m;
  vector<ll> a(n), sum(n * 2 + 1, 0);
  rep(i, 0, n) cin >> a[i];
  vector<vector<int>> mod(m);
  rep(i, 0, 2 * n)
  {
    sum[i + 1] = sum[i] + a[i % n];
    mod[sum[i] % m].push_back(i);
  }
  ll ans = 0;
  rep(i, 0, m)
  {
    auto v = mod[i];
    int l = 0, r = 0;
    while (l < v.size() and v[l] < n)
    {
      while (r < v.size() and v[r] - v[l] < n)
        r++;
      ans += r - l - 1;
      l++;
    }
  }
  cout << ans << endl;
}