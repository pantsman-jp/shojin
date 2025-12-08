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
  int n, k;
  cin >> n >> k;
  vector<string> s(n);
  rep(i, 0, n) cin >> s[i];
  int ans = 0;
  rep(bit, 0, 1 << n)
  {
    int tmp = 0;
    vector<int> cnt(26);
    rep(i, 0, n)
    {
      if (!(bit & (1 << i)))
        continue;
      for (char c : s[i])
        cnt[c - 'a']++;
    }
    rep(c, 0, 26) if (cnt[c] == k) tmp++;
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}