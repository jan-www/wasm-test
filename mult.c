// emcc -Os -s STANDALONE_WASM -s EXPORTED_FUNCTIONS="['_multiply_arrays']" -Wl,--no-entry "mult.c" -o "mult.wasm"
void multiply_arrays(int* out, int* in_a, int* in_b, int size) {
  for (int i = 0; i < size; i += 1) {
     out[i] = in_a[i] * in_b[i] * in_a[i];
  }
}