#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

bool p(char c)
{
  return c == 'A' or c == 'C' or c == 'G' or c == 'T';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int ans = 0, cur = 0;
  for (char c : s)
  {
    if (p(c))
      cur++;
    else
      cur = 0;
    ans = max(ans, cur);
  }
  cout << ans << endl;
}