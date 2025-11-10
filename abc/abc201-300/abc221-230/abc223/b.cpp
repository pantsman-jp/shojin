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
  string s;
  cin >> s;
  string t = s;
  vector<string> v;
  rep(i, 0, s.size()) v.push_back(t), t = t.substr(1) + t[0];
  sort(all(v));
  cout << v.front() << endl;
  cout << v.back() << endl;
}