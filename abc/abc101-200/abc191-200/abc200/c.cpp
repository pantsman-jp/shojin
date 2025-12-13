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
  map<int, ll> cnt;
  rep(_, 0, n)
  {
    int a;
    cin >> a;
    cnt[a % 200]++;
  }
  ll ans = 0;
  for (auto [_, c] : cnt)
    ans += c * (c - 1) / 2;
  cout << ans << endl;
}