#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

bool in(char c)
{
  return c == 'a' or c == 't' or c == 'c' or c == 'o' or c == 'd' or c == 'e' or c == 'r';
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s, t;
  cin >> s >> t;
  map<char, int> cs, ct;
  int at_s = 0, at_t = 0;
  for (char c : s)
  {
    if (c == '@')
      at_s++;
    else
      cs[c]++;
  }
  for (char c : t)
  {
    if (c == '@')
      at_t++;
    else
      ct[c]++;
  }
  for (char c = 'a'; c <= 'z'; c++)
  {
    int diff = cs[c] - ct[c];
    if (diff > 0)
    {
      if (in(c))
        at_t -= diff;
      else
      {
        cout << "No" << endl;
        return 0;
      }
    }
    else if (diff < 0)
    {
      if (in(c))
        at_s += diff;
      else
      {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  if (at_s < 0 or at_t < 0)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;
}