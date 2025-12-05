#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int cross(P a, P b, P c)
{
  return (b.first - a.first) * (c.second - b.second) - (b.second - a.second) * (c.first - b.first);
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  P A, B, C, D;
  cin >> A.first >> A.second >> B.first >> B.second >> C.first >> C.second >> D.first >> D.second;
  vector<P> points = {A, B, C, D};
  bool convex = true;
  rep(i, 0, 4)
  {
    if (cross(points[i], points[(i + 1) % 4], points[(i + 2) % 4]) <= 0)
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}