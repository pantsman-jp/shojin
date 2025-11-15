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
  string n;
  cin >> n;
  if (n[0] == n[1] and n[1] == n[2] and n[2] == n[3])
    cout << "SAME" << endl;
  else
    cout << "DIFFERENT" << endl;
}