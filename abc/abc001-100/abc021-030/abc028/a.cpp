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
  if (n < 60)
    cout << "Bad" << endl;
  else if (60 <= n and n < 90)
    cout << "Good" << endl;
  else if (90 <= n and n < 100)
    cout << "Great" << endl;
  else
    cout << "Perfect" << endl;
}