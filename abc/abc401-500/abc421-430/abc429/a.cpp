#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  rep(i, 1, n + 1)
  {
    if (i <= m)
      cout << "OK" << endl;
    else
      cout << "Too Many Requests" << endl;
  }
}
