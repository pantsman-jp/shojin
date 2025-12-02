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
  ll a, b, ans = inf;
  string s;
  cin >> n >> a >> b >> s;
  s += s;
  rep(i, 0, n)
  {
    ll tmp = a * i;
    rep(j, 0, n / 2) if (s[i + j] != s[i + n - 1 - j]) tmp += b;
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}