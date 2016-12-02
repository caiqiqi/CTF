#!/usr/bin/php

<?php
$secret = "xsdasd";
echo bin2hex(strrev(base64_encode($secret)));
echo "\n"
?>
