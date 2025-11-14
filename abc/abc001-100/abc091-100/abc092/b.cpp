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
  int n, d, x;
  cin >> n >> d >> x;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  int cnt = 0;
  rep(i, 0, n) rep(j, 0, 100) if (j * a[i] + 1 <= d) cnt++;
  cout << x + cnt << endl;
}