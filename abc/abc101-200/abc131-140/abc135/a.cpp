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
  ll a, b;
  cin >> a >> b;
  if ((a + b) % 2 == 0)
    cout << (a + b) / 2 << endl;
  else
    cout << "IMPOSSIBLE" << endl;
}