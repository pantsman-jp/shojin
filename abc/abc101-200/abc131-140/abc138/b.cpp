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
  double sum = 0;
  rep(_, 0, n)
  {
    double a;
    cin >> a;
    sum += 1.0 / a;
  }
  cout << fixed << setprecision(10) << 1.0 / sum << endl;
}