<?php
if (!function_exists("fibonacci")) {
    print("Function fibonacci does not exist... Maybe it's not loaded into PHP ? \n");
    exit(1);
}
print("Calculating fibonacci for 5 ...\n");
print("And its: " . fibonacci(5));
exit(0);











$br = (php_sapi_name() == "cli")? "":"<br>";

if(!extension_loaded('util')) {
	dl('util.' . PHP_SHLIB_SUFFIX);
}
$module = 'util';
$functions = get_extension_funcs($module);
echo "Functions available in the test extension:$br\n";
foreach($functions as $func) {
    echo $func."$br\n";
}
echo "$br\n";
$function = 'confirm_' . $module . '_compiled';
if (extension_loaded($module)) {
	$str = $function($module);
} else {
	$str = "Module $module is not compiled into PHP";
}
echo "$str\n";
?>
