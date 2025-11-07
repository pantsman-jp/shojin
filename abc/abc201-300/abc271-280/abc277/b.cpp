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
  map<string, int> cnt;
  rep(_, 0, n)
  {
    string s;
    cin >> s;
    cnt[s]++;
    if (cnt[s] == 2)
    {
      cout << "No" << endl;
      return 0;
    }
    char c1 = s[0], c2 = s[1];
    bool ok1 = false, ok2 = false;
    for (char c : "HDCS")
      if (c == c1)
        ok1 = true;
    for (char c : "A23456789TJQK")
      if (c == c2)
        ok2 = true;
    if (!ok1 or !ok2)
    {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}