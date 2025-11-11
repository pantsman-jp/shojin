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
  int n;
  cin >> n;
  vector<ll> x(n);
  rep(i, 0, n)
  {
    ll absx;
    cin >> absx;
    x[i] = abs(absx);
  }
  cout << fixed << setprecision(10) << reduce(all(x)) << endl;
  ll square = 0;
  rep(i, 0, n) square += x[i] * x[i];
  cout << fixed << setprecision(10) << sqrt(square) << endl;
  cout << fixed << setprecision(10) << *max_element(all(x)) << endl;
}