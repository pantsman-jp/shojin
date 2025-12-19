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
  int a, b, c;
  cin >> a >> b >> c;
  int sum = a + b + c, m = max(a, max(b, c)), x = m;
  while ((3 * x - sum) % 2 != 0)
    x++;
  cout << (3 * x - sum) / 2 << endl;
}