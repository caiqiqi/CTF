#!/usr/bin/php
<!--?php 
// This php code needs to decrypt the following proccess. 
// bin2hex(strrev(base64_encode($secret))) 
// The string to decrypt is '3d3d516343746d4d6d6c315669563362'. 
echo base64_decode(strrev(hex2bin('3d3d516343746d4d6d6c315669563362'))); 
?-->

<?php
echo base64_decode(strrev(hex2bin('3d3d516343746d4d6d6c315669563362')));
echo "\n"
?>
