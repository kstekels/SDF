#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print(vector<int>& arr)
{
    for (auto i:arr)
        cout << i << " ";
    cout << endl;
}

int main()
{

    vector<int> aa = {12, 8 ,3};
    aa.push_back(7);

    print(aa);

    aa.insert(aa.begin(), 5);

    print(aa);

    aa.erase(aa.begin()+1);

    print(aa);

    remove(aa.begin(), aa.end(), 8);

    print(aa);

    aa.pop_back();

    print(aa);

    return 0;
}
