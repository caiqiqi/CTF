#!/usr/bin/env python

import base64
from scapy.all import *

packets = rdpcap("a.pcap")
fp = file("ColorOverflow-extract.apk", "wb")

ranges = [(610,637),(641,908),(912,1178),(1183,1274)]

for start,end in ranges:
    for i in range(start, end+1):
        packets = packets[i]
	for TCP in packet[TCP] and packet.sport == 33946:
	    if packet[IP].dst == "10.0.2.15" and Raw in packet[TCP]:
	        if i == 610:
		    fp.write(packet[TCP][Raw].load[32:])
		elif i == start:
		    fp.write(packet[TCP][Raw].load[24:])
		else:
		    out = packet[TCP][Raw].load
		    if "DATA" in out:
		        offset = out.find("DATA")
			out = out[:offset] + out[offset+8:]
	            fp.write(out)
fp.close()
