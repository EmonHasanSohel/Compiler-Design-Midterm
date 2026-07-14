#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

bool alreadyExists(string token, string printed[], int count)
{
    for(int i = 0; i < count; i++)
    {
        if(printed[i] == token)
            return true;
    }
    return false;
}

void printToken(ofstream &out, string token, string type, string printed[], int &count)
{
    if(!alreadyExists(token, printed, count))
    {
        out << token << " --> " << type << endl;
        printed[count] = token;
        count++;
    }
}

int main()
{
    string keyword[] = {"int","float","char","double","void","return","string","cout","cin","if","else","for","while","main"};
    string op[] = {"+","-","*","/","=","==","<<",">>","<",">","<=",">=","!="};
    char punc[] = {';',',','(',')','{','}','[',']'};

    ifstream file("Input.txt");
    ofstream out("Output.txt");

    if(!file)
    {
        cout << "File not found";
        return 0;
    }

    string printed[1000];
    int printedCount = 0;

    string line;
    int lineNo = 1;

    out << "----------------------------------" << endl;

    while(getline(file, line))
    {
        out << "Line " << lineNo << endl;

        string token = "";

        for(int i = 0; i <= line.length(); i++)
        {
            char ch = line[i];

            if(isalnum(ch) || ch=='_' || ch=='.' || ch=='"')
            {
                token += ch;
            }
            else
            {
                if(token != "")
                {
                    bool found = false;

                    for(int j = 0; j < 14; j++)
                    {
                        if(token == keyword[j])
                        {
                            printToken(out, token, "Keyword", printed, printedCount);
                            found = true;
                            break;
                        }
                    }

                    if(!found)
                    {
                        bool number = true;
                        int dot = 0;

                        for(int j = 0; j < token.length(); j++)
                        {
                            if(token[j] == '.')
                                dot++;
                            else if(!isdigit(token[j]) && token[j] != '"')
                                number = false;
                        }

                        if(token[0] == '"' && token[token.length()-1] == '"')
                        {
                            printToken(out, token, "String", printed, printedCount);
                        }
                        else if(number && dot == 0)
                        {
                            printToken(out, token, "Integer", printed, printedCount);
                        }
                        else if(number && dot == 1)
                        {
                            printToken(out, token, "Float", printed, printedCount);
                        }
                        else
                        {
                            printToken(out, token, "Identifier", printed, printedCount);
                        }
                    }

                    token = "";
                }

                if(ch == ' ')
                    continue;

                if((ch=='<' || ch=='>') && i+1<line.length() && line[i+1]==ch)
                {
                    string temp = "";
                    temp += ch;
                    temp += line[i+1];
                    printToken(out, temp, "Operator", printed, printedCount);
                    i++;
                    continue;
                }

                if((ch=='=' || ch=='!' || ch=='<' || ch=='>') && i+1<line.length() && line[i+1]=='=')
                {
                    string temp = "";
                    temp += ch;
                    temp += line[i+1];
                    printToken(out, temp, "Operator", printed, printedCount);
                    i++;
                    continue;
                }

                bool foundOp = false;

                for(int j = 0; j < 13; j++)
                {
                    if(string(1,ch) == op[j])
                    {
                        printToken(out, string(1,ch), "Operator", printed, printedCount);
                        foundOp = true;
                        break;
                    }
                }

                if(foundOp)
                    continue;

                for(int j = 0; j < 8; j++)
                {
                    if(ch == punc[j])
                    {
                        printToken(out, string(1,ch), "Punctuation", printed, printedCount);
                        break;
                    }
                }
            }
        }

        out << endl;
        lineNo++;
    }

    out << "----------------------------------" << endl;

    file.close();
    out.close();

    cout << "Output successfully written to Output.txt" << endl;

    return 0;
}