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
  ll t = 0;
  rep(i, 0, n)
  {
    ll h;
    cin >> h;
    t += (h / 5) * 3, h %= 5;
    while (h > 0)
    {
      t++;
      if (t % 3 == 0)
        h -= 3;
      else
        h--;
    }
  }
  cout << t << endl;
}