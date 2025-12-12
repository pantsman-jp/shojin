#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;
const ll mod = 1e9 + 7;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> c(n);
  rep(i, 0, n) cin >> c[i];
  sort(all(c));
  ll ans = 1;
  rep(i, 0, n) ans = (ans * max(0, c[i] - i)) % mod;
  cout << ans << endl;
}