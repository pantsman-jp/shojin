#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> x(n), y(n);
  rep(i, 0, n) cin >> x[i] >> y[i];
  string s;
  cin >> s;
  map<int, vector<pair<int, char>>> ys;
  rep(i, 0, n) ys[y[i]].push_back(make_pair(x[i], s[i]));
  for (auto [_, vec] : ys)
  {
    sort(all(vec));
    rep(i, 0, vec.size() - 1)
    {
      if (vec[i].second == 'R' and vec[i + 1].second == 'L')
      {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}