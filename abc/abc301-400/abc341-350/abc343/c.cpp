#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

bool is_pali(string s)
{
  string t = s;
  reverse(all(t));
  return s == t;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  ll ans = 0;
  for (ll i = 1; i * i * i <= n; i++)
    if (is_pali(to_string(i * i * i)))
      ans = i * i * i;
  cout << ans << endl;
}