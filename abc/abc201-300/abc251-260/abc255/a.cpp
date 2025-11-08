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
  int r, c;
  cin >> r >> c;
  r--, c--;
  vector<vector<int>> a(2, vector<int>(2));
  rep(i, 0, 2) rep(j, 0, 2) cin >> a[i][j];
  cout << a[r][c] << endl;
}