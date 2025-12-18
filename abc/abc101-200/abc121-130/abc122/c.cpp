#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

vector<int> cnt;

void solve()
{
  int l, r;
  cin >> l >> r;
  cout << cnt[r] - cnt[l] << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  string s;
  cin >> n >> q >> s;
  cnt.resize(n + 1);
  rep(i, 2, n + 1)
  {
    cnt[i] = cnt[i - 1];
    if (s[i - 2] == 'A' and s[i - 1] == 'C')
      cnt[i]++;
  }
  rep(_, 0, q) solve();
}