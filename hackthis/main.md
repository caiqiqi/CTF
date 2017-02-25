# Main 2

这样都可以。。。把一个span的颜色弄成跟背景一个颜色就看不出来了。
需要改html源码, 把"color: #000000" 改成  "color: #ffffff"

               <label for="user">Username:</label> <span style="color: #000000">resu</span>
                <input type="Text" name="user" id="user" autocomplete="off"><br>
                <label for="user">Password:</label> <span style="color: #000000">ssap</span>

# Main 3
打开源码，搜索，当我输入`pass`准备继续输入的时候，发现前面的这段js脚本吸引了我。

```
<script type='text/javascript'> $(function(){ $('.level-form').submit(function(e){ if(document.getElementById('user').value == 'heaven' && document.getElementById('pass').value == 'hell') { } else { e.preventDefault(); alert('Incorrect login') } })})
</script>
```

意思是，对`level-form`这个表单的`submit`进行监听，如果'user'和'pass'满足条件，则什么都不做，提交到默认页面(当前页面?)，
否则alert('Incorrect login')
```
            <div class='level-form'>
                <form method="POST">
                    <fieldset>
                        <label for="user">Username:</label>
                        <input type='Text' autocomplete="off" id='user' name='user'><br>
                        <label for="user">Password:</label>
                        <input type='Password' autocomplete="off" id='pass' name='pass'><br>
                        <input type="submit" class="button" value="Submit">
                    </fieldset>
                </form>            
            </div>
```

# Main 8
在源码中找到这个
https://www.hackthis.co.uk/levels/extras/secret.txt
于是查看发现是01序列
```
1011 0000 0000 1011
1111 1110 1110 1101
```
于是查看HINT，说是base16
将其转换成
```
B00B
FDDE
```

# Main 9
看源码，找邮箱地址，换成自己的。
# Main 10
看源码，找到
https://www.hackthis.co.uk/levels/extras/level10pass.txt
"69bfe1e6e44821df7f8a0927bd7e61ef208fdb25deaa4353450bc3fb904abd52:f1abe1b083d12d181ae136cfc75b8d18a8ecb43ac4e9d1a36d6a9c75b6016b61"
看到冒号应该是两个hash的分割
于是用神站
http://hashtoolkit.com/
来crack这两个hash
"http://hashtoolkit.com/reverse-hash/?hash=69bfe1e6e44821df7f8a0927bd7e61ef208fdb25deaa4353450bc3fb904abd52" -> carl
"http://hashtoolkit.com/reverse-hash?hash=f1abe1b083d12d181ae136cfc75b8d18a8ecb43ac4e9d1a36d6a9c75b6016b61" -> guess
