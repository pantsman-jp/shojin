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
  if (n <= k)
  {
    rep(_, 0, n) cout << 0 << ' ';
    cout << endl;
    return 0;
  }
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, k, n) cout << a[i] << ' ';
  rep(_, 0, k) cout << 0 << ' ';
  cout << endl;
}