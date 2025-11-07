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
  vector<string> a(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) rep(j, 0, n)
  {
    bool ok = true;
    if (a[i][j] == 'W' and a[j][i] != 'L')
      ok = false;
    if (a[i][j] == 'L' and a[j][i] != 'W')
      ok = false;
    if (a[i][j] == '-' and a[j][i] != '-')
      ok = false;
    if (!ok)
    {
      cout << "incorrect" << endl;
      return 0;
    }
  }
  cout << "correct" << endl;
}