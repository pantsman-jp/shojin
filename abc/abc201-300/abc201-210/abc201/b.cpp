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
  vector<pair<int, string>> mt(n);
  rep(i, 0, n)
  {
    string s;
    int t;
    cin >> s >> t;
    mt[i] = make_pair(t, s);
  }
  sort(all(mt), greater<pair<int, string>>());
  cout << mt[1].second << endl;
}