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
  int n, p, q, r, s;
  cin >> n >> p >> q >> r >> s;
  p--, q--, r--, s--;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, p, q + 1) swap(a[i], a[(i - p) + r]);
  rep(i, 0, n) cout << a[i] << ' ';
  cout << endl;
}