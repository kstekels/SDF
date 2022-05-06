#include <iostream>
#include <cstring>
using namespace std;

struct person
{
    char first[16];
    char second[16];
    int age;
};

int main() // &p
{
    person p;
    strcpy(p.first, "Johnny");
    strcpy(p.second, "Codeblocks");
    p.age = 32;

    return 0;
}
