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

#define ERROR_TYPE_1 "Missing character '%s'\n" // Отсутствует символ '%символ'
#define ERROR_TYPE_2 "Input string != Output string '%s'\n"

FILE *output;

string sInput = "";
int index = 0;

int symbol;
int value;
int tscan;

// возведение в степень
int fPow(int one, int two)
{
    double count = 1;
    while (two)
        if (two & 1)
        {
            count *= one;
            two--;
        }
        else
        {
            one *= one;
            two >>= 1;
        }
    return count;
}

void printScan(int id)
{
    switch(id)
    {
        case 1:     cout << "SYMBOL_POW" << endl;   break;
        case 2:     cout << "SYMBOL_LP" << endl;    break;
        case 3:     cout << "SYMBOL_RP" << endl;    break;
        case 4:     cout << "SYMBOL_MULT" << endl;  break;
        case 5:     cout << "SYMBOL_PLUS" << endl;  break;
        case 6:     cout << "SYMBOL_COMMA" << endl; break;
        case 7:     cout << "SYMBOL_I" << endl;     break;
        default:    cout << endl;                   break;
    }
}

void error(string type, bool flag = 0)
{
    if (flag)
        fprintf(output, ERROR_TYPE_2, type.c_str());
    else
        fprintf(output, ERROR_TYPE_1, type.c_str());
//    exit(1);
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
        printScan(tscan);
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
        printScan(tscan);
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
        printScan(tscan);
        if (symbol == SYMBOL_LP)
        {
            tscan = scan(sInput);
            printScan(tscan);
            fa = S();
            if (symbol == SYMBOL_COMMA)
            {
                tscan = scan(sInput);
                printScan(tscan);
                fb = S();
            }
            else
                error(",");
            if(symbol == SYMBOL_RP)
            {
                tscan = scan(sInput);
                printScan(tscan);
                return fPow(fa, fb);
            }
            else
                error(")");
        }
        else
            error("(");
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
        printScan(tscan);
        return value;
    }
    else if (symbol == SYMBOL_LP)
    {
        tscan = scan(sInput);
        printScan(tscan);
        int sx = S();
        if(symbol == SYMBOL_RP)
        {
            tscan = scan(sInput);
            printScan(tscan);
            return sx;
        }
        else
            error(")");
    }
    else
        error("(");
}

void printFile(int sx, string yesTest)
{
    if (index != sInput.length())
        error("---", 1);
    fprintf(output, "%s\n", sInput.c_str());
    fprintf(output, "sx = %d\n", sx);
    fprintf(output, "test: %s\n\n", yesTest.c_str());
}

int main()
{
    fstream test;
    test.open("test.txt", ios::in); // input test
    if(!test.is_open())
    {
        cout << "File test.txt not open!" << endl;
        exit(1);
    }
    output = fopen("resTask5.txt", "a+"); // output result
    if (!output)
    {
        cout << "File resTask5.txt not open!" << endl;
        exit(1);
    }

    while(!test.eof())
    {
        test >> sInput;
        cout << "sInput " << sInput << endl;

        index = 0;
        tscan = scan(sInput);
        printScan(tscan);
        int sx = S();

        int resTest = 0; string resT = "";
        test >> resT;
        resTest = atoi(resT.c_str());
        if (resTest == sx)
        {
            printf("YES! %d\n\n", sx);
            printFile(sx, "YES");
        }
        else
        {
            printf("!NO! %d != %d\n\n", resTest, sx);
            printFile(sx, "NO");
        }
    }
    test.close();
    fclose(output);
    return 0;
}
