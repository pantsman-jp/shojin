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
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  vector<ll> prod = {a * c, a * d, b * c, b * d};
  cout << *max_element(all(prod)) << endl;
}