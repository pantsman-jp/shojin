#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

vector<int> di = {-1, -1, 1, 1}, dj = {-1, 1, -1, 1};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int h, w;
  cin >> h >> w;
  vector<string> a(h), b(h);
  rep(i, 0, h) cin >> a[i];
  rep(i, 0, h) cin >> b[i];
  rep(s, 0, h) rep(t, 0, w)
  {
    vector<string> na = a;
    rep(i, 0, h) rep(j, 0, w) na[(i + s) % h][(j + t) % w] = a[i][j];
    if (na == b)
    {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}