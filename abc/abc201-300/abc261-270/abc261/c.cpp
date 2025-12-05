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
    if (cnt[s] > 1)
      cout << s << '(' << cnt[s] - 1 << ')' << endl;
    else
      cout << s << endl;
  }
}