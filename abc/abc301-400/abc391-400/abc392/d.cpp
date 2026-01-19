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
  cin >> n;
  vector<int> k(n);
  vector<map<int, int>> cnt(n);
  rep(i, 0, n)
  {
    cin >> k[i];
    rep(j, 0, k[i])
    {
      int a;
      cin >> a;
      cnt[i][a]++;
    }
  }
  ld ans = 0.0;
  rep(i, 0, n) rep(j, i + 1, n)
  {
    int a = i, b = j;
    ld p = 0.0;
    if (cnt[a].size() > cnt[b].size())
      swap(a, b);
    for (auto [x, m] : cnt[a])
    {
      if (cnt[b].count(x) != 0)
        p += (ld)m / k[a] * (ld)cnt[b][x] / k[b];
    }
    chmax(ans, p);
  }
  dout(ans);
}