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
  ld a, b;
  cin >> a >> b;
  ld d = sqrt(a * a + b * b);
  cout << fixed << setprecision(10) << a / d << ' ' << b / d << endl;
}