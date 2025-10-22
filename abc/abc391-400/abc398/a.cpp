#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main()
{
  int n;
  cin >> n;
  if (n % 2 == 0)
  {
    int c = (n - 2) / 2;
    string edge = string(c, '-');
    cout << edge + "==" + edge << endl;
  }
  else
  {
    int c = (n - 1) / 2;
    string edge = string(c, '-');
    cout << edge + "=" + edge << endl;
  }
}
