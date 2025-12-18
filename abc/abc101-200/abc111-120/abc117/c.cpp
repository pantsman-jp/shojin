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
  int n, m;
  cin >> n >> m;
  vector<ll> x(m);
  rep(i, 0, m) cin >> x[i];
  sort(all(x));
  vector<ll> diffs;
  rep(i, 1, m) diffs.push_back(x[i] - x[i - 1]);
  sort(rall(diffs));
  ll ans = x[m - 1] - x[0];
  rep(i, 0, min(m - 1, n - 1)) ans -= diffs[i];
  cout << ans << endl;
}