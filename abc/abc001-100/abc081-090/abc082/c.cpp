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
  map<int, int> cnt;
  rep(_, 0, n)
  {
    int a;
    cin >> a;
    cnt[a]++;
  }
  int ans = 0;
  for (auto [a, c] : cnt)
  {
    if (a > c)
      ans += c;
    else if (a < c)
      ans += c - a;
  }
  cout << ans << endl;
}