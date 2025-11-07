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
  vector<int> x(5 * n);
  rep(i, 0, 5 * n) cin >> x[i];
  sort(all(x));
  int sum = 0;
  rep(i, n, 4 * n) sum += x[i];
  printf("%.10f\n", sum / (3.0 * n));
}