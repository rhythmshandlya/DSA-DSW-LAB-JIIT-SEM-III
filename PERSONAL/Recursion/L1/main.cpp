#include <iostream>
using namespace std;

int scoreOfParentheses(string s)
{
    static int i = 0;
    int score = 0;
    while (i < s.size())
    {
        if (s[i] == '<')
        {
            char first = s[i];
            ++i;

            if (s[i] == '>')
            {
                score++;
                ++i;
            }
            else
            {
                score += 3 * scoreOfParenthese(s);
                ++i;
            }
        }
        else
            return score;
    }
    return score;
}

int main()
{
    cout << scoreOfParentheses("<<>>");
    return 0;
}