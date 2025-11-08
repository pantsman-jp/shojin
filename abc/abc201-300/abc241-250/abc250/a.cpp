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
  int h, w, r, c, ans = 0;
  cin >> h >> w >> r >> c;
  if (c != 1)
    ans++;
  if (c != w)
    ans++;
  if (r != 1)
    ans++;
  if (r != h)
    ans++;
  cout << ans << endl;
}