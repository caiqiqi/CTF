#coding=utf-8
#!/usr/bin/en python

import sys

ciphertext = sys.argv[1]
alphabet = list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")
plaintext = ""
shift = 1

while shift <= 26:
    for c in ciphertext:
        if c in alphabet:
	    plaintext += alphabet[(alphabet.index(c) + shift) % (len(alphabet))]
    
    print("[*] Shift used: " + str(shift))
    print("Plaintext: " + plaintext)
    print("======================")

    # 每一轮结束之后 shift加1, plaintext 清空
    shift = shift + 1
    plaintext = ""


## output
''' [*] Shift used: 14
Plaintext: CAESARISEASY
======================
'''
