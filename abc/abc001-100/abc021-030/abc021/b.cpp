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
  int n, a, b, k;
  cin >> n >> a >> b >> k;
  vector<bool> visited(n + 1);
  visited[a] = true, visited[b] = true;
  rep(_, 0, k)
  {
    int p;
    cin >> p;
    if (visited[p])
    {
      cout << "NO" << endl;
      return 0;
    }
    visited[p] = true;
  }
  cout << "YES" << endl;
}