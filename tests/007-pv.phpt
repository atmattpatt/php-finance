--TEST--
Present value of a lump sum
--SKIPIF--
<?php if (!extension_loaded("finance")) print "skip"; ?>
--FILE--
<?php
$fv   = 25000.00;
$rate = 0.0895;
$per  = 5;

printf("%0.4f", finance_pv($fv, $rate, $per));
?>
--EXPECT--
16285.6027
