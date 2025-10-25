#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> uses(n + 1);
  vector<int> rem(m);
  rep(i, m)
  {
    int k;
    cin >> k;
    rem[i] = k;
    rep(j, k)
    {
      int a;
      cin >> a;
      uses[a].push_back(i);
    }
  }
  vector<int> B(n);
  rep(i, n) cin >> B[i];
  int ans = 0;
  rep(day, n)
  {
    int x = B[day];
    for (int dish : uses[x])
    {
      rem[dish]--;
      if (rem[dish] == 0)
        ans++;
    }
    cout << ans << endl;
  }
}
