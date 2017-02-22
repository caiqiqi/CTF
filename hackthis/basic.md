# Basic+ Level 7
根据提示，
We are running a suspicious looking service. Maybe it will give you the answer. 
用nmap扫描 www.hackthis.co.uk


Nmap scan report for www.hackthis.co.uk (85.159.213.101)
Host is up (0.29s latency).
Not shown: 65521 filtered ports
PORT     STATE  SERVICE
22/tcp   open   ssh
80/tcp   open   http
81/tcp   closed hosts2-ns
443/tcp  open   https
2428/tcp closed ott
6379/tcp closed redis
6459/tcp open   unknown
6460/tcp open   unknown
6697/tcp closed ircs-u
6699/tcp closed napster
6776/tcp open   unknown
7030/tcp closed op-probe
7031/tcp open   iposplanet
8080/tcp open   http-proxy

Read data files from: /usr/local/bin/../share/nmap
Nmap done: 1 IP address (1 host up) scanned in 691.00 seconds
➜  hackthis git:(master) nc www.hackthis.co.uk 6459                                           [11:56:11]
^C
➜  hackthis git:(master) nc www.hackthis.co.uk 6460                                           [12:30:40]
^C
➜  hackthis git:(master) nc www.hackthis.co.uk 6776                                           [12:31:07]
Welcome weary traveller. I believe you are looking for this: mapthat
