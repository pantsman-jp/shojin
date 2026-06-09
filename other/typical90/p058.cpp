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
const int mod = 1e5;

int y(int n)
{
  int ans = 0;
  while (n > 0)
    ans += n % 10, n /= 10;
  return ans;
}

int a(int x)
{
  return (x + y(x)) % mod;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  ll k;
  cin >> n >> k;
  vector<int> seq, pos(mod, -1);
  while (pos[n] == -1)
  {
    pos[n] = seq.size();
    seq.push_back(n);
    n = a(n);
  }
  ll start = pos[n], cycle = seq.size() - start;
  if (k < seq.size())
    cout << seq[k] << endl;
  else
    cout << seq[(k - start) % cycle + start] << endl;
}