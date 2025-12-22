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
  map<int, int> cnt;
  rep(_, 0, n)
  {
    int a;
    cin >> a;
    cnt[a]++;
  }
  int ans = 0;
  if (cnt.size() > k)
  {
    vector<int> v;
    for (auto [_, c] : cnt)
      v.push_back(c);
    sort(all(v));
    rep(i, 0, cnt.size() - k) ans += v[i];
  }
  cout << ans << endl;
}