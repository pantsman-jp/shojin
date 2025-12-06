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
  vector<int> w(n);
  rep(i, 0, n) cin >> w[i];
  map<int, vector<int>> mp;
  rep(i, 0, n) mp[w[i]].push_back(i);
  int now = 0;
  rep(i, 0, n) if (s[i] == '1') now++;
  int ans = now;
  for (auto p : mp)
  {
    for (int i : p.second)
    {
      if (s[i] == '1')
        now--;
      else
        now++;
    }
    ans = max(ans, now);
  }
  cout << ans << endl;
}