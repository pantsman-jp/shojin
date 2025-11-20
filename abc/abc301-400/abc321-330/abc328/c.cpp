#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

vector<int> sum;

void solve()
{
  int l, r;
  cin >> l >> r;
  l--, r--;
  cout << sum[r] - sum[l] << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  string s;
  cin >> n >> q >> s;
  sum.resize(n);
  rep(i, 0, n - 1) sum[i + 1] = sum[i] + (int)(s[i + 1] == s[i]);
  rep(_, 0, q) solve();
}