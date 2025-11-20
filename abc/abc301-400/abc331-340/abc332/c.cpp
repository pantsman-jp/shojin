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
  int n, m;
  string s;
  cin >> n >> m >> s;
  int plane = m, logo = 0, ans = 0;
  for (char c : s)
  {
    if (c == '0')
      plane = m, ans = min(ans, logo), logo = 0;
    else if (c == '1')
    {
      if (plane > 0)
        plane--;
      else
        logo--;
    }
    else
      logo--;
  }
  cout << abs(min(ans, logo)) << endl;
}