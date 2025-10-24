#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  string s;
  cin >> n >> s;
  vector<pair<char, ll>> vec;
  ll cnt = 1;
  for (int i = 1; i < n; i++)
  {
    if (s[i] == s[i - 1])
      cnt++;
    else
      vec.push_back({s[i - 1], cnt}), cnt = 1;
  }
  vec.push_back({s[n - 1], cnt});
  ll same = 0;
  for (auto &p : vec)
    same += p.second * (p.second + 1) / 2;
  ll total = n * (n + 1) / 2;
  cout << total - same << endl;
}
