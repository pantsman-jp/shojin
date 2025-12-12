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
  int n, k;
  cin >> n >> k;
  vector<int> c(n);
  rep(i, 0, n) cin >> c[i];
  map<int, int> nums;
  int ans = 0;
  rep(i, 0, n)
  {
    nums[c[i]]++;
    if (i >= k)
    {
      nums[c[i - k]]--;
      if (nums[c[i - k]] == 0)
        nums.erase(c[i - k]);
    }
    ans = max(ans, (int)nums.size());
  }
  cout << ans << endl;
}