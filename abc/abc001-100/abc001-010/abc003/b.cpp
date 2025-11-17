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
  vector<char> chars = {'a', 't', 'c', 'o', 'd', 'e', 'r'};
  rep(i, 0, s.size())
  {
    if (s[i] == t[i])
      continue;
    else if (s[i] == '@' and find(all(chars), t[i]) != chars.end())
      continue;
    else if (t[i] == '@' and find(all(chars), s[i]) != chars.end())
      continue;
    else
    {
      cout << "You will lose" << endl;
      return 0;
    }
  }
  cout << "You can win" << endl;
}