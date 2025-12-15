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
  int n, m;
  cin >> n >> m;
  vector<int> digit(n, -1);
  rep(_, 0, m)
  {
    int s, c;
    cin >> s >> c;
    if (digit[s - 1] != -1 and digit[s - 1] != c)
    {
      cout << -1 << endl;
      return 0;
    }
    digit[s - 1] = c;
  }
  if (n > 1 and digit[0] == 0)
  {
    cout << -1 << endl;
    return 0;
  }
  rep(i, 0, n)
  {
    if (digit[i] == -1)
    {
      if (i == 0 and n > 1)
        cout << 1;
      else
        cout << 0;
    }
    else
      cout << digit[i];
  }
  cout << endl;
}