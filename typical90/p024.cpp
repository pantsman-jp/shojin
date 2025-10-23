#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n), b(n);
  rep(i, 0, n) cin >> a[i];
  rep(i, 0, n) cin >> b[i];
  long long diff = 0;
  rep(i, 0, n) diff += abs(a[i] - b[i]);
  if (diff > k)
  {
    cout << "No" << endl;
    return 0;
  }
  if (diff % 2 != k % 2)
  {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
}
