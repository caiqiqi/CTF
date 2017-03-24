#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>


///////////////
// 这是一个很经典的文件访问竞态条件漏洞。这种类型的漏洞描述了这样一个问题：
// 当在使用一个文件之前，先判断当前用户是否具有第该文件操作的权限，如果有，才可以继续。这种思路流程如下：
// if (access(file, R_OK)){
//     int f = open(file, O_RDONLY);
//     ......
// }else {
//
//     printf("error\n");
//     exit(1);
//
// 在上面的代码中，首先用access函数判断当前用户是否有操作文件的权限(access函数用的是其调用进程的uid，而不是effective ID)。
// 有权限则open它，无权限则打印error并退出。
// 在早期的单处理操作系统中，这样的代码可能是严谨的，出发点也是好的--因为单处理的话，进程执行完毕后才发生切换。但是在多任务的操作系统中
// 有这样一个问题：在用access检查文件后，这个程序可能收到其他程序的干扰或者发生进程切换，在进程发生切换之后，进程失去了执行流程，并且
// 在它还未获得执行时，它欲操作的文件发生改变--邪恶源头是因为access和open都是通过文件路径这个字符串作为参数的，而路径可能是一个链接文件。
// 在linux中，假设要access一个/tmp/cqq文件，在access后，open之前，/tmp/cqq被替换成了一个链接文件，指向了其他文件(比如/etc/passwd)。
// 而如果这个进程有对/etc/passwd操作的权限，它最终所操作的并不是真正的/tmp/cqq，而是/etc/passwd。
////////////////


// struct sockaddr 和 struct sockaddr_in 这两个结构体用来处理网络通信的地址。
// 在各种系统调用或者函数中，只要和网路地址打交道，就得用到这两个结构体
// 它们两个是并列的结构，指向sockaddr_in 的结构体指针也可以指向sockaddr的结构体，并代替它。
// 也就是说，你可以用sockaddr_in 建立你所需要的信息，然后用memset函数初始化就可以了。
//
// 相应地，头文件中有如下定义：
// #include <netinet/in.h> 
// struct sockaddr {
//     unsigned short         sa_family;      // 2 bytes address family, AF_XXX
//     char                   sa_data[14];    // 14 bytes of protocol address
// };
//
//
// // IPv4 AF_INET sockets:
//
// struct sockaddr_in {
//     short             sin_family;           // 2 bytes,指代协议族，在socket编程中只能是AF_INET.  e.g. AF_INET, AF_INET6
//     unsigned short    sin_port;             // 2 bytes, 存储端口号(使用网络字节顺序). e.g. htons(3490)
//     struct in_addr    sin_addr;             // 4 bytes, 存储IP地址，使用in_addr这个数据结构
//     char              sin_zero[8];          // 8 bytes zero,是为了让sockaddr与sockaddr_in两个数据结构保持大小相同而保留的空字节
// };
//
//
// struct in_addr {
//     unsigned long s_addr;                   // 4 bytes load with inet_pton()
// };
//
//
//
int main(int argc, char **argv)
{
	char *file;
	char *host;

	if(argc < 3) {
		printf("%s file host\n\tsends file to host if you have access to it\n", argv[0]);
		exit(1);
	}

	file = argv[1];
	host = argv[2];

	if(access(argv[1], R_OK) == 0) {
		int fd;
		int ffd;
		int rc;


                struct sockaddr_in sin;
		char buffer[4096];

		printf("Connecting to %s:18211 .. ", host); fflush(stdout);
                // 建立好socket之后，就跟这个file descripter通信
		fd = socket(AF_INET, SOCK_STREAM, 0);
		// 使用memset函数初始化
		memset(&sin, 0, sizeof(struct sockaddr_in));
                // 一般用法为：
                // 程序员把类型、ip地址、端口填充sockaddr_in 结构体，然后强制转换成sockaddr， 作为参数传递给系统调用函数。
                
		/* 填充struct sockaddr_in */
		sin.sin_family = AF_INET; 
		sin.sin_addr.s_addr = inet_addr(host);
		sin.sin_port = htons(18211);
	        
		/* 强制转换成struct sockaddr */
		if(connect(fd, (void *)&sin, sizeof(struct sockaddr_in)) == -1) {
		// 若connect之后，返回失败(-1)
			printf("Unable to connect to host %s\n", host);
			exit(EXIT_FAILURE);
		}

#define HITHERE ".oO Oo.\n"
		if(write(fd, HITHERE, strlen(HITHERE)) == -1) {
			printf("Unable to write banner to host %s\n", host);
			exit(EXIT_FAILURE);
		}
#undef HITHERE

		printf("Connected!\nSending file .. "); fflush(stdout);

		ffd = open(file, O_RDONLY);
		if(ffd == -1) {
			printf("Damn. Unable to open file\n");
			exit(EXIT_FAILURE);
		}

		rc = read(ffd, buffer, sizeof(buffer));
		if(rc == -1) {
			printf("Unable to read from file: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}

		write(fd, buffer, rc);

		printf("wrote file!\n");

	} else {
		printf("You don't have access to %s\n", file);
	}
}
