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
  cin >> n;
  vector cnt(n, vector<int>(26));
  rep(i, 0, n)
  {
    string s;
    cin >> s;
    for (char c : s)
      cnt[i][c - 'a']++;
  }
  string ans = "";
  rep(i, 0, 26)
  {
    int m = cnt[0][i];
    rep(j, 0, n) m = min(m, cnt[j][i]);
    ans += string(m, 'a' + i);
  }
  cout << ans << endl;
}