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
  int n, q;
  cin >> n >> q;
  vector<int> a(n + 1), pos(n + 1);
  rep(i, 1, n + 1) a[i] = i, pos[i] = i;
  rep(_, 0, q)
  {
    int x;
    cin >> x;
    int i = pos[x];
    int j = i + 1;
    if (i == n)
      j = i - 1;
    int y = a[j];
    swap(a[i], a[j]);
    pos[x] = j, pos[y] = i;
  }
  rep(i, 1, n + 1) cout << a[i] << ' ';
  cout << endl;
}