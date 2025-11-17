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
  int ans = 0;
  rep(_, 0, 3)
  {
    int s, e;
    cin >> s >> e;
    ans += s / 10 * e;
  }
  cout << ans << endl;
}