#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

vector<int> c, s, f;

int calc(int i, int t)
{
  return max((t + f[i] - 1) / f[i] * f[i], s[i]) + c[i];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  c.resize(n - 1), s.resize(n - 1), f.resize(n - 1);
  rep(i, 0, n - 1) cin >> c[i] >> s[i] >> f[i];
  rep(i, 0, n)
  {
    int ans = 0;
    rep(j, i, n - 1) ans = calc(j, ans);
    cout << ans << endl;
  }
}