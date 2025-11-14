#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

string solve(string s)
{
  int n = s.length();
  if (s[0] != 'A')
    return "WA";
  if (s[1] < 'a' or 'z' < s[1])
    return "WA";
  if (s[n - 1] < 'a' or 'z' < s[n - 1])
    return "WA";
  int c = 0, x = 0;
  rep(i, 2, n - 1)
  {
    if ('a' <= s[i] and s[i] <= 'z')
      x++;
    else if (s[i] == 'C')
      c++;
    else
      return "WA";
  }
  if (c == 1)
    return "AC";
  return "WA";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  cout << solve(s) << endl;
}