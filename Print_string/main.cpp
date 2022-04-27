#include<iostream>
using namespace std;

int strlen(const char *s) {
    int i=0;
    while (s[i]!=0) ++i;
    return i;
}

int main()
{
    char s[] = "Hello, World!";

	for (int i=0; i<strlen(s); ++i) cout<<s[i];
	cout<<endl;

	for (int i=0; s[i]!=0; ++i) cout<<s[i];
	cout<<endl;
    return 0;
}
