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
  int l, r;
  string s;
  cin >> l >> r >> s;
  l--, r--;
  rep(i, 0, s.size())
  {
    if (l <= i and i <= r)
      cout << s[r - i + l];
    else
      cout << s[i];
  }
  cout << endl;
}