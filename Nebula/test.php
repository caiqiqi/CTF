<?php

function spam($email)
{
  $email = preg_replace("/\./", " dot ", $email);
  $email = preg_replace("/\@/", " at ", $email);

  return $email;
}
