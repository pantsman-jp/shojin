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
  map<int, int> mp;
  rep(i, 0, n)
  {
    int a;
    cin >> a;
    mp[a]++;
  }
  vector<int> ans;
  for (auto p : mp)
    ans.push_back(p.second);
  reverse(all(ans));
  while (ans.size() < n)
    ans.push_back(0);
  rep(k, 0, n) cout << ans[k] << endl;
}