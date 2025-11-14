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
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  vector<int> x(N), y(M);
  rep(i, 0, N) cin >> x[i];
  rep(i, 0, M) cin >> y[i];
  if (max(X + 1, *max_element(all(x)) + 1) <= min(Y, *min_element(all(y))))
    cout << "No War" << endl;
  else
    cout << "War" << endl;
}