--TEST--
Future value of a lump sum
--SKIPIF--
<?php if (!extension_loaded("finance")) print "skip"; ?>
--FILE--
<?php
$pv   = 25000.00;
$rate = 0.0895;
$per  = 5;

printf("%0.4f", finance_fv($pv, $rate, $per));
?>
--EXPECT--
38377.4559
