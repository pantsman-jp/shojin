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
  vector<int> num(5);
  rep(i, 0, 5) cin >> num[i];
  vector<int> sum;
  rep(i, 0, 5) rep(j, i + 1, 5) rep(k, j + 1, 5) sum.push_back(num[i] + num[j] + num[k]);
  sort(all(sum));
  cout << sum[sum.size() - 3] << endl;
}