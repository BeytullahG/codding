#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    ifstream in("sint.txt");
    ofstream out("result.txt");

    if (!in)
    {
        cout << "Can't open input file" << endl;
        return -1;
    }

    if (!out)
    {
        cout << "Can't open output file" << endl;
        return -1;
    }

    char x;
    int q = 0;

    while (in >> x && q != 5)
    {
        out << x;
        switch (q)
        {
        case 0:
            if (x == 'A')
                q = 1;
            else
                q = 5;
            break;
        case 1:
            if (x == 'A' || x == 'B')
                q = 2;
            else
                q = 5;
            break;
        case 2:
            if (x == 'A')
                q = 3;
            else
                q = 5;
            break;
        case 3:
            if (x == 'A' || x == 'B')
                q = 2;
            else if (x == 'C')
                q = 4;
            else
                q = 5;
            break;
        default:
            q = 5;
            break;
        }
        out << setw(2) << q << endl;
    }

    out << endl;
    if (q == 4)
        out << "sequence is element of L" << endl;
    else
        out << "sequence is not element of L" << endl;

    in.close();
    out.close();

    return 0;
}