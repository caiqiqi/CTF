#include <stdio.h>
#include <string.h>
#include "flag.h"

void register_user(char *username, char *password);
int check_login(char *user, char *pass, char *username, char *password);


// 可见 logged_in 和 is_admin 要为某个非0 的值才可以进去
// 一种思路是通过注册一个超过 500 个字符的用户，覆盖掉is_admin 字段使其值为非0，然后以该帐号登录进去，
// 这样，logged_in 字段也非0了。可以执行到下面的 printf()

// 另一种思路是，通过覆盖掉flag变量后面的user和pw, 然后覆盖掉一部分sebuf()，至少需要 > 250 + 500 +500
// 所以先以某个正常的用户登录进去，然后选择4 store flag, 覆盖掉flag直到后面的setbuf。


int main() {
	char username[500]; // 注册时用的 username
	int is_admin = 0;  // 注册的时候如果超过500个字符，第501个字符会将 is_admin 的值覆盖为 1
	char password[500]; // 注册时用的 password
	int logged_in = 0;
	char flag[250];

	char user[500];    // 登录时用的 username
	char pw[500];      // 登录时用的 password
	setbuf(stdout, NULL);
	printf("Welcome to the FlagStore!\n");

	while (1) {
		printf("Choose an action:\n");
		printf("> %s: 1\n> %s: 2\n> %s: 3\n> %s: 4\n", "regiser", "login", "get_flag", "store_flag");
		int answer = 0;
		scanf("%d", &answer);

		switch(answer) {
			case 1:
				printf("Enter an username:");
				scanf("%s", username);
				printf("Enter a password:");
				scanf("%s", password);

				if(strcmp(username, "admin") == 0) {
					printf("Sorry, admin user already registered\n");
					break;
				}

				if(strlen(password) < 6) {
					printf("Sorry, password too short\n");
					break;
				}

				register_user(username, password);
				printf("User %s successfully registered. You can login now!\n", username);

				break;
			case 2:
				printf("Username:");
				scanf("%499s", user);
				printf("Password:");
				scanf("%499s", pw);

				if(check_login(user, pw, username, password) == -1) {
					printf("Wrong credentials!\n");
					break;
				}

				logged_in = 1;
				printf("You're now authenticated!\n");

				break;
			case 3:
				if(logged_in == 0) {
					printf("Please login first!\n");
					break;
				}

				if(is_admin != 0) {
					strcpy(flag, FLAG);
				}

				printf("Your flag: %s\n", flag);

				break;
			case 4:
				if(logged_in == 0) {
					printf("Please login first!\n");
					break;
				}

				printf("Enter your flag:");
				scanf("%s",flag);

				printf("Flag saved!\n");

				break;
			default:
				printf("Wrong option\nGood bye\n");
				return -1;
		}
	}
}

void register_user(char *username, char *password) {
	//XXX: Implement database connection
	return;
}

int check_login(char *user, char *pass, char *username, char *password) {
	if (strcmp(user, username) != 0 || strcmp(pass, password) != 0) {
		return -1;
	}
	return 0;
}