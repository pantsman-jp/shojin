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
  int sum = 0, cnt = 0;
  rep(_, 0, n)
  {
    int a;
    cin >> a;
    if (a != 0)
      sum += a, cnt++;
  }
  cout << (sum + cnt - 1) / cnt << endl;
}