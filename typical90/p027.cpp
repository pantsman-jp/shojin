#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
using ll = long long;
const ll inf = 1LL << 60;

map<string, bool> signup;
int day = 1;

void solve()
{
  string s;
  cin >> s;
  if (!signup[s])
  {
    signup[s] = true;
    cout << day << endl;
  }
  day++;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  rep(sq, 0, n) solve();
}
