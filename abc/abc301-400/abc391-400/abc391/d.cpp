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
  int n, w;
  cin >> n >> w;
  vector<int> x(n), y(n);
  rep(i, 0, n) cin >> x[i] >> y[i], x[i]--;
  vector<int> idx(n);
  rep(i, 0, n) idx[i] = i;
  sort(all(idx), [&](int i, int j)
       { return y[i] < y[j]; });
  vector<int> r(n), num(w);
  for (int i : idx)
    r[i] = num[x[i]], num[x[i]]++;
  vector<int> d(n, inf);
  {
    vector<vector<int>> blocks(n);
    rep(i, 0, n) blocks[r[i]].push_back(i);
    rep(i, 0, n)
    {
      if (blocks[i].size() != w)
        continue;
      int mx = 0;
      for (int j : blocks[i])
        chmax(mx, y[j] - 1);
      d[i] = mx + 1;
    }
  }
  int q;
  cin >> q;
  rep(_, 0, q)
  {
    int t, a;
    cin >> t >> a;
    yn(d[r[a - 1]] > t);
  }
}