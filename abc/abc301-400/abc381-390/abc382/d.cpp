#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a) - 1; i >= b; i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
// const ll mod = 998244353;
// const ll mod = 1000000007;

int n, m;
vector<vector<int>> ans;

void dfs(vector<int> &a)
{
  if ((int)a.size() == n)
  {
    ans.push_back(a);
    return;
  }
  int last, remain = n - a.size() - 1, sup = m - 10 * remain;
  if (a.empty())
    last = 1;
  else
    last = a.back() + 10;
  rep(v, last, sup + 1)
  {
    a.push_back(v);
    dfs(a);
    a.pop_back();
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  vector<int> a;
  dfs(a);
  cout << ans.size() << endl;
  for (vector<int> xs : ans)
  {
    for (int x : xs)
      cout << x << ' ';
    cout << endl;
  }
}