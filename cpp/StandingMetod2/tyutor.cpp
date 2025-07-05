#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

bool is_letter(char x)
{
    return ((x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z'));
}
bool is_digit(char x)
{
    return (x >= '0' && x <= '9');
}
bool is_sign(char x)
{
    return (x == '+' || x == '-' || x == '*' || x == '/');
}

int main()
{

    ifstream in("in.txt");
    ofstream out("result.txt");
    if (!in)
    {
        exit(-1);
    }

    char x;
    int q = 0;
    int last = 0;
    int k = 0;

    while (q != 30 && in >> x)
    {
        last = q;
        switch (q)
        {
        case 0:
            if (is_letter(x)) q = 1;
            else q = 30;
            break;

        case 1:
            if (is_letter(x) || is_digit(x)) q = 2;
            else if (x == ':') q = 3;
            else q = 30;
            break;

        case 2:
            if (x == ':') q = 3;
            else q = 30;
            break;

        case 3:
            if (x == '=') q = 4;
            else q = 30;
            break;

        case 4:
            if (is_letter(x)) q = 5;
            else if (x == '+' || x == '-') q = 10;
            else q = 30;
            break;

        case 5:
            if (is_letter(x) || is_digit(x)) q = 6;
            else if (x == '<' || x == '=') q = 7;
            else q = 30;
            break;

        case 6:
            if (x == '<' || x == '=') q = 7;
            else q = 30;
            break;

        case 7:
            if (is_letter(x)) q = 8;
            else if (x == '+' || x == '-') q = 11;
            else q = 30;
            break;

        case 8:
            if (is_letter(x) || is_digit(x)) q = 9;
            else if (x == '[') q = 12;
            else q = 30;
            break;

        case 9:
            if (x == '[') q = 12;
            else q = 30;
            break;

        case 10:
            if (is_digit(x) && k < 4)
            {
                q = 10;
                k++;
            }
            else if (is_digit(x) && k == 4)
            {
                q = 6;
                k = 0;
            }
            else q = 30;
            break;

        case 11:
            if (is_digit(x) && k < 4)
            {
                q = 11;
                k++;
            }
            else if (is_digit(x) && k == 4)
            {
                q = 9;
                k = 0;
            }
            else q = 30;
            break;

        case 12:
            if (is_letter(x)) q = 13;
            else if (x == '+' || x == '-') q = 15;
            else q = 30;
            break;

        case 13:
            if (is_letter(x) || is_digit(x)) q = 14;
            else if (x == ']') q = 20;
            else if (is_sign(x)) q = 16;
            else q = 30;
            break;

        case 14:
            if (is_sign(x)) q = 16;
            else if (x == ']') q = 20;
            else q = 30;
            break;

        case 15:
            if (is_digit(x) && k < 4)
            {
                q = 15;
                k++;
            }
            else if (is_digit(x) && k == 4)
            {
                q = 14;
                k = 0;
            }
            else q = 30;
            break;

        case 16:
            if (is_letter(x)) q = 17;
            else if (x == '+' || x == '-') q = 19;
            else q = 30;
            break;

        case 17:
            if (is_letter(x) || is_digit(x)) q = 18;
            else if (x == ']') q = 20;
            else q = 30;
            break;

        case 18:
            if (x == ']') q = 20;
            else q = 30;
            break;

        case 19:
            if (is_digit(x) && k < 4)
            {
                q = 19;
                k++;
            }
            else if (is_digit(x) && k == 4)
            {
                q = 18;
                k = 0;
            }
            else q = 30;
            break;

        case 20:
            if (x == '[') q = 21;
            else q = 30;
            break;

        case 21:
            if (is_letter(x)) q = 22;
            else if (x == '+' || x == '-') q = 24;
            else q = 30;
            break;

        case 22:
            if (is_letter(x) || is_digit(x)) q = 23;
            else if (x == ']') q = 29;
            else if (is_sign(x)) q = 25;
            else q = 30;
            break;

        case 23:
            if (is_sign(x)) q = 25;
            else if (x == ']') q = 29;
            else q = 30;
            break;

        case 24:
            if (is_digit(x) && k < 4)
            {
                q = 24;
                k++;
            }
            else if (is_digit(x) && k == 4)
            {
                q = 23;
                k = 0;
            }
            else q = 30;
            break;

        case 25:
            if (is_letter(x)) q = 26;
            else if (x == '+' || x == '-') q = 28;
            else q = 30;
            break;

        case 26:
            if (is_letter(x) || is_digit(x)) q = 27;
            else if (x == ']') q = 29;
            else q = 30;
            break;

        case 27:
            if (x == ']') q = 29;
            else if (x == ';') q = 0;
            else q = 30;
            break;

        case 28:
            if (is_digit(x) && k < 4)
            {
                q = 28;
                k++;
            }
            else if (is_digit(x) && k == 4)
            {
                q = 27;
                k = 0;
            }
            else q = 30;
            break;

        case 29:
            if (x == ';') q = 0;
            else q = 30;
            break;

        default:
            q = 30;
            break;
        }

        if (q != 30)
        {
            out << x;
            if (x == ';') out << endl;
        }
    }

    out << endl;

    if (q == 0)
        out << "Everything is correct!";

    else if (q == 30)
    {
        switch (last)
        {
        case 0:  out << "Ошибка 0 : ожидалась буква, найден символ '" << x << "'" << endl; break;
        case 1:  out << "Ошибка 1: ожидалась буква или цифра, или символ ':', найден символ '" << x << "'" << endl; break;
        case 2:  out << "Ошибка 2: ожидался символ ':', найден символ '" << x << "'" << endl; break;
        case 3:  out << "Ошибка 3: ожидался символ '=', найден символ '" << x << "'" << endl; break;
        case 4:  out << "Ошибка 4: ожидалась буква или знаки '+' или '-' найден символ '" << x << "'" << endl; break;
        case 5:  out << "Ошибка 5: ожидалась буква или цифра (0-9), найден символ '" << x << "'" << endl; break;
        case 6:  out << "Ошибка 6: ожидался  знаки  '<' или '=', найден символ '" << x << "'" << endl; break;
        case 7:  out << "Ошибка 7: ожидалась буква или знаки '+' или '-', найден символ '" << x << "'" << endl; break;
        case 8:  out << "Ошибка 8: ожидалась буква или цифра (0-9), найден символ '" << x << "'" << endl; break;
        case 9:  out << "Ошибка 9: ожидался символ  '[', найден символ '" << x << "'" << endl; break;
        case 10: out << "Ошибка 10: ожидалась цифра (0-9), найден символ '" << x << "'" << endl; break;
        case 11: out << "Ошибка 11: ожидалась цифра (0-9), найден символ '" << x << "'" << endl; break;
        case 12: out << "Ошибка 12: ожидалась буква или знаки '+' или '-' найден символ '" << x << "'" << endl; break;
        case 13: out << "Ошибка 13: ожидалась буква или цифра (0-9), найден символ '" << x << "'" << endl; break;
        case 14: out << "Ошибка 14: ожидался знак '+','','*','/' или ']' найден символ '" << x << "'" << endl; break;
        case 15: out << "Ошибка 15: ожидалась цифра (0-9), найден символ '" << x << "'" << endl; break;
        case 16: out << "Ошибка 16: ожидалась буква или знаки '+' или '-' найден символ '" << x << "'" << endl; break;
        case 17: out << "Ошибка 17: ожидалась буква или цифра (0-9), найден символ '" << x << "'" << endl; break;
        case 18: out << "Ошибка 18: ожидался символ ']' найден символ '" << x << "'" << endl; break;
        case 19: out << "Ошибка 19: ожидалась цифра (0-9), найден символ '" << x << "'" << endl; break;
        case 20: out << "Ошибка 20: ожидался символ  '[', найден символ '" << x << "'" << endl; break;
        case 21: out << "Ошибка 21: ожидалась буква или знаки '+' или '-', найден символ '" << x << "'" << endl; break;
        case 22: out << "Ошибка 22: ожидалась буква или цифра (0-9), найден символ '" << x << "'" << endl; break;
        case 23: out << "Ошибка 23: ожидался знак '+','','*','/' или ']' найден символ '" << x << "'" << endl; break;
        case 24: out << "Ошибка 24: ожидалась цифра (0-9), найден символ '" << x << "'" << endl; break;
        case 25: out << "Ошибка 25: ожидалась буква или знаки '+' или '-', найден символ '" << x << "'" << endl; break;
        case 26: out << "Ошибка 26: ожидалась буква или цифра (0-9), найден символ '" << x << "'" << endl; break;
        case 27: out << "Ошибка 27: ожидался символ ']' или ';' найден символ '" << x << "'" << endl; break;
        case 28: out << "Ошибка 28: ожидалась цифра (0-9), найден символ '" << x << "'" << endl; break;
        }
    }

    in.close();
    out.close();

    return 0;
}
