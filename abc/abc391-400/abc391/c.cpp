#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

vector<int> pos, cnt;
int ans = 0;

void solve()
{
  int t, p, h;
  cin >> t;
  if (t == 1)
  {
    cin >> p >> h;
    p--, h--;
    if (cnt[pos[p]] == 2)
      ans--;
    cnt[pos[p]]--, pos[p] = h, cnt[h]++;
    if (cnt[h] == 2)
      ans++;
  }
  else
    cout << ans << endl;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  pos.resize(n), cnt.resize(n, 1);
  rep(i, 0, n) pos[i] = i;
  rep(_, 0, q) solve();
}