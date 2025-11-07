#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;
const double pi = acos(-1);

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int a, b, d;
  cin >> a >> b >> d;
  double theta = d * pi / 180;
  printf("%.10f ", a * cos(theta) - b * sin(theta));
  printf("%.10f\n", a * sin(theta) + b * cos(theta));
}