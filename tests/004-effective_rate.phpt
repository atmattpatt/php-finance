--TEST--
Effective interest rate
--SKIPIF--
<?php if (!extension_loaded("finance")) print "skip"; ?>
--FILE--
<?php
$nrate = 0.05999; // Nominal rate
$nPer  = 4;

printf("%0.6f", finance_effective_rate($nrate, $nPer));
?>
--EXPECT--
0.061353
