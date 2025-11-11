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
  ll ans = 0;
  rep(i, 0, n)
  {
    ll a, b;
    cin >> a >> b;
    ans += (b - a + 1) * (a + b) / 2;
  }
  cout << ans << endl;
}