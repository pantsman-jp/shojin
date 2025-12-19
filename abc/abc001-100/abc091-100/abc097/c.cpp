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
  string s;
  int k;
  cin >> s >> k;
  set<string> subs;
  rep(i, 0, s.size()) rep(j, 1, k + 1) subs.insert(s.substr(i, j));
  vector<string> ans(all(subs));
  cout << ans[k - 1] << endl;
}