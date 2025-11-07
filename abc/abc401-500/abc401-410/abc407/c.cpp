#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  ll ans = 0, x = 0;
  while (!s.empty())
  {
    int d = s.back() - '0';
    while ((d - x) % 10 != 0)
      ans++, x = (x + 1) % 10;
    s.pop_back(), ans++;
  }
  cout << ans << endl;
}