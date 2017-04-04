# Boston Key Party CTF 2017 Writeup: Prudentialv2
参考：
https://0xd13a.github.io/ctfs/bkp2017/prudentialv2/

> Prudentialv2
> 50
> We fixed our challenge from two years ago.
> http://54.202.82.13/

这个网站要求登录
然后看到页面的源码发现：
```html
<a href="./index.txt">Level 1</a>
```
这个.txt文件是用来检查登录的源文件。这个文件里面有一个很奇怪的逻辑，咋一看感觉没法满足。
```php
<?php
require 'flag.php';

if (isset($_GET['name']) and isset($_GET['password'])) {
    $name = (string)$_GET['name'];
    $password = (string)$_GET['password'];

    if ($name == $password) {
        print 'Your password can not be your name.';
    } else if (sha1($name) === sha1($password)) {
      die('Flag: '.$flag);
    } else {
        print '<p class="alert">Invalid password.</p>';
    }
}
?>
```
也就是说username和password的值必须不同，但是他们的SHA1值必须相同。</br>
如果没有今年的这个[google的announcement](https://security.googleblog.com/2017/02/announcing-first-sha1-collision.html)，这几乎是不可能的。
然而，下载google提供的这两个文件之后验证了一下。
![](img/屏幕快照\ 2017-04-02\ 下午7.18.02.png)
