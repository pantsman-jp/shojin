#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> a;
  while (true)
  {
    int n;
    cin >> n;
    a.push_back(n);
    if (n == 0)
      break;
  }
  for (int i = (int)a.size() - 1; -1 < i; --i)
    cout << a[i] << endl;
}
