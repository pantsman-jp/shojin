#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
#define yn(p) cout << (p ? "Yes" : "No") << '\n';
using ll = long long;
using P = pair<int, int>;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> p(n);
  rep(i, 0, n)
  {
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    p[i] = p1 + p2 + p3;
  }
  vector<int> q = p;
  sort(all(q), greater<int>());
  rep(i, 0, n) yn(p[i] + 300 >= q[k - 1])
}