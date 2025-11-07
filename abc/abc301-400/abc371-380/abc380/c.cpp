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
  string s;
  cin >> n >> k >> s;
  k--;
  vector<pair<int, int>> mass;
  rep(i, 0, n)
  {
    if (s[i] == '1')
    {
      int l = i;
      while (i < n and s[i] == '1')
        i++;
      mass.push_back({l, i - 1});
    }
  }
  int l1 = mass[k - 1].first, r1 = mass[k - 1].second;
  int l2 = mass[k].first, r2 = mass[k].second;
  string ans;
  ans.reserve(n);
  ans += s.substr(0, r1 + 1);
  ans += string(r2 - l2 + 1, '1');
  ans += s.substr(r1 + 1, l2 - r1 - 1);
  ans += s.substr(r2 + 1);
  cout << ans << endl;
}
