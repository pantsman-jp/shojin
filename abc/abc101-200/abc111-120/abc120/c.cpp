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
  int zero = 0, one = 0;
  rep(i, 0, s.size())
  {
    if (s[i] == '0')
      zero++;
    else
      one++;
  }
  cout << min(zero, one) * 2 << endl;
}