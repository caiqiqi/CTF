#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    volatile int modified;
    char buffer[64];

    modified = 0;  // 可以被覆盖
    gets(buffer);  // 没有指定多大

    if(modified !=0){
        printf("[*] You have changed the 'modified' var\n");
	return 0;  // 成功
    } else{
        printf("[!] Tru again\n");
	return 1;  // 失败
    }
}
