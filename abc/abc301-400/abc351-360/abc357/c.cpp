#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

vector<string> levelup(vector<string> s)
{
  int n = s.size();
  vector<string> ans(n * 3);
  rep(i, 0, 3 * n) rep(j, 0, 3 * n)
  {
    if (i >= n and i < n * 2 and j >= n and j < n * 2)
      ans[i] += ".";
    else
      ans[i] += s[i % n][j % n];
  }
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<string> ans(1, "#");
  rep(i, 0, n) ans = levelup(ans);
  for (string s : ans)
    cout << s << endl;
}