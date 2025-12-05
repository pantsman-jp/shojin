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
  int n, m;
  cin >> n >> m;
  vector<int> a;
  rep(i, 0, n) a.push_back(0);
  rep(i, 0, m - n) a.push_back(1);
  do
  {
    rep(i, 0, m) if (a[i] == 0) cout << i + 1 << " ";
    cout << endl;
  } while (next_permutation(all(a)));
}