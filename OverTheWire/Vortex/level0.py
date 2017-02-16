'''
Your goal is to connect to port 5842 on vortex.labs.overthewire.org and read in 4 unsigned integers in host byte order. Add these integers together and send back the results to get a username and password for vortex1. This information can be used to log in using SSH.
'''

import socket
import struct
import telnetlib
from hexdump import hexdump

def q(a):
    return struct.pack("I", a)

def interact():
    print " ** INTERACT **"
    t = telnetlib.Telnet()
    t.sock = s
    t.interact()


s = socket.create_connection(("vortex.labs.overthewire.org", 5842))

acc = 0

for i in range(4):
    acc += struct.unpack("I", s.recv(4))[0]

s.send(q(acc))

interact()


'''
Username: vortex1 Password: Gq#qu3bF3*** Connection closed by remote host ***
'''
