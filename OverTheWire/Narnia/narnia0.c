// 基于stack的buffer overflow
// 参考：https://hackmethod.com/overthewire-narnia-0/
#include <stdio.h>
#include <stdlib.h>

int main(){
        long val=0x41414141;
        // char在C语言中的长度为一个字节，所以buf的为20个字符
	char buf[20];

        printf("Correct val's value from 0x41414141 -> 0xdeadbeef!\n");
        printf("Here is your chance: ");
        // %24s 表示scanf函数将接收24个字节的字符串(一个字符 = 一字节)
	scanf("%24s",&buf);
	// 发现buf只分配了20字节，而scanf要接收24字节，这样一来我们就可以buffer overflow了

        printf("buf: %s\n",buf);
        printf("val: 0x%08x\n",val);

        if(val==0xdeadbeef)
                system("/bin/sh");
        else {
                printf("WAY OFF!!!!\n");
                exit(1);
        }

        return 0;
}
