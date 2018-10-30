#include "parser.h"

const char* fileOut = "out.txt";

int main(int argc, char *argv[])
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
        printFile(sx);
        printf("sx = %d\n", sx);
        cin >> sInput;
    }
    fclose(output);
    return 0;
}
