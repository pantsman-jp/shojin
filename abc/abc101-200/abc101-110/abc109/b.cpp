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
  vector<string> w(n);
  rep(i, 0, n) cin >> w[i];
  map<string, int> cnt;
  rep(i, 1, n)
  {
    cnt[w[i - 1]]++;
    if (cnt[w[i]] == 1 or w[i][0] != w[i - 1].back())
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}