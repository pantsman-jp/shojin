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
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  rep(i, 0, n) cin >> s[i];
  sort(all(s));
  do
  {
    bool ok = true;
    rep(i, 0, n - 1)
    {
      int diff = 0;
      rep(j, 0, m) if (s[i][j] != s[i + 1][j]) diff++;
      if (diff != 1)
      {
        ok = false;
        break;
      }
    }
    if (ok)
    {
      cout << "Yes" << endl;
      return 0;
    }
  } while (next_permutation(all(s)));
  cout << "No" << endl;
}