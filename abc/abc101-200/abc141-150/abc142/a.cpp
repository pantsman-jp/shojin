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
  int odd = 0;
  rep(a, 1, n + 1) if (a % 2 != 0) odd++;
  cout << fixed << setprecision(10) << odd * 1.0 / n * 1.0 << endl;
}