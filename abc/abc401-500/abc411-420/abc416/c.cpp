#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const ll inf = 1LL << 60;

int n, k;
ll x;
vector<string> s, ans;

void dfs(string cur, int depth)
{
  if (depth == k)
  {
    ans.push_back(cur);
    return;
  }
  rep(i, n) dfs(cur + s[i], depth + 1);
}

int main()
{
  cin >> n >> k >> x;
  s.resize(n);
  rep(i, n) cin >> s[i];
  dfs("", 0);
  sort(ans.begin(), ans.end());
  cout << ans[x - 1] << endl;
}
