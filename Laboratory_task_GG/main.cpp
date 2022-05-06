/*
GG – linked list with elements of unit-testing and exception handling.

The same assignment, as in G, it’s solution (a) should be complemented by two additional elements:

x) at least one of the data checking should be implemented using exception handling,
y) at least one of the function (preferably, the central one) should be unit-tested, at least three test cases should be provided;
for that purpose
    (1) this function should be put in a separate file (to function main),
    (2) you should create another project just for unit-testing (so, the regular project, and testing project).
Tips: the last lab work of the previous semester (about classes) with hard-coded main function is very close to the concept of such a unit-testing project.
*/
#include <iostream>

using namespace std;

struct node {
    int num;
    node *next;
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
