def revStr(s):
    news=""
    for i in xrange(0,len(s),4):
    news+=s[i+2:i+4]
    news+=s[i:i+2]
    return news
def foo():
    f=open("funfile")
    s="377a"
    for line in f:
    s+=revStr(line.strip()[8:].replace(’ ‘,”))
    fsave=open('fun.7z','wb')
    fsave.write(s.decode(‘hex’))
    fsave.close()
if __name__ == '__main__':
    foo()
    print 'finished'