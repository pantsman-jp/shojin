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
  string s;
  cin >> s;
  ll n = s.size(), ans = 0, p = 1, v = 0;
  rep(i, 1, n) p *= 26, ans += p;
  for (char c : s)
    v = v * 26 + (c - 'A');
  cout << ans + v + 1 << endl;
}