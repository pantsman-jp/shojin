#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

ll kto10(string s, ll k)
{
  ll ans = 0;
  for (char x : s)
    ans *= k, ans += x - '0';
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll k, x, y;
  string a, b;
  cin >> k >> a >> b;
  x = kto10(a, k), y = kto10(b, k);
  cout << x * y << endl;
}