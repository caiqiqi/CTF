参考:
https://sdsdkkk.github.io/2016/vulnhub-necromancer-writeup/
https://m4ng0n3l.github.io/articles/2016-09/vulnhub-necromancer

发现局域网上的主机的一个好方法:
```sh
netdiscover -r 192.168.170.0/24
```
列出改网段up的主机IP和Mac以及根据Mac地址得出的网卡厂商
## flag1
### using tshark
```sh
# tshark -i eth0 -f "tcp port 4444"
```
得到
```sh
str="V2VsY29tZSENCg0KWW91IGZpbmQgeW91cnNlbGYgc3RhcmluZyB0b3dhcmRzIHRoZSBob3Jpem9uLCB3aXRoIG5vdGhpbmcgYnV0IHNpbGVuY2Ugc3Vycm91bmRpbmcgeW91Lg0KWW91IGxvb2sgZWFzdCwgdGhlbiBzb3V0aCwgdGhlbiB3ZXN0LCBhbGwgeW91IGNhbiBzZWUgaXMgYSBncmVhdCB3YXN0ZWxhbmQgb2Ygbm90aGluZ25lc3MuDQoNClR1cm5pbmcgdG8geW91ciBub3J0aCB5b3Ugbm90aWNlIGEgc21hbGwgZmxpY2tlciBvZiBsaWdodCBpbiB0aGUgZGlzdGFuY2UuDQpZb3Ugd2FsayBub3J0aCB0b3dhcmRzIHRoZSBmbGlja2VyIG9mIGxpZ2h0LCBvbmx5IHRvIGJlIHN0b3BwZWQgYnkgc29tZSB0eXBlIG9mIGludmlzaWJsZSBiYXJyaWVyLiAgDQoNClRoZSBhaXIgYXJvdW5kIHlvdSBiZWdpbnMgdG8gZ2V0IHRoaWNrZXIsIGFuZCB5b3VyIGhlYXJ0IGJlZ2lucyB0byBiZWF0IGFnYWluc3QgeW91ciBjaGVzdC4gDQpZb3UgdHVybiB0byB5b3VyIGxlZnQuLiB0aGVuIHRvIHlvdXIgcmlnaHQhICBZb3UgYXJlIHRyYXBwZWQhDQoNCllvdSBmdW1ibGUgdGhyb3VnaCB5b3VyIHBvY2tldHMuLiBub3RoaW5nISAgDQpZb3UgbG9vayBkb3duIGFuZCBzZWUgeW91IGFyZSBzdGFuZGluZyBpbiBzYW5kLiAgDQpEcm9wcGluZyB0byB5b3VyIGtuZWVzIHlvdSBiZWdpbiB0byBkaWcgZnJhbnRpY2FsbHkuDQoNCkFzIHlvdSBkaWcgeW91IG5vdGljZSB0aGUgYmFycmllciBleHRlbmRzIHVuZGVyZ3JvdW5kISAgDQpGcmFudGljYWxseSB5b3Uga2VlcCBkaWdnaW5nIGFuZCBkaWdnaW5nIHVudGlsIHlvdXIgbmFpbHMgc3VkZGVubHkgY2F0Y2ggb24gYW4gb2JqZWN0Lg0KDQpZb3UgZGlnIGZ1cnRoZXIgYW5kIGRpc2NvdmVyIGEgc21hbGwgd29vZGVuIGJveC4gIA0KZmxhZzF7ZTYwNzhiOWIxYWFjOTE1ZDExYjlmZDU5NzkxMDMwYmZ9IGlzIGVuZ3JhdmVkIG9uIHRoZSBsaWQuDQoNCllvdSBvcGVuIHRoZSBib3gsIGFuZCBmaW5kIGEgcGFyY2htZW50IHdpdGggdGhlIGZvbGxvd2luZyB3cml0dGVuIG9uIGl0LiAiQ2hhbnQgdGhlIHN0cmluZyBvZiBmbGFnMSAtIHU2NjYi"
echo $str|base64 -d
```
得到
'Welcome!

You find yourself staring towards the horizon, with nothing but silence surrounding you.
You look east, then south, then west, all you can see is a great wasteland of nothingness.

Turning to your north you notice a small flicker of light in the distance.
You walk north towards the flicker of light, only to be stopped by some type of invisible barrier.  

The air around you begins to get thicker, and your heart begins to beat against your chest. 
You turn to your left.. then to your right!  You are trapped!

You fumble through your pockets.. nothing!  
You look down and see you are standing in sand.  
Dropping to your knees you begin to dig frantically.

As you dig you notice the barrier extends underground!  
Frantically you keep digging and digging until your nails suddenly catch on an object.

You dig further and discover a small wooden box.  
flag1{e6078b9b1aac915d11b9fd59791030bf} is engraved on the lid.

You open the box, and find a parchment with the following written on it. "Chant the string of flag1 - u666"#'


flag1{e6078b9b1aac915d11b9fd59791030bf}

## flag2
将该hash在`hashid`中识别
得到应该是md5类型的。
通过强大的在线md5, sha逆向网站 'http://hashtoolkit.com/'
得到其原始字符串为 'opensesame'
根据其提示: '"Chant the string of flag1 - u666'
通过本地监听在与Necro网卡同一网段的那个网卡上,把 'opensesame' chant给Necro

```sh
echo opensesame |nc -u 192.168.170.159 666
```

得到
'
A loud crack of thunder sounds as you are knocked to your feet!

Dazed, you start to feel fresh air entering your lungs.

You are free!

In front of you written in the sand are the words:

flag2{c39cd4df8f2e35d20d92c2e44de5f7c6}

As you stand to your feet you notice that you can no longer see the flicker of light in the distance.

You turn frantically looking in all directions until suddenly, a murder of crows appear on the horizon.

As they get closer you can see one of the crows is grasping on to an object. As the sun hits the object, shards of light beam from its surface.

The birds get closer, and closer, and closer.

Staring up at the crows you can see they are in a formation.

Squinting your eyes from the light coming from the object, you can see the formation looks like the numeral 80.

As quickly as the birds appeared, they have left you once again.... alone... tortured by the deafening sound of silence.

666 is closed.
'

flag2{c39cd4df8f2e35d20d92c2e44de5f7c6}

## flag3

然后用nmap扫一下端口发现，发现80端口已经打开了。
于是curl一下主页。查看源代码没发现什么不同的，只有一张图片。
`<img src="/pics/pileoffeathers.jpg">`
用wget下载该图片,
```sh
wget http://192.168.170.159/
```
于是在kali中用`hexeditor`分析该图片。

### 方法一: 直接将jpg文件重命名为zip文件然后解压缩
然后
```sh
cp pileoffeathers.jpg pileoffeathers.zip
```
然后解压缩
```sh
unzip pileoffeathers.zip
```
得到一个feathers.txt
cat feathers.txt 
得到一个base64字符串 
'ZmxhZzN7OWFkM2Y2MmRiN2I5MWMyOGI2ODEzNzAwMDM5NDYzOWZ9IC0gQ3Jvc3MgdGhlIGNoYXNtIGF0IC9hbWFnaWNicmlkZ2VhcHBlYXJzYXR0aGVjaGFzbQ=='
将其解码, 
```sh
echo $str |base64 -d
```

得到
flag3{9ad3f62db7b91c28b68137000394639f} - Cross the chasm at /amagicbridgeappearsatthechasm

###方法二: 用`binwalk -e`拉出改文件中所有的东西
```sh
binwalk -e pileoffeathers.jpg
```
得到一个解压出来的目录,包括一个zip压缩文件9082.zip,和一个文本文件feathers.txt
其他的同方法一。

进入到 
http://192.168.170.159/amagicbridgeappearsatthechasm/
注意这个最后面的/ 不能丢，否则会碰到301

通过用kali中的内置字典穷举目录,
```sh
dirb http://192.168.170.159/amagicbridgeappearsatthechasm/ /usr/share/wordlists/dirbuster/directory-list-2.3-small.txt
```

```
➜  ~ dirb http://192.168.170.159/amagicbridgeappearsatthechasm/ /usr/share/wordlists/dirbuster/directory-list-2.3-small.txt

-----------------
DIRB v2.22    
By The Dark Raver
-----------------

START_TIME: Fri Dec  2 21:20:01 2016
URL_BASE: http://192.168.170.159/amagicbridgeappearsatthechasm/
WORDLIST_FILES: /usr/share/wordlists/dirbuster/directory-list-2.3-small.txt

-----------------

GENERATED WORDS: 87568                                                                         

---- Scanning URL: http://192.168.170.159/amagicbridgeappearsatthechasm/ ----
+ http://192.168.170.159/amagicbridgeappearsatthechasm/talisman (CODE:200|SIZE:9676)                  
^C> Testing: http://192.168.170.159/amagicbridgeappearsatthechasm/payload
```
得到一个taliman目录/文件.
wget下来,是一个32位的可执行ELF文件。
由于是32位的，而我手里的机器都是64位的，于是丢到我实验室的小鸡子上跑一下吧。
```sh
➜  /tmp file talisman
talisman: ELF 32-bit LSB  executable, Intel 80386, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.32, BuildID[sha1]=2b131df906087adf163f8cba1967b3d2766e639d, not stripped
➜  /tmp chmod +x talisman
➜  /tmp ./talisman
You have found a talisman.

The talisman is cold to the touch, and has no words or symbols on it's surface.

Do you want to wear the talisman?  yes

Nothing happens.
```
既然他可以接收输出，那可以试一下可不可以让它crash。

用python生成100个A作为`talisman`的输入。
```sh
python -c 'print "A"*100' |  ./talisman
```

看到别人博客上推荐的gdb的插件, 
https://github.com/longld/peda.git
![](img/屏幕快照\ 2016-12-02\ 下午10.14.55.png)
还蛮好看的，给我做实验用的ubuntu和实验室的小鸡子都装上了。


用
```sh
objdump -d talisman
```
反汇编查看其包含哪些函数.
![](屏幕快照\ 2016-12-02\ 下午10.32.22.png)
to be continued...
