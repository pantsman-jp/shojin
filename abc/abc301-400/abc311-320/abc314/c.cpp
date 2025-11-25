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
  string s;
  cin >> n >> m >> s;
  vector<int> c(n);
  rep(i, 0, n) cin >> c[i];
  map<int, vector<int>> c2i;
  rep(i, 0, n) c2i[c[i]].push_back(i);
  string result_s = s;
  rep(i, 1, m + 1)
  {
    vector<int> &indices = c2i[i];
    int k = indices.size();
    vector<char> chars_to_shift;
    rep(j, 0, k) chars_to_shift.push_back(result_s[indices[j]]);
    rep(j, 0, k) result_s[indices[j]] = chars_to_shift[(j + k - 1) % k];
  }
  cout << result_s << endl;
}