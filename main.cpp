#include <cstdio>
#include <string>

#include "brainfuck.h"

int main()
{
    std::string szCode = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";

    CBrainfuckInterpreter Interpreter(szCode);
    Interpreter.Interpret();

    printf("Done\n");

    return 0;
}