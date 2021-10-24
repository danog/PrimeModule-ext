#define FFI_SCOPE "primemodule"
#define FFI_LIB "libprimemodule.so"

// Returns at most a 32-bit signed int or -1
int32_t factorizeFFI(const char *number);
