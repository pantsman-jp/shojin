#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h, w;
  cin >> h >> w;
  if (h == 1 or w == 1)
    cout << h * w << endl;
  else
    cout << ((h + 1) / 2) * ((w + 1) / 2) << endl;
}
