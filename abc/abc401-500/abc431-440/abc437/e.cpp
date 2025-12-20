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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> a(n + 1);
  vector<pair<vector<int>, int>> b;
  rep(i, 1, n + 1)
  {
    int x, y;
    cin >> x >> y;
    a[i] = a[x];
    a[i].push_back(y);
    b.push_back({a[i], i});
  }
  sort(all(b), [](auto &p1, auto &p2)
       {
    if (p1.first != p2.first) return p1.first < p2.first;
    return p1.second < p2.second; });
  rep(i, 0, n) cout << b[i].second << ' ';
  cout << endl;
}