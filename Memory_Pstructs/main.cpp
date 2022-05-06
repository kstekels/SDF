#include <iostream>
#include <cstring>
using namespace std;

struct person
{
    char first[16];
    char second[16];
    int age;
};

int main()
{
    person *p = new person();
    strcpy(p->first, "Johnny");
    strcpy(p->second, "Codeblocks");
    p->age = 33;
    delete p;
    return 0;
}
