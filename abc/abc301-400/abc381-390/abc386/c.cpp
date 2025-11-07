#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int k;
  string s, t;
  cin >> k >> s >> t;
  if (s == t)
  {
    cout << "Yes" << endl;
    return 0;
  }
  if (s.size() == t.size())
  {
    int cnt = 0;
    rep(i, 0, s.size())
    {
      if (s[i] != t[i])
        cnt++;
    }
    if (cnt <= 1)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
    return 0;
  }
  if (s.size() < t.size())
    swap(s, t);
  if (s.size() != t.size() + 1)
  {
    cout << "No" << endl;
    return 0;
  }
  int maxl = 0, maxr = 0;
  rep(i, 0, t.size())
  {
    if (s[i] != t[i])
      break;
    maxl++;
  }
  for (int i = t.size() - 1; i >= 0; i--)
  {
    if (s[i + 1] != t[i])
      break;
    maxr++;
  }
  if (maxl + maxr >= t.size())
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}