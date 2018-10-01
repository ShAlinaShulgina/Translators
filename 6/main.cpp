#include "parser.h"

const string flag = "-t";
const char* fileOutTest = "outTest.txt";
const char* fileOut = "out.txt";

int main(int argc, char *argv[])
{
    if (argc >= 2)
    {
        if (flag == argv[1])
        {
            output = fopen(fileOutTest, "a+"); // output result
            if (!output)
            {
                cout << "File not open!" << endl;
                exit(1);
            }

            fstream test;
            test.open("test.txt", ios::in); // input test
            if(!test.is_open())
            {
                cout << "File test.txt not open!" << endl;
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
        }
    }
    else
    {
        output = fopen(fileOut, "a+"); // output result
        if (!output)
        {
            cout << "File not open!" << endl;
            exit(1);
        }
        cin >> sInput;
        while (sInput != "q")
        {
            index = 0;
            tscan = scan(sInput);
            printScan(tscan);
            int sx = S();
            printFile(sx, "", 0);
            printf("sx = %d\n", sx);
            cin >> sInput;
        }
    }
    fclose(output);
    return 0;
}
