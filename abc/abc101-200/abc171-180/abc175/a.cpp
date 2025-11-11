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
  bool p = s[0] == 'R', q = s[1] == 'R', r = s[2] == 'R';
  if (p and q and r)
    cout << 3 << endl;
  else if ((p and q) or (q and r))
    cout << 2 << endl;
  else if (p or q or r)
    cout << 1 << endl;
  else
    cout << 0 << endl;
}