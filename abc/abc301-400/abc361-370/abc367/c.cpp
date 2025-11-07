#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

void dfs(vector<int> &a, int k, const vector<int> &r, int sum)
{
  if (a.size() == r.size())
  {
    if (sum % k == 0)
    {
      rep(i, 0, a.size()) cout << a[i] << " ";
      cout << endl;
    }
    return;
  }
  rep(v, 1, r[a.size()] + 1) a.push_back(v), dfs(a, k, r, sum + v), a.pop_back();
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> r(n), a;
  rep(i, 0, n) cin >> r[i];
  dfs(a, k, r, 0);
}