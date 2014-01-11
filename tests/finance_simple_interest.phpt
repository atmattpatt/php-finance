--TEST--
simple_interest
--SKIPIFF--
<?php if (!extension_loaded("finance")) print "skip"; ?>
--INI--
zend.enable_gc=0
--FILE--
<?php
$principle = 5000.00;
$rate      = 0.05999;
$time      = 24;

printf("%.4f", finance_simple_interest($principle, $rate, $time));
?>
--EXPECT--
7198.8000
