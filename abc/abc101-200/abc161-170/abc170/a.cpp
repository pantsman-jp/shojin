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
  rep(i, 1, 6)
  {
    int x;
    cin >> x;
    if (x == 0)
    {
      cout << i << endl;
      return 0;
    }
  }
}