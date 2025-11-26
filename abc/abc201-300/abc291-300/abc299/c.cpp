#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

vector<pair<char, int>> run_length(string s)
{
  vector<pair<char, int>> ans;
  int cnt = 1;
  char now = s[0];
  rep(i, 1, s.size())
  {
    if (s[i] == now)
      cnt++;
    else
      ans.push_back({now, cnt}), now = s[i], cnt = 1;
  }
  ans.push_back({now, cnt});
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s;
  cin >> n >> s;
  int ans = -1;
  for (auto [c, m] : run_length(s))
    if (c == 'o')
      ans = max(ans, m);
  cout << ans << endl;
}