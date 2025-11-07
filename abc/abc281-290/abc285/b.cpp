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
  string s;
  cin >> n >> s;
  rep(i, 1, n) rep(j, 1, n + 1)
  {
    if (i + j > n)
    {
      cout << j - 1 << endl;
      break;
    }
    if (s[j - 1] == s[j + i - 1])
    {
      cout << j - 1 << endl;
      break;
    }
  }
}
