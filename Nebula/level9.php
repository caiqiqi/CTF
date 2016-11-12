<?php

function spam($email)
{
  # functio preg_replace($pattern, $replacement, $subject)
  # 搜索$subject中匹配$pattern的部分，  以$replacement进行替换。
  $email = preg_replace("/\./", " dot ", $email);
  $email = preg_replace("/@/", " AT ", $email);
  
  return $email;
}

function markup($filename, $use_me)
{
  # fucntion file_get_contents($filename)
  # 将整个文件读入一个字符串
  $contents = file_get_contents($filename);

  $contents = preg_replace("/(\[email (.*)\])/e", "spam(\"\\2\")", $contents);
  $contents = preg_replace("/\[/", "<", $contents);
  $contents = preg_replace("/\]/", ">", $contents);

  return $contents;
}

$output = markup($argv[1], $argv[2]);

print $output;

?>
