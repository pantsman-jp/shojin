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

bool solve()
{
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, 0, n) cin >> a[i];
  int cnt_pos = count(all(a), a[0]);
  int cnt_neg = count(all(a), -a[0]);
  if (cnt_pos == n)
    return true;
  if (cnt_pos + cnt_neg == n and min(cnt_pos, cnt_neg) == n / 2)
    return true;
  sort(all(a), [](ll x, ll y)
       { return abs(x) > abs(y); });
  rep(i, 0, n - 2) if (a[i] * a[i + 2] != a[i + 1] * a[i + 1]) return false;
  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  rep(_, 0, t) yn(solve());
}