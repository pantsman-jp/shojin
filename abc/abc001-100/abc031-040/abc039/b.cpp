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
  int x;
  cin >> x;
  for (int n = 1; n * n * n * n <= x; n++)
    if (n * n * n * n == x)
      cout << n << endl;
}