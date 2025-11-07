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
  string s, t;
  cin >> s >> t;
  vector<string> x;
  while (s != t)
  {
    string best = "";
    rep(i, 0, s.size())
    {
      if (s[i] != t[i])
      {
        string ns = s;
        ns[i] = t[i];
        if (best == "" or ns < best)
          best = ns;
      }
    }
    s = best, x.push_back(s);
  }
  cout << x.size() << endl;
  rep(i, 0, x.size()) cout << x[i] << endl;
}