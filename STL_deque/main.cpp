#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

bool isOdd(int i)
{
    return i % 2 != 0;
}

bool myless(int i, int k)
{
    return i % 10 < k % 10;
}

bool myless_reverse(int i, int k)
{
    return i % 10 > k % 10;
}

void print(deque<int>& aa)
{
    for (auto i: aa)
        cout << i << " ";
    cout << endl;
}

int main()
{
    deque<int> aa = {12, 8, 5, 14, 7, 3};

    print(aa);

    auto it = find(aa.begin(), aa.end(), 55);

    if (it==aa.end())
        cout << "not found" << endl;
    else
        cout << *it << endl;

    sort(aa.begin()+1, aa.end()-1);

    print(aa);

    sort(aa.begin(), aa.end(), myless);

    print(aa);

    sort(aa.begin(), aa.end(), myless_reverse);

    print(aa);

    return 0;
}
