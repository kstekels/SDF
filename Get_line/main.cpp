#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream file;
    file.open("textfile.txt", ios::in);
    if (file.is_open())
    {
        string lineContent;
        int lines = 0;
        int counter = 0;
        int digits = 0;
        while(getline(file, lineContent))
        {
            for (int i=0; i<lineContent.size(); ++i)
            {
                if (lineContent[i]>='0' && lineContent[i]<='9')
                {
                    digits++;
                }
            }
            lines++;
            counter += lineContent.size();
            cout << lineContent << endl;
        }
        cout<< "lines: " << lines << endl;
        cout<< "chars: " << counter << endl;
        cout<< "digits: " << digits << endl;
    }
    else
        {
            cout << "File open failed" << endl;
        }
        file.close();

    return 0;
}
