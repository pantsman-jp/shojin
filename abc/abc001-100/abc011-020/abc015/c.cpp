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
  int n, k;
  cin >> n >> k;
  vector t(n, vector<int>(k));
  rep(i, 0, n) rep(j, 0, k) cin >> t[i][j];
  vector<int> indices(n, 0);
  while (true)
  {
    int x = 0;
    rep(i, 0, n) x ^= t[i][indices[i]];
    if (x == 0)
    {
      cout << "Found" << endl;
      return 0;
    }
    int pos = n - 1;
    while (pos >= 0)
    {
      indices[pos]++;
      if (indices[pos] < k)
        break;
      indices[pos] = 0;
      pos--;
    }
    if (pos < 0)
      break;
  }
  cout << "Nothing" << endl;
}