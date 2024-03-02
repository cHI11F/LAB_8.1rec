#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int CountRec(const char* str, int index, int count)
{
    if (str[index] == '\0')
        return count;

    if (str[index] == '+' || str[index] == '-' || str[index] == '=')
        count++;

    return CountRec(str, index + 1, count);
}

int Count(const char* str)
{
    return CountRec(str, 0, 0);
}

char* ChangeRec(const char* str, char* tmp, int index, int t_index)
{
    if (str[index] == '\0') {
        tmp[t_index] = '\0';
        return tmp;
    }

    if (str[index] == '+' || str[index] == '-' || str[index] == '=') {
        tmp[t_index++] = '*';
        tmp[t_index++] = '*';
    }
    else {
        tmp[t_index++] = str[index];
    }

    return ChangeRec(str, tmp, index + 1, t_index);
}

char* Change(const char* str)
{
    size_t len = strlen(str);
    char* tmp = new char[len * 2 + 1];
    return ChangeRec(str, tmp, 0, 0);
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);
    cout << "String contained " << Count(str) << " groups of '+ - ='" << endl;
    char* dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;
    delete[] dest;
    return 0;
}
