# PrimeModule-ext

C++ header-only library, binary and FFI library for factorizing huge (up to 2^63-1) numbers (optimized for huge semiprimes).

## Install

Arch Linux (AUR):
```bash
paru -S primemodule
```

Debian/Ubuntu:
```
sudo apt-get install build-essential && git clone https://github.com/danog/PrimeModule-ext && cd PrimeModule-ext && make -j$(nproc) && sudo make install
```

## API

### Binary

```bash
primemodule number
```  

On success (return code 0), prints to stdout one of the prime factors of `number`.

### C++

```c++
uint32_t PrimeModule::factorize(uint64_t number);
```

Returns one of the prime factors of `number`, throws an std::runtime_error on failure.

### C

```c
int64_t factorize(uint64_t number);
```

Returns one of the prime factors of `number`, returns -1 on failure.


### PHP

```php
<?php

$f = FFI::load("/usr/include/primemodule-ffi.h");

// Always pass strings to allow 64-bit factorization with no loss of precision on 32-bit PHP.
var_dump($f->factorizeFFI("2189285106422392999"));
```

Returns one of the prime factors of `2189285106422392999`, returns -1 on failure.
