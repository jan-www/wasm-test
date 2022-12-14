// emcc -Os -s STANDALONE_WASM -s EXPORTED_FUNCTIONS="['_multiply_arrays']" -Wl,--no-entry "simd.c" -o "simd.wasm" -msimd128 
#include <wasm_simd128.h>

void multiply_arrays(int* out, int* in_a, int* in_b, int size) {
  for (int i = 0; i < size; i += 4) {
    v128_t a = wasm_v128_load(&in_a[i]);
    v128_t b = wasm_v128_load(&in_b[i]);
    v128_t prod = wasm_i32x4_mul(wasm_i32x4_mul(a, b), a);
    wasm_v128_store(&out[i], prod);
  }
}