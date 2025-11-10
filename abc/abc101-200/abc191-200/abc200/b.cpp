#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(p) p.begin(), p.end()
using P = pair<int, int>;
using ll = long long;
const ll inf = 1LL << 60;

ll n, k;

void op()
{
  if (n % 200 == 0)
    n /= 200;
  else
    n = n * 1000 + 200;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  rep(_, 0, k) op();
  cout << n << endl;
}