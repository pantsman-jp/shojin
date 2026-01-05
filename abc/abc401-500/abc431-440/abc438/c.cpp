#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a) - 1; i >= b; i--)
#define all(p) p.begin(), p.end()
#define rall(p) p.rbegin(), p.rend()
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define yn(p) cout << (p ? "Yes\n" : "No\n");
#define dout(f) cout << fixed << setprecision(10) << f << '\n';
using ll = long long;
using ld = long double;
using P = pair<int, int>;
const int inf = 1 << 30;
const ll INF = 1LL << 60;
// const ll mod =;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a;
  rep(i, 0, n)
  {
    int ai;
    cin >> ai;
    a.push_back(ai);
    if (a.size() >= 4)
    {
      int m = a.size();
      if (a[m - 1] == a[m - 2] and a[m - 2] == a[m - 3] and a[m - 3] == a[m - 4])
        rep(_, 0, 4) a.pop_back();
    }
  }
  cout << a.size() << endl;
}