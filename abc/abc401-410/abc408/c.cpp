#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<int> imos(n + 2);
  rep(i, 0, m)
  {
    int l, r;
    cin >> l >> r;
    imos[l]++, imos[r + 1]--;
  }
  vector<int> sum(n + 1);
  sum[0] = imos[0];
  rep(i, 1, n + 1) sum[i] = sum[i - 1] + imos[i];
  cout << *min_element(sum.begin() + 1, sum.begin() + n + 1) << endl;
}
