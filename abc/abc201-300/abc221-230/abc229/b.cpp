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
  while (true)
  {
    if (a == 0 or b == 0)
    {
      cout << "Easy" << endl;
      return 0;
    }
    if (a % 10 + b % 10 > 9)
    {
      cout << "Hard" << endl;
      return 0;
    }
    a /= 10, b /= 10;
  }
}