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
  vector<string> s(8);
  rep(i, 0, 8) cin >> s[i];
  rep(i, 0, 8) rep(j, 0, 8)
  {
    if (s[i][j] == '*')
    {
      cout << (char)('a' + j - 0) << 8 - i << endl;
      return 0;
    }
  }
}