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
  cin >> n >> m;
  map<int, int> cnt;
  rep(_, 0, n)
  {
    int a;
    cin >> a;
    cnt[a]++;
  }
  rep(_, 0, m)
  {
    int b;
    cin >> b;
    if (cnt[b] < 1)
    {
      cout << "No" << endl;
      return 0;
    }
    else
      cnt[b]--;
  }
  cout << "Yes" << endl;
}