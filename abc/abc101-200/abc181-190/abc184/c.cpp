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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int p = abs(c - a), q = abs(d - b), ans = 0;
  if (p == 0 and q == 0)
    ans = 0;
  else if (p == q or p + q <= 3)
    ans = 1;
  else if ((p + q) % 2 == 0 or p + q <= 6 or abs(p - q) <= 3)
    ans = 2;
  else
    ans = 3;
  cout << ans << endl;
}