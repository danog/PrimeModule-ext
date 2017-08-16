# PrimeModule-ext

PHP extension for factorizing huge (up to 2^63-1) numbers (optimized for huge semiprimes).

To compile it, simply install https://github.com/CopernicaMarketingSoftware/PHP-CPP and run `make && sudo make install` in this directory.

```
git clone https://github.com/CopernicaMarketingSoftware/PHP-CPP
cd PHP-CPP
make -j$(nproc)
sudo make install
cd ..
git clone https://github.com/danog/PrimeModule-ext
cd PrimeModule-ext
make -j$(nproc)
sudo make install
```

API:

```
integer factorize( mixed $pq )
```

Parameters:

pq - The number to factorize, a string or an integer.


Return value: an integer, containing one of the factors of the number.


Example:
```
<?php
var_dump(factorize(1724114033281923457));
var_dump(factorize("2189285106422392999"));
var_dump(factorize(15));
```

This will output:

```
int(1402015859)
int(1117663223)
int(5)
```

As you can see, the factorize function accepts integers and strings as parameter, so that if you're poor and you have only a 32 bit system, you will still be able to provide 64 bit integers as a string.

The function can throw an \Exception if factorization fails.
