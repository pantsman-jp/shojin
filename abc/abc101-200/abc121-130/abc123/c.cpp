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
  ll n, a, b, c, d, e;
  cin >> n >> a >> b >> c >> d >> e;
  ll mini = min(a, min(b, min(c, min(d, e))));
  cout << (n + mini - 1) / mini + 4 << endl;
}