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
  string s;
  cin >> s;
  int ans = 0;
  rep(pass, 0, 10000)
  {
    vector<int> a(10);
    int x = pass;
    rep(_, 0, 4) a[x % 10] = 1, x /= 10;
    bool ok = true;
    rep(i, 0, 10) if ((s[i] == 'o' and a[i] != 1) or (s[i] == 'x' and a[i] != 0)) ok = false;
    if (ok)
      ans++;
  }
  cout << ans << endl;
}