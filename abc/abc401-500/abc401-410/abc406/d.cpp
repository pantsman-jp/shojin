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
  int h, w, n;
  cin >> h >> w >> n;
  vector<set<int>> row(h), line(w);
  rep(i, 0, n)
  {
    int x, y;
    cin >> x >> y;
    x--, y--;
    row[x].insert(y);
    line[y].insert(x);
  }
  int q;
  cin >> q;
  rep(_, 0, q)
  {
    int t, p;
    cin >> t >> p;
    p--;
    if (t == 1)
    {
      cout << row[p].size() << endl;
      for (int j : row[p])
        line[j].erase(p);
      row[p] = set<int>();
    }
    else
    {
      cout << line[p].size() << endl;
      for (int j : line[p])
        row[j].erase(p);
      line[p] = set<int>();
    }
  }
}