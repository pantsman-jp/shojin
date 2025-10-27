#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> p(n), diff;
  rep(i, 0, n) cin >> p[i];
  rep(i, 0, n - 1) diff.push_back(p[i] < p[i + 1] ? 0 : 1);
  vector<pair<int, int>> rle;
  for (int x : diff)
  {
    if (rle.size() and rle.back().first == x)
      rle.back().second++;
    else
      rle.emplace_back(x, 1);
  }
  ll ans = 0;
  rep(i, 0, rle.size())
  {
    if (rle[i].first == 1)
    {
      ll l = 0, r = 0;
      if (0 < i)
        l = rle[i - 1].second;
      if (i + 1 < rle.size())
        r = rle[i + 1].second;
      ans += l * r;
    }
  }
  cout << ans << endl;
}