#include <cstdlib>
#include <cstdio>
#include <cstdarg>
#include <string>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

#define SYMBOL_POW   1  // pow
#define SYMBOL_LP    2  // (
#define SYMBOL_RP    3  // )
#define SYMBOL_MULT  4  // *
#define SYMBOL_PLUS  5  // +
#define SYMBOL_COMMA 6  // ,
#define SYMBOL_I     7  // i

FILE *output;

string sInput = "";
int index = 0;

int symbol;
int value;
int tscan;

void error()
{
    cout << "error" << endl;
    fprintf(output, "%s\n\n", "error");
    exit(1);
}

string getNum(string str)
{
    string sNum = "";
    while (str[index] >= 48 && str[index] <= 57)
    {
        sNum += str[index];
        index++;
    }
    return sNum;
}

int scan(string str)
{
    char cSymbol = str[index];

    if (cSymbol == '(')
    {
        symbol = SYMBOL_LP;
        index++;
        return SYMBOL_LP;
    }

    if (cSymbol == ')')
    {
        symbol = SYMBOL_RP;
        index++;
        return SYMBOL_RP;
    }

    if (cSymbol == '*')
    {
        symbol = SYMBOL_MULT;
        index++;
        return SYMBOL_MULT;
    }

    if (cSymbol == '+')
    {
        symbol = SYMBOL_PLUS;
        index++;
        return SYMBOL_PLUS;
    }

    if (cSymbol == ',')
    {
        symbol = SYMBOL_COMMA;
        index++;
        return SYMBOL_COMMA;
    }

    if (str.substr(index, 3) == "pow")
    {
        symbol = SYMBOL_POW;
        index += 3;
        return SYMBOL_POW;
    }
    else
    {
        string sNum = getNum(str);
        if (sNum != "")
        {
            value = atoi(sNum.c_str());
            symbol = SYMBOL_I;
            return SYMBOL_I;
        }
        else
            return -1;
    }
}


int M();
int E();
int F();

// S ::= S + M | M
int S()
{
    int mx = M();

    if (symbol == SYMBOL_PLUS)
    {
        tscan = scan(sInput);
        mx += M();
    }

    return mx;
}

// M ::= M * E | E
int M()
{
    int ex = E();

    if (symbol == SYMBOL_MULT)
    {
        tscan = scan(sInput);
        ex *= E();
    }
    
    return ex;
}

// E ::= pow( S, S ) | F
int E()
{
    int fa, fb;
    if(symbol == SYMBOL_POW)
    {
        tscan = scan(sInput);
        if (symbol == SYMBOL_LP)
        {
            tscan = scan(sInput);
            fa = S();
            if (symbol == SYMBOL_COMMA)
            {
                tscan = scan(sInput);
                fb = S();
            }
            else
                error();
            if(symbol == SYMBOL_RP)
            {
                tscan = scan(sInput);
                return pow(fa, fb);
            }
            else
                error();
        }
        else
            error();
    }
    else
        return fa = F();
}

// F ::= i | (S)
int F()
{
    if(symbol == SYMBOL_I)
    {
        tscan = scan(sInput);
        return value;
    }
    else if (symbol == SYMBOL_LP)
    {
        tscan = scan(sInput);
        int sx = S();
        if(symbol == SYMBOL_RP)
        {
            tscan = scan(sInput);
            return sx;
        }
        else
            error();
    }
    else
        error();
}

void printFile(int sx)
{
    if (index != sInput.length())
        error();
    fprintf(output, "%s\n", sInput.c_str());
    fprintf(output, "sx = %d\n\n", sx);
}

int main()
{
    output = fopen("resTask5.txt", "a+");

    cin >> sInput;
    while (sInput != "q")
    {
        index = 0;
        tscan = scan(sInput);
        int sx = S();
        printf("sx = %d\n", sx);
        printFile(sx);
        cin >> sInput;
    }
    fclose(output);
    return 0;
}
