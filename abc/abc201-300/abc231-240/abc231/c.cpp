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
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];
  sort(all(a));
  rep(_, 0, q)
  {
    int x;
    cin >> x;
    cout << n - (lower_bound(all(a), x) - a.begin()) << endl;
  }
}