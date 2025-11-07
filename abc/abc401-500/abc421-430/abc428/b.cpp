#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  int n, k;
  string s;
  cin >> n >> k >> s;
  map<string, int> cnt;
  rep(i, n - k + 1)
  {
    string t = s.substr(i, k);
    cnt[t]++;
  }
  int x = -1;
  for (auto [t, c] : cnt)
    x = max(x, c);
  vector<string> ans;
  for (auto [t, c] : cnt)
    if (c == x)
      ans.push_back(t);
  sort(ans.begin(), ans.end());
  cout << x << endl;
  for (string t : ans)
    cout << t << ' ';
  cout << endl;
}
