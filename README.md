# PrimeModule-ext

PHP extension for factorizing huge (up to 2^63-1) semiprimes.

API:

```
array factorize( mixed $pq )
```

Usage:
```
<?php
var_dump(factorize(2189285106422392999));
var_dump(factorize("2189285106422392999"));
```

This will output:

```
array(2) {
  [0]=>
  int(1117663223)
  [1]=>
  int(1958805713)
}
array(2) {
  [0]=>
  int(1117663223)
  [1]=>
  int(1958805713)
}
```

As you can see, the factorize function accepts integers and strings as parameter, so that if you're poor and you have only a 32 bit system, you will still be able to provide 64 bit integers as a string.

The function can throw an \Exception if factorization fails.
