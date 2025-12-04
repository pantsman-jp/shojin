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
  vector<bool> vol(n + 2);
  rep(i, 0, n)
  {
    int a;
    cin >> a;
    vol[min(n + 1, a)] = true;
  }
  for (int read = 1;; read++)
  {
    n--;
    if (!vol[read])
      n--;
    if (n < 0)
    {
      cout << read - 1 << endl;
      return 0;
    }
  }
}