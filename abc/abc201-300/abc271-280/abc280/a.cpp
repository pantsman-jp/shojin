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
  int h, w, ans = 0;
  cin >> h >> w;
  rep(_, 0, h)
  {
    string s;
    cin >> s;
    rep(i, 0, w) if (s[i] == '#') ans++;
  }
  cout << ans << endl;
}