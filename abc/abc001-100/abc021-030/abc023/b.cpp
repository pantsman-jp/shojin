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
  string s;
  cin >> n >> s;
  string t = "b";
  int ans = 0;
  while (t.size() < s.size())
  {
    if (ans % 3 == 0)
      t = "a" + t + "c";
    else if (ans % 3 == 1)
      t = "c" + t + "a";
    else
      t = "b" + t + "b";
    ans++;
  }
  if (s == t)
    cout << ans << endl;
  else
    cout << -1 << endl;
}