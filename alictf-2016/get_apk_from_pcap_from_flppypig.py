#!/usr/bin/env python
import io
import struct
import sys

from scapy import *
from scapy.all import *

b = io.BytesIO()

rawpcap = rdpcap(sys.argv[1])
rawpcap = [_ for _ in rawpcap if TCP in _ and _[TCP].dport == 5555 and _[IP].src =="10.0.2.2" and Raw in _[IP] ]

rawpcap = next( rawpcap[i+1:] for i,p in enumerate(rawpcap) ifRaw inp andp[Raw].load.find('/data/local/tmp') !=-1 andp[Raw].load.find('SEND') != -1)

rawpcap = next( rawpcap[:i] for i,p in enumerate(rawpcap) ifRaw inp andp[Raw].load.find('pm \'install\'') != -1)

print(len(rawpcap))

#b.write(''.join([p[Raw].load[24:] for p inrawpcap if Raw in p ]))

for p in rawpcap:

if Rawin p:

data = p[Raw].load

if data.startswith('WRTE'):

data = data[24:]

b.write(data)

b.seek(0)

#print b.read()

a = open('out.apk','wb')

header = b.read(8)

while header != "":

tag, datalen =struct.unpack('<4sI',header)

if tag== "DATA":

a.write(b.read(datalen))

else:

break

header = b.read(8)
