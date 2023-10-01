
#include <iostream>
#include <stack>
using namespace std;
void init(stack<char>& b, string a)
{
    for (size_t i = 0; i < a.length(); i++)
    {
        b.push(a[i]);
    }
}
bool isRight(stack<char> b)
{
    string t;
    int size = b.size();
    for (size_t i = 0; i < size; i++)
    {
        t += b.top();
        b.pop();
    }
    reverse(t.begin(), t.end());
    {
        int x = 0;
        int z = 0;
        int y = 0;
        for (size_t i = 0; i < t.length(); i++)
        {
            if (t[i] == '(')
                x++;
            else if (t[i] == ')')
                x--;
            else if (t[i] == '{')
                y++;
            else if (t[i] == '}')
                y--;
            else if (t[i] == '[')
                z++;
            else if (t[i] == ']')
                z--;
        }
        if (x != 0 || z!=0 || y!=0)
            return 0;
    }
    bool flag = 0;
    for (size_t i = 0; i < t.length(); i++)
    {
        int x = 0;
        if (t[i] == '('|| t[i]=='{' || t[i]=='[')
            flag = 0;
        for (size_t j = i+1; j < t.length(); j++)
        {
            if (t[i] == '(')
            {
                if (t[j] == '(')
                    x++;
                else if (t[j] == ')')
                {
                    if (x == 0)
                    {
                        flag = 1;
                    }
                    else
                        x--;
                }
            }
            if (t[i] == '{')
            {
                if (t[j] == '{')
                    x++;
                else if (t[j] == '}')
                {
                    if (x == 0)
                    {
                        flag = 1;
                    }
                    else
                        x--;
                }
            }
            if (t[i] == '[')
            {
                if (t[j] == '[')
                    x++;
                else if (t[j] == ']')
                {
                    if (x == 0)
                    {
                        flag = 1;
                    }
                    else
                        x--;
                }
            }
        }
        if (flag == 0)
            return 0;
    }
    return 1;
}

int main()
{
    stack<char> main;
    init(main, "({x-y-z}*[][x+2y]-(z+4x))");
    cout << isRight(main) << endl;
    init(main, "([x-y-z}*[x+2y)-{z+4x)]");
    cout << isRight(main) << endl;
}

