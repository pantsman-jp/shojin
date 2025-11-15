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
  ll n, ans = inf;
  cin >> n;
  for (ll h = 1; h * h <= n; h++)
  {
    ll w = n / h;
    ans = min(ans, abs(h - w) + n - h * w);
  }
  cout << ans << endl;
}