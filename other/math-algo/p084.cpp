#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll a, b, c;
  cin >> a >> b >> c;
  if (c - a - b > 0 and 4 * a * b < (c - a - b) * (c - a - b))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}