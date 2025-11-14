#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

string rotate(string s)
{
  return s.substr(1) + s[0];
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s, t;
  cin >> s >> t;
  rep(_, 0, s.size())
  {
    if (s == t)
    {
      cout << "Yes" << endl;
      return 0;
    }
    s = rotate(s);
  }
  cout << "No" << endl;
}