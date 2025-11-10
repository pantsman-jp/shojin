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
  ll x;
  cin >> x;
  if (x < 0 and x % 10 != 0)
    cout << x / 10 - 1 << endl;
  else
    cout << x / 10 << endl;
}