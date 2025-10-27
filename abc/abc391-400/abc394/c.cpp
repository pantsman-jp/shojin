#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  string s;
  cin >> s;
  int n = s.size(), w = 0;
  rep(i, 0, n)
  {
    if (s[i] == 'W')
      w++;
    else
    {
      if (s[i] == 'A')
      {
        rep(j, i - w + 1, i + 1) s[j] = 'C';
        s[i - w] = 'A';
      }
      w = 0;
    }
  }
  cout << s << endl;
}