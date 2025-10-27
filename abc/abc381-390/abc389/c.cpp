#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using ll = long long;
const ll inf = 1LL << 60;

deque<ll> x;
ll tx = 0;

void solve()
{
  int t;
  cin >> t;
  if (t == 1)
  {
    int L;
    cin >> L;
    x.push_back(tx), tx += L;
  }
  else if (t == 2)
    x.pop_front();
  else
  {
    int k;
    cin >> k;
    k--;
    cout << x[k] - x[0] << endl;
  }
}

int main()
{
  int q;
  cin >> q;
  rep(_, 0, q) solve();
}