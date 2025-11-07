#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int n;
vector<bool> grid;

void op()
{
  int l;
  cin >> l;
  rep(i, 0, n)
  {
    if (grid[i])
      l--;
    if (l == 0 and i != n - 1 and !grid[i + 1])
      grid[i] = false, grid[i + 1] = true;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int k, q;
  cin >> n >> k >> q;
  grid.resize(n, false);
  rep(_, 0, k)
  {
    int a;
    cin >> a;
    a--;
    grid[a] = true;
  }
  rep(_, 0, q) op();
  rep(i, 0, n) if (grid[i]) cout << i + 1 << ' ';
  cout << endl;
}