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
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  rep(i, 0, n) cin >> p[i], p[i]--;
  vector<int> q(n);
  rep(i, 0, n) q[p[i]] = i;
  int ans = inf;
  set<int> s;
  rep(i, 0, n)
  {
    s.insert(q[i]);
    if (s.size() > k)
      s.erase(q[i - k]);
    if (s.size() == k)
      chmin(ans, *s.rbegin() - *s.begin());
  }
  cout << ans << endl;
}