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
  int cnt = 1;
  rep(i, 0, s.size())
  {
    if (i + 1 < s.size() and s[i] == s[i + 1])
      cnt++;
    else
      cout << s[i] << cnt, cnt = 1;
  }
  cout << endl;
}