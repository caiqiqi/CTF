#!/bin/python
import os;

for i in range(10,100,10):
        a="A"*i+"BBBB"+"CCCC"
        print "--------------------------------------------------------------"
        print "- " + str(i) + " A's"
        ret = os.system("echo " + a + " | ./talisman")
        if ret <> 0:
                break  
