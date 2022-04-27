#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream file;
    file.open("textfile.txt", ios::in);

    if (file.is_open())
    {
        char character;
        int counter=0;
        character = file.get();

        while (file.eof()==false)
        {
            ++counter;
            cout << character;
            character = file.get();
        }
        cout << counter << endl;
    }
    else
    {
        cout << "File open failed!" << endl;
    }
    file.close();

    return 0;
}
