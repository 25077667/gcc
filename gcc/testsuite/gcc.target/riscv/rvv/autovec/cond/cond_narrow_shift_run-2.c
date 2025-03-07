/* { dg-do run { target { riscv_vector } } } */
/* { dg-additional-options "--param=riscv-autovec-preference=scalable -fno-vect-cost-model" } */

#include "cond_narrow_shift-2.c"

#define N 99

#define TEST_LOOP(TYPE1, TYPE2)                                                \
  {                                                                            \
    TYPE2 r[N], a[N];                                                          \
    TYPE2 shift = 5;                                                           \
    TYPE1 b[N];                                                                \
    for (int i = 0; i < N; ++i)                                                \
      {                                                                        \
	a[i] = (i & 1 ? i : 3 * i);                                            \
	b[i] = (i >> 4) << (i & 15);                                           \
	asm volatile ("" ::: "memory");                                        \
      }                                                                        \
    test_##TYPE1##_##TYPE2 (r, a, b, shift, N);                                \
    for (int i = 0; i < N; ++i)                                                \
      if (r[i] != (a[i] > 20 ? (TYPE2) (b[i] >> shift) : r[i]))                \
	__builtin_abort ();                                                    \
  }

int
main ()
{
  TEST_ALL (TEST_LOOP)
  return 0;
}
