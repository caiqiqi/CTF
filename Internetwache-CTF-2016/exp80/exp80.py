from pwn import *

velf = ELF("./RemotePrinter")
getclose = velf.got["close"]
