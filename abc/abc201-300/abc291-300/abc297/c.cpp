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
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, 0, h) cin >> s[i];
  rep(i, 0, h) rep(j, 0, w - 1)
  {
    if (s[i][j] == 'T' and s[i][j + 1] == 'T')
      s[i][j] = 'P', s[i][j + 1] = 'C';
  }
  rep(i, 0, h) cout << s[i] << endl;
}