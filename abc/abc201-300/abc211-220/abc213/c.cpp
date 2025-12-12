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
  int h, w, n;
  cin >> h >> w >> n;
  vector<int> a(n), b(n);
  rep(i, 0, n) cin >> a[i] >> b[i];
  vector<int> x = a, y = b;
  sort(all(x)), x.erase(unique(all(x)), x.end());
  sort(all(y)), y.erase(unique(all(y)), y.end());
  rep(i, 0, n)
  {
    cout << lower_bound(all(x), a[i]) - x.begin() + 1 << ' ';
    cout << lower_bound(all(y), b[i]) - y.begin() + 1 << endl;
  }
}