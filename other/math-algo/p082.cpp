#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<pair<ll, ll>> lr(n);
  rep(i, 0, n) cin >> lr[i].first >> lr[i].second;
  sort(lr.begin(), lr.end(), [](const pair<int, int> &a, const pair<int, int> &b)
       { return a.second < b.second; });
  int current_time = 0, ans = 0;
  for (auto &m : lr)
    if (m.first >= current_time)
      current_time = m.second, ans++;
  cout << ans << endl;
}
