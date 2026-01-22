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

bool out(int i, int j, int h, int w)
{
  return i < 0 or h - 1 < i or j < 0 or w - 1 < j;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h, w, q;
  cin >> h >> w >> q;
  vector<set<int>> row(h, {-1, w}), line(w, {-1, h});
  rep(i, 0, h) rep(j, 0, w) row[i].insert(j), line[j].insert(i);
  auto del = [&](int r, int c) -> void
  {
    if (out(r, c, h, w))
      return;
    row[r].erase(c), line[c].erase(r);
  };
  rep(_, 0, q)
  {
    int r, c;
    cin >> r >> c;
    r--, c--;
    auto right = row[r].lower_bound(c);
    if (*right == c)
    {
      del(r, *right);
      continue;
    }
    auto left = prev(right);
    auto down = line[c].lower_bound(r);
    auto top = prev(down);
    del(r, *right), del(r, *left), del(*down, c), del(*top, c);
  }
  ll ans = 0;
  rep(i, 0, h) ans += row[i].size() - 2;
  cout << ans << endl;
}