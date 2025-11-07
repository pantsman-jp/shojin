#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n, t, a;
  cin >> n >> t >> a;
  if (min(t, a) + (n - (t + a)) < max(t, a))
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
