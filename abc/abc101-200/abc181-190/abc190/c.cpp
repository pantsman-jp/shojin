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
  int n, m;
  cin >> n >> m;
  vector<P> ab(m);
  rep(i, 0, m) cin >> ab[i].first >> ab[i].second;
  int k;
  cin >> k;
  vector<P> cd(k);
  rep(i, 0, k) cin >> cd[i].first >> cd[i].second;
  int ans = 0;
  rep(bit, 0, 1 << k)
  {
    vector<bool> ball(n);
    rep(i, 0, k)
    {
      const auto [c, d] = cd[i];
      if (bit & (1 << i))
        ball[c] = true;
      else
        ball[d] = true;
    }
    int cnt = 0;
    for (auto [a, b] : ab)
      if (ball[a] and ball[b])
        cnt++;
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}