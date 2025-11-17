#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int n, a, b, ans = 0;

int f(int d)
{
  if (d < a)
    return a;
  if (b < d)
    return b;
  return d;
}

void solve()
{
  string s;
  int d;
  cin >> s >> d;
  if (s == "East")
    ans += f(d);
  else
    ans -= f(d);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> a >> b;
  rep(_, 0, n) solve();
  if (ans == 0)
    cout << 0 << endl;
  else if (ans < 0)
    cout << "West " << -ans << endl;
  else
    cout << "East " << ans << endl;
}