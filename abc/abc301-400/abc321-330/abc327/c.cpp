#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

bool check(vector<int> xs)
{
  map<int, int> cnt;
  rep(i, 1, 10) cnt[i] = 0;
  for (int x : xs)
  {
    cnt[x]++;
    if (cnt[x] > 1)
      return false;
  }
  return true;
}

bool solve(vector<vector<int>> xs)
{
  rep(i, 0, 9)
  {
    if (!check(xs[i]))
      return false;
  }
  rep(j, 0, 9)
  {
    vector<int> line;
    rep(i, 0, 9) line.push_back(xs[i][j]);
    if (!check(line))
      return false;
  }
  rep(i, 0, 3) rep(j, 0, 3)
  {
    vector<int> block;
    rep(i2, 0, 3) rep(j2, 0, 3) block.push_back(xs[i * 3 + i2][j * 3 + j2]);
    if (!check(block))
      return false;
  }
  return true;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<vector<int>> a(9, vector<int>(9));
  rep(i, 0, 9) rep(j, 0, 9) cin >> a[i][j];
  if (solve(a))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}