#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
using ld = long double;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ld a, b, c, x;
  cin >> a >> b >> c >> x;
  if (x <= a)
    cout << fixed << setprecision(10) << (ld)1.0 << endl;
  else if (x <= b)
    cout << fixed << setprecision(10) << c / (b - a) << endl;
  else
    cout << fixed << setprecision(10) << (ld)0.0 << endl;
}