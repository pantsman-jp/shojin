#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

vector<pair<char, int>> rle(string s)
{
  vector<pair<char, int>> ans;
  int cnt = 1;
  char now = s[0];
  rep(i, 1, s.size())
  {
    if (s[i] == now)
      cnt++;
    else
      ans.push_back({now, cnt}), now = s[i], cnt = 1;
  }
  ans.push_back({now, cnt});
  return ans;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  cout << rle(s).size() - 1 << endl;
}