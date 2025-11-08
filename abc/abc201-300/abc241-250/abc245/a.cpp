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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a < c)
    cout << "Takahashi" << endl;
  if (a > c)
    cout << "Aoki" << endl;
  if (a == c and b <= d)
    cout << "Takahashi" << endl;
  if (a == c and b > d)
    cout << "Aoki" << endl;
}