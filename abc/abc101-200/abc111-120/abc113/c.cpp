#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using p = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

string pad(int x, int n, char c)
{
  string s = to_string(n);
  return string(max(0, x - (int)s.size()), c) + s;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> p(m), y(m);
  rep(i, 0, m) cin >> p[i] >> y[i];
  vector<vector<pair<int, int>>> cities(n + 1);
  rep(i, 0, m) cities[p[i]].push_back({y[i], i});
  vector<int> order(m);
  rep(p, 1, n + 1)
  {
    sort(all(cities[p]));
    rep(i, 0, cities[p].size()) order[cities[p][i].second] = i + 1;
  }
  rep(i, 0, m) cout << pad(6, p[i], '0') << pad(6, order[i], '0') << endl;
}