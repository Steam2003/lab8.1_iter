#include <iostream>
#include <string>
using namespace std;

bool IsOrNot(char* s)
{
    for (size_t i = 0; i < strlen(s) - 2; i++)
        if (s[i] == '*' && s[i + 1] == '*' && s[i + 2] == '*')
            return true;
    return false;
}

char* change(char* s)
{
    char* sNew = new char[101];
    size_t l = 0;
    if (IsOrNot(s))
        for (size_t i = 0; i < strlen(s); i++)
        {
            if (s[i] == '*' && s[i + 1] == '*' && s[i + 2] == '*')
            {
                sNew[l] = '!';
                sNew[l + 1] = '!';
                l += 2;
                i += 2;
            }
            else
            {
                sNew[l] = s[i];
                ++l;
            }
        }
    sNew[l] = '\0';
    strcpy_s(s, strlen(sNew)+1, sNew);
    delete[] sNew;
    return s;       
}

int main()
{
    char* s = new char[101];
    cout << "Enter string:" << endl;
    cin.getline(s, 100);
    char* t=change(s);
    cout << t;
    delete[] s;
    cout << endl;
}