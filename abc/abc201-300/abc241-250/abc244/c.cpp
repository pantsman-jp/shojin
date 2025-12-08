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
  vector<bool> used(2 * n + 2);
  while (true)
  {
    int x = 0;
    rep(i, 1, 2 * n + 2)
    {
      if (!used[i])
      {
        x = i;
        break;
      }
    }
    cout << x << endl;
    used[x] = true;
    int aoki;
    cin >> aoki;
    if (aoki == 0)
      break;
    used[aoki] = true;
  }
}