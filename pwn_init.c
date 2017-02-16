// 基本栈溢出-来自i春秋

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void callsystem()
{
    system("/bin/bash");
}

void vulnerable_function()
{
    char buf[128];
    read(STDIN_FILENO, buf, 256);
}

int main(int argc, char** argv)
{
    if (argc == 2 && strcmp("password", argv[1]) == 0)
        callsystem();
    write(STDOUT_FILENO, "Hello, World!\n", 14);
    vulnerable_function();
}
