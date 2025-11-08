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
  int n, p = 0;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  vector<bool> grid(4, false);
  rep(i, 0, n)
  {
    grid[0] = true;
    vector<bool> next(4, false);
    rep(j, 0, 4)
    {
      if (grid[j])
      {
        if (j + a[i] >= 4)
          p++;
        else
          next[j + a[i]] = true;
      }
    }
    grid = next;
  }
  cout << p << endl;
}