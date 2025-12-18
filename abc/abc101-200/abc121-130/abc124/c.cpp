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
  int n = s.size(), head0 = 0, head1 = 0;
  rep(i, 0, n)
  {
    if (i % 2 == 0)
    {
      if (s[i] == '0')
        head1++;
      else
        head0++;
    }
    else
    {
      if (s[i] == '0')
        head0++;
      else
        head1++;
    }
  }
  cout << min(head0, head1) << endl;
}