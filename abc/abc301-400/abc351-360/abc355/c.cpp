#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

int n;
vector<set<int>> lines;

bool check(int id, int val, int i)
{
  lines[id].insert(val);
  return lines[id].size() >= n;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> n >> t;
  lines.resize(n * 2 + 2);
  rep(i, 1, t + 1)
  {
    int a;
    cin >> a;
    a--;
    int x = a / n, y = a % n;
    if (check(x, a, i) or check(y + n, a, i) or (x == y and check(n * 2, a, i)) or (x + y == n - 1 and check(n * 2 + 1, a, i)))
    {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}