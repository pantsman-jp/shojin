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
  string s;
  cin >> n >> s;
  vector<char> ans;
  rep(i, 0, n)
  {
    if (1 <= i and ans.back() == 'n' and s[i] == 'a')
      ans.push_back('y');
    ans.push_back(s[i]);
  }
  for (char c : ans)
    cout << c;
  cout << endl;
}