#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  string prev = "";
  rep(i, n)
  {
    string s;
    cin >> s;
    if (prev == "sweet" and s == "sweet" and i != n - 1)
    {
      cout << "No" << endl;
      return 0;
    }
    prev = s;
  }
  cout << "Yes" << endl;
}
