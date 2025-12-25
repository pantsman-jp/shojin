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
  int m = 2025 - n;
  rep(i, 1, 10)
  {
    if (m % i == 0 and m / i < 10)
      cout << i << " x " << m / i << endl;
  }
}