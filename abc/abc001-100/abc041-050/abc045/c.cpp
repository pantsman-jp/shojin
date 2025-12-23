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
  int n = s.size();
  ll ans = 0;
  rep(i, 0, 1 << (n - 1))
  {
    ll sm = 0, a = s[0] - '0';
    rep(j, 0, n - 1)
    {
      if (i & (1 << j))
        sm += a, a = 0;
      a = a * 10 + s[j + 1] - '0';
    }
    sm += a, ans += sm;
  }
  cout << ans << endl;
}