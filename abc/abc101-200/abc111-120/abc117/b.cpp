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
  int n;
  cin >> n;
  vector<int> l(n);
  rep(i, 0, n) cin >> l[i];
  if (*max_element(all(l)) * 2 < reduce(all(l)))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}