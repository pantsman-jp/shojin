#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  map<int, ll> cnt;
  rep(i, 0, n)
  {
    int a;
    cin >> a;
    cnt[a]++;
  }
  ll ans = n * (n - 1) / 2;
  for (auto [_, c] : cnt)
    ans -= c * (c - 1) / 2;
  cout << ans << endl;
}