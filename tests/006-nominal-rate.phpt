--TEST--
Nominal interest rate is inverse of effective interest rate
--SKIPIF--
<?php if (!extension_loaded("finance")) print "skip"; ?>
--FILE--
<?php
$nrate = 0.059999; // Nominal rate
$nPer  = 4;

printf("%0.6f", finance_nominal_rate(
	finance_effective_rate($nrate, $nPer),
	$nPer
));
?>
--EXPECT--
0.059999
