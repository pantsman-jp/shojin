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
  int i = 0, ans = 0;
  while (i < s.size())
  {
    if (s[i] == '0' and i + 1 < s.size() and s[i + 1] == '0')
      ans++, i += 2;
    else
      ans++, i++;
  }
  cout << ans << endl;
}