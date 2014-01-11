--TEST--
Compound interest
--SKIPIF--
<?php if (!extension_loaded("finance")) print "skip"; ?>
--FILE--
<?php
$principle = 5000.00;
$rate      = 0.05999; // Annual rate
$nPer      = 12;      // compounded monthly
$per       = 2;       // 2 years

printf("%.4f", finance_compound_interest($principle, $rate, $per, $nPer));
?>
--EXPECT--
5635.6867
