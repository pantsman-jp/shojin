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
  int n, m;
  cin >> n >> m;
  vector<bool> re(n + 1);
  rep(i, 0, m)
  {
    int a;
    cin >> a;
    re[a] = true;
  }
  vector<int> b;
  rep(i, 0, n + 1) if (!re[i]) b.push_back(i);
  vector<int> ans(n);
  rep(i, 0, n) ans[i] = i + 1;
  rep(i, 0, b.size() - 1) reverse(ans.begin() + b[i], ans.begin() + b[i + 1]);
  rep(i, 0, n) cout << ans[i] << ' ';
  cout << endl;
}