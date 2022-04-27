#include<iostream>
#include<list>
using namespace std;

void print(list<int> stl_list, string list_name)
{
    cout << list_name << ": [ ";
    for (auto &i: stl_list)
        cout << i << " ";
    cout << "]" << endl;
}

void print2(list<int> stl_list, string list_name)
{
    cout << list_name << ": [ ";
    for (auto it=stl_list.begin(); it!=stl_list.end(); ++it)
        cout << *it << " ";
    cout << "]" << endl;
}

void print2_reverse(list<int> stl_list, string list_name)
{
    cout << list_name << ": [ ";
    for (auto it=stl_list.rbegin(); it!=stl_list.rend(); ++it)
        cout << *it << " ";
    cout << "]" << endl;
}

int main()
{
    list<int> list_1={8,4,6};
    print(list_1, "list_1"); // 8 4 6

    list_1.push_front(1);
    list_1.push_back(5);
    print(list_1, "list_1"); // 1 8 4 6 5

    list<int> list_2={3,7};
    print(list_2, "list_2"); // 3 7

    auto it = list_1.begin();
    cout << "*it = " << *it << endl; // 1
    advance(it, 3);
    cout << "*it = " << *it << endl; // 6

    list_1.insert(it, list_2.begin(), list_2.end()); // 1 8 4 [3 7] 6 5
    print2(list_1, "list_1"); // 1 8 4 3 7 6 5
    print2_reverse(list_1, "list_1"); // 5 6 7 3 4 8 1

    auto it1 = list_1.begin(); // 1
    ++it1; // 8

    auto it2 = list_1.end(); // 5
    --it2; // 6

    list_1.erase(it1, it2); // removes (8, ..., 6) Including
    print2(list_1, "list_1"); // 1 5

    it = list_1.begin(); // 1
    ++it; // 5
    auto itplus = list_1.insert(it, 3); // 1 [3] 5
    print2(list_1, "list_1"); // 1 3 5
    cout << "*itplus: " << *itplus << endl; // 3

    itplus = list_1.erase(itplus); // 3
    print(list_1, "list_1"); // 1 5
    cout << "*itplus: " << *itplus << endl; // 5

    return 0;
}
