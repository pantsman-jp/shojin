#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
  long long x;
  cin >> x;
  int ans = 2;
  long long fact = 2;
  while (true)
  {
    if (fact == x)
    {
      cout << ans << endl;
      return 0;
    }
    ans++;
    fact *= ans;
  }
}
