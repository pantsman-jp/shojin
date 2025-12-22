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
  int p = 0, q = 0, r = 0;
  rep(i, 0, n)
  {
    int a;
    cin >> a;
    if (a % 4 == 0)
      p++;
    else if (a % 2 == 0)
      q++;
    else
      r++;
  }
  if (q > 1)
    q = 1;
  if (p >= r + q - 1)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}