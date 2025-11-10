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
  ll n, pow2 = 1, k = 0;
  cin >> n;
  while (true)
  {
    if (pow2 > n)
    {
      cout << k - 1 << endl;
      return 0;
    }
    pow2 *= 2, k++;
  }
}