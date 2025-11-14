#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

bool check(string s)
{
  return s.substr(0, s.size() / 2) == s.substr(s.size() / 2);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  int n = s.size();
  rep(i, 1, n)
  {
    string ans = s.substr(0, n - i * 2);
    if (check(ans))
    {
      cout << ans.size() << endl;
      return 0;
    }
  }
}