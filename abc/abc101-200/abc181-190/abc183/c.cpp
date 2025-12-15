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
  int n, k;
  cin >> n >> k;
  vector t(n, vector<int>(n));
  rep(i, 0, n) rep(j, 0, n) cin >> t[i][j];
  int ans = 0;
  vector<int> ids(n - 1);
  rep(i, 0, n - 1) ids[i] = i + 1;
  do
  {
    int time = 0, from = 0;
    rep(i, 0, n - 1) time += t[from][ids[i]], from = ids[i];
    time += t[ids.back()][0];
    if (time == k)
      ans++;
  } while (next_permutation(all(ids)));
  cout << ans << endl;
}