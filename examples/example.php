<?php

$f = FFI::load("/usr/include/primemodule-ffi.h");

// Always pass strings to allow 64-bit factorization with no loss of precision on 32-bit PHP.
var_dump($f->factorizeFFI("2189285106422392999"));
