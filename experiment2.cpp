#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void tokenize(string input)
{
    string keyword[]= {"int", "float",  "char", "cout", "cin", "if", "else"};
    string op[] = {"+", "-",  "*",  "/", "=", "<<", ">>"} ;
    char punc[] ={';', ',', '(',')', '{', '}','[', ']'};

    int i = 0, j = 0;

    while (j < input.length())
    {
        if ( input[j] == ' ')
        {
            j++;
            i = j;
            continue;
        }

        if ( isalnum(input[j]) || input[j] == '.')
        {
            while (j < input.length() && (isalnum(input[j]) || input[j] == '.'))
            {
                j++;
            }

            string token = input.substr(i, j - i);

            bool found = false;
            for (int k = 0; k < 7; k++)
            {
                if (token == keyword[k])
                {
                    cout << token << " -> Keyword" << endl;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                bool isNumber = true;
                for (int k = 0; k < token.length(); k++)
                {
                    if ( !isdigit(token[k]) && token[k] != '.')
                    {
                        isNumber = false;
                        break;
                    }
                }

                if (isNumber)
                    cout << token << " ->  Numerical Constant" << endl;
                else
                    cout << token << " ->  Identifier" << endl;
            }

            i = j;
        }
        else if (input[j] == '<' && j + 1 < input.length() && input[j + 1] == '<')
        {
            cout << "<< ->  Operator" << endl;
            j += 2;
            i = j;
        }
        else if (input[j] == '>' && j + 1 < input.length() && input[j + 1] == '>')
        {
            cout << ">> -> Operator" << endl;
            j += 2;
            i = j;
        }
        else if (input[j] == '+' || input[j] == '-' || input[j] == '*' || input[j] == '/' || input[j] == '=')
        {
            cout << input[j] << " -> Operator" << endl;
            j++;
            i = j;
        }
        else if (input[j] == ';' || input[j] == ',' || input[j] == '(' || input[j] == ')' || input[j] == '{' || input[j] == '}' || input[j] == '[' || input[j] == ']')
        {
            cout << input[j] << " ->  Punctuation" << endl;
            j++;
            i = j;
        }
        else
        {
            j++;
            i = j;
        }
    }
}

int main()
{
    cout << "--------------------------------------" << endl;

    string input = "cout << 20 + a * 60.5;";

    tokenize(input);

    cout << "--------------------------------------" << endl;

    return 0;
}