#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

char op(char c)
{
  if (c == 'z')
    return 'a';
  return c + 1;
}

char ops(char c, int n)
{
  if (n % 26 == 0)
    return c;
  char ans = c;
  rep(_, 0, n % 26) ans = op(ans);
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s, t;
  cin >> s >> t;
  rep(k, 0, 26)
  {
    string ns = "";
    rep(i, 0, s.size()) ns += ops(s[i], k);
    if (ns == t)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}