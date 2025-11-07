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
  reverse(all(s));
  rep(i, 0, s.size())
  {
    if (s[i] == 'a')
    {
      cout << s.size() - i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}