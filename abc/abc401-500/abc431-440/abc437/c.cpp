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

void solve()
{
  int n;
  cin >> n;
  vector<ll> w(n), p(n);
  ll sump = 0;
  vector<ll> costs(n);
  rep(i, 0, n)
  {
    cin >> w[i] >> p[i];
    sump += p[i], costs[i] = w[i] + p[i];
  }
  sort(all(costs));
  int ans = 0;
  ll now = 0;
  rep(i, 0, n)
  {
    if (now + costs[i] <= sump)
      now += costs[i], ans++;
    else
      break;
  }
  cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  rep(_, 0, t) solve();
}