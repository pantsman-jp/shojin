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
  int n, k;
  cin >> n >> k;
  vector<ll> cnt(k);
  rep(i, 1, n + 1) cnt[i % k]++;
  ll ans = 0;
  rep(a, 0, k)
  {
    int b = (k - a) % k, c = (k - a) % k;
    if ((b + c) % k != 0)
      continue;
    ans += cnt[a] * cnt[b] * cnt[c];
  }
  cout << ans << endl;
}