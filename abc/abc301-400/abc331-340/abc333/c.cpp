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
  vector<ll> repunit;
  rep(i, 0, 12) repunit.push_back(stoll(string(i + 1, '1')));
  rep(i, 0, 12) rep(j, 0, i + 1) rep(k, 0, j + 1)
  {
    n--;
    if (n == 0)
    {
      cout << repunit[i] + repunit[j] + repunit[k] << endl;
      return 0;
    }
  }
}