--TEST--
Nominal interest rate
--SKIPIF--
<?php if (!extension_loaded("finance")) print "skip"; ?>
--FILE--
<?php
$erate = 0.06135; // Effective rate
$nPer  = 4;

printf("%0.6f", finance_nominal_rate($erate, $nPer));
?>
--EXPECT--
0.059987
