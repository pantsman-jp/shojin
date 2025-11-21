#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
using ld = long double;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> c(9);
  rep(i, 0, 9) cin >> c[i];
  vector<vector<int>> lines = {{0, 1, 2},
                               {3, 4, 5},
                               {6, 7, 8},
                               {0, 3, 6},
                               {1, 4, 7},
                               {2, 5, 8},
                               {0, 4, 8},
                               {2, 4, 6}};
  ld total = 0, good = 0;
  vector<int> p(9);
  iota(all(p), 0);
  do
  {
    total++;
    bool ok = true;
    vector<int> pos(9);
    rep(i, 0, 9) pos[p[i]] = i;
    for (auto &l : lines)
    {
      int a = c[l[0]], b = c[l[1]], d = c[l[2]];
      if (a == b and b != d)
      {
        if (pos[l[2]] > max(pos[l[0]], pos[l[1]]))
        {
          ok = false;
          break;
        }
      }
      if (a == d and d != b)
      {
        if (pos[l[1]] > max(pos[l[0]], pos[l[2]]))
        {
          ok = false;
          break;
        }
      }
      if (b == d and a != b)
      {
        if (pos[l[0]] > max(pos[l[1]], pos[l[2]]))
        {
          ok = false;
          break;
        }
      }
    }
    if (ok)
      good++;
  } while (next_permutation(all(p)));
  cout << fixed << setprecision(10) << good / total << endl;
}