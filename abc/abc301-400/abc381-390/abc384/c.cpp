#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  vector<int> p(5);
  rep(i, 0, 5) cin >> p[i];
  rep(i, 0, 5) p[i] *= -1;
  vector<pair<int, string>> pts_name;
  rep(bit, 1, 32)
  {
    int pts = 0;
    string name = "";
    rep(digit, 0, 5)
    {
      if (bit & 1 << digit)
      {
        pts += p[digit];
        name += "ABCDE"[digit];
      }
    }
    pts_name.emplace_back(pts, name);
  }
  ranges::sort(pts_name);
  for (const auto &name : pts_name | views::values)
    cout << name << endl;
}
