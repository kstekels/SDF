#include<iostream>
#include<fstream>
using namespace std;

void example1()
{
    fstream file;
    file.open("out1.txt", ios::out);
    file << "Hello" << endl;
    file << "World" << endl;
    file << "example1" << endl;
    file.close();
}

void example2()
{
    fstream file("out2.txt", ios::out);
    file << "Hello" << endl;
    file << "World" << endl;
    file << "example2" << endl;
    file.close();
}

void example3()
{
    ofstream file("out3.txt");
    file << "Hello" << endl;
    file << "World" << endl;
    file << "example3" << endl;
    file.close();
}

int main()
{
    int example;
    cout << "Choose example from 1 - 3: ";
    cin >> example;
    switch (example)
    {
    case 1:
        example1();
        break;
    case 2:
        example2();
        break;
    case 3:
        example3();
        break;
    default:
        cout << "No example found for " << example << endl;
        break;
    }

    return 0;
}
