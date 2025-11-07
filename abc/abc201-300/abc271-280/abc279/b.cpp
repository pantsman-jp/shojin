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
  int n = s.size(), m = t.size();
  if (n < m)
  {
    cout << "No" << endl;
    return 0;
  }
  rep(i, 0, n - m + 1)
  {
    if (s.substr(i, m) == t)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}