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
  map<string, int> cnt;
  rep(_, 0, n)
  {
    string s;
    cin >> s;
    cnt[s]++;
  }
  int best = 0;
  vector<string> ans;
  for (auto [s, c] : cnt)
  {
    if (c < best)
      continue;
    else if (c == best)
      ans.push_back(s);
    else
      best = c, ans = {}, ans.push_back(s);
  }
  sort(all(ans));
  for (string s : ans)
    cout << s << endl;
}