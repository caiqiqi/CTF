# level7
根据提示，可以输入一些Unix/Linux下的常见命令，看能否执行。
于是输入"2017;ls -l" 或者直接输入";ls -l"
即可得到"ls -l"命令的输出结果。从结果中可以看到存在一个"k1kh31b1n55h.php"文件，
于是访问这个url"http://www.hackthissite.org/missions/basic/7/k1kh31b1n55h.php" 得到密码

# level8
当输入了你的名字之后，服务端创建了一个一个不明其意的"randomjunk.shtml"。这一关与服务端包含 "Server Side Includes (SSI)"有关。
> SSI 就是在 HTML 文件中，可以通过注释行调用的命令或指针。
> SSI 具有强大的功能，只要使用一条简单的 SSI 命令就可以实现整个网站的内容更新，时间和日期的动态显示，以及执行 shell 和 CGI 脚本程序等复杂的功能。
参考：http://www.cnblogs.com/zichi/p/5111159.html
于是，只需要在输入名字的地方输入
```
<!--#exec cmd="ls ../"-->
```
即可执行`ls ../`的功能。然而当输入其他命令，比如`pwd`时，网站出于安全考虑不让这些命令执行。[笑cry]
> If you are trying to use server side includes to solve the challenge, you are on the right track: 
> but I have limited the commands allowed to ones relevant towards finding the password file for 
> security reasons(because there will always be that one person who decides to execute some rather nasty commands). 
> So please manipulate your code so that it is a little more pertaining to the level.
执行完之后得知有这样一个路径存在。"https://www.hackthissite.org/missions/basic/8/au12ha39vc.php"
于是加载这个url之后，得到
ab676504
参考：https://www.aldeid.com/wiki/Hackthissite/Basic/Level8

# level9

