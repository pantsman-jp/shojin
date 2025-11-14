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
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  rep(i, 1, n)
  {
    bool head[26] = {}, tail[26] = {};
    rep(j, 0, i) head[s[j] - 'a'] = true;
    rep(j, i, n) tail[s[j] - 'a'] = true;
    int cnt = 0;
    rep(c, 0, 26) if (head[c] and tail[c]) cnt++;
    ans = max(ans, cnt);
  }
  cout << ans << endl;
}