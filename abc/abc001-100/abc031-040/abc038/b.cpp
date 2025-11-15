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
  int h1, w1, h2, w2;
  cin >> h1 >> w1 >> h2 >> w2;
  if (h1 == h2 or h1 == w2 or w1 == h2 or w1 == w2)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}