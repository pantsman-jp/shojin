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
  if (k >= n)
  {
    cout << 0 << endl;
    return 0;
  }
  vector<ll> h(n);
  rep(i, 0, n) cin >> h[i];
  sort(all(h));
  cout << reduce(h.begin(), h.begin() + n - k) << endl;
}