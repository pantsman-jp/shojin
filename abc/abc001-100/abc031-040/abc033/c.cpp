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
  string s;
  cin >> s;
  int ans = 0;
  bool has0 = false;
  for (char c : s)
  {
    if (c == '+')
    {
      if (!has0)
        ans++;
      has0 = false;
    }
    else if (c == '0')
      has0 = true;
  }
  if (!has0)
    ans++;
  cout << ans << endl;
}