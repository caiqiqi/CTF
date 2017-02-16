<?php
$cipher = 'a1zLbgQsCESEIqRLwuQAyMwLyq2L5VwBxqGA3RQAyumZ0tmMvSGM2ZwB4tws';  
$tmp = base64_decode(strrev(str_rot13($cipher)));  
echo $tmp;  
$b = '';  
for ($i=0; $i < strlen($tmp); $i++) {   
     $a = substr($tmp, $i, 1);  
     $b = $b.chr(ord($a)-1);  
}
echo strrev($b);
?>

