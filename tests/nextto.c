#include "testconfig.h"
#ifdef HAVE_NEXTTOWARD
#define TEST_FUNC_FF_F __MATH_PRECNAME(nexttoward)
#include "testdriver.h"

#define FP_FLT_MAX_P HEXCONSTE(3.4028234663852885981170e+38, 0x407e, 0xffffff00L, 0x00000000L)
#define FP_FLT_MAX_M HEXCONSTE(-3.4028234663852885981170e+38, 0xc07e, 0xffffff00L, 0x00000000L)
#define FP_FLT_MIN_P HEXCONSTE(1.1754943508222875e-38, 0x3f80, 0xffffffffL, 0xffffff83L)
#define FP_FLT_MIN_M HEXCONSTE(-1.1754943508222875e-38, 0xbf80, 0xffffffffL, 0xffffff83L)


/* FIXME: 2nd arg always long double */
static test_ff_f_data const nexttoward_data[] = {
	{ __LINE__, ZERO_P, ZERO_P, ZERO_P, NO_INEXACT_EXCEPTION },
	{ __LINE__, ZERO_M, ZERO_P, ZERO_P, NO_INEXACT_EXCEPTION },
	{ __LINE__, ZERO_P, ZERO_M, ZERO_M, NO_INEXACT_EXCEPTION },
	{ __LINE__, ZERO_M, ZERO_M, ZERO_M, NO_INEXACT_EXCEPTION },
	{ __LINE__, ZERO_P, INF_P, ZERO_P, UNDERFLOW_EXCEPTION },
	{ __LINE__, ZERO_P, INF_M, ZERO_M, UNDERFLOW_EXCEPTION },
	{ __LINE__, ZERO_M, INF_P, ZERO_M, UNDERFLOW_EXCEPTION },
	{ __LINE__, ZERO_M, INF_M, ZERO_M, UNDERFLOW_EXCEPTION },

	{ __LINE__, HEXCONSTE(9, 0x4002, 0x90000000L, 0x00000000L), HEXCONSTE(9, 0x4002, 0x90000000L, 0x00000000L), HEXCONSTE(9, 0x4002, 0x90000000L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-9, 0xc002, 0x90000000L, 0x00000000L), HEXCONSTE(-9, 0xc002, 0x90000000L, 0x00000000L), HEXCONSTE(-9, 0xc002, 0x90000000L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, INF_P, INF_P, INF_P, NO_INEXACT_EXCEPTION },
	{ __LINE__, INF_M, INF_M, INF_M, NO_INEXACT_EXCEPTION },

	{ __LINE__, QNAN_P, HEXCONSTE(1.1L, 0x3fff, 0x8cccccccL, 0xcccccccdL), QNAN_P, NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(1.1L, 0x3fff, 0x8cccccccL, 0xcccccccdL), QNAN_P, QNAN_P, NO_INEXACT_EXCEPTION },
	{ __LINE__, QNAN_P, QNAN_P, QNAN_P, NO_INEXACT_EXCEPTION },

#ifdef TEST_FLOAT
	{ __LINE__, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(1.1L, 0x3fff, 0x8cccccccL, 0xcccccccdL), HEXCONSTE(1.00000011920928955078e+00, 0x3fff, 0x80000100L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), MAX_P, HEXCONSTE(1.00000011920928955078e+00, 0x3fff, 0x80000100L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(1.00000000000000022204e+00, 0x3fff, 0x80000000L, 0x00000800L), HEXCONSTE(1.00000011920928955078e+00, 0x3fff, 0x80000100L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(0.9L, 0x3ffe, 0xe6666666L, 0x66666666L), HEXCONSTE(9.99999940395355224609e-01, 0x3ffe, 0xffffff00L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), MAX_M, 0x0.ffffffp0, NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(9.99999999999999888978e-01, 0x3ffe, 0xffffffffL, 0xfffff800L), HEXCONSTE(9.99999940395355224609e-01, 0x3ffe, 0xffffff00L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), HEXCONSTE(-1.1L, 0xbfff, 0x8cccccccL, 0xcccccccdL), HEXCONSTE(-1.00000011920928955078e+00, 0xbfff, 0x80000100L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), MAX_M, HEXCONSTE(-1.00000011920928955078e+00, 0xbfff, 0x80000100L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), HEXCONSTE(-1.00000000000000022204e+00, 0xbfff, 0x80000000L, 0x00000800L), HEXCONSTE(-1.00000011920928955078e+00, 0xbfff, 0x80000100L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), HEXCONSTE(-0.9L, 0xbffe, 0xe6666666L, 0x66666666L), HEXCONSTE(-9.99999940395355224609e-01, 0xbffe, 0xffffff00L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), MAX_P, HEXCONSTE(-9.99999940395355224609e-01, 0xbffe, 0xffffff00L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), HEXCONSTE(-9.99999999999999888978e-01, 0xbffe, 0xffffffffL, 0xfffff800L), HEXCONSTE(-9.99999940395355224609e-01, 0xbffe, 0xffffff00L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-2.66246708221715243476e-44, 0xbf6e, 0x98000000L, 0x00000000L), HEXCONSTE(-2.80259692864963414185e-44, 0xbf6e, 0xa0000000L, 0x00000000L), HEXCONSTE(-2.80259692864963414185e-44, 0xbf6e, 0xa0000000L, 0x00000000L), INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION },
	{ __LINE__, FP_FLT_MAX_P, HEXCONSTE(6.8056471355946732327508e+38, 0x407f, 0xffffff80L, 0x00000000L), INF_P, OVERFLOW_EXCEPTION },
	{ __LINE__, FP_FLT_MAX_M, HEXCONSTE(-6.8056471355946732327508e+38, 0xc07f, 0xffffff80L, 0x00000000L), INF_M, OVERFLOW_EXCEPTION },
	{ __LINE__, FP_FLT_MIN_P, ZERO_P, ZERO_P, UNDERFLOW_EXCEPTION },
	{ __LINE__, FP_FLT_MIN_M, ZERO_M, ZERO_M, UNDERFLOW_EXCEPTION },
# if LDBL_MANT_DIG >= 64
	{ __LINE__, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(1.00000000000000000173e+00, 0x3fff, 0x80000000L, 0x00000010L), HEXCONSTE(1.00000011920928955078e+00, 0x3fff, 0x80000100L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(9.99999999999999999946e-01, 0x3ffe, 0xffffffffL, 0xffffffffL), HEXCONSTE(9.99999940395355224609e-01, 0x3ffe, 0xffffff00L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), HEXCONSTE(-1.00000000000000000173e+00, 0xbfff, 0x80000000L, 0x00000010L), HEXCONSTE(-1.00000011920928955078e+00, 0xbfff, 0x80000100L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), HEXCONSTE(-9.99999999999999999946e-01, 0xbffe, 0xffffffffL, 0xffffffffL), HEXCONSTE(-9.99999940395355224609e-01, 0xbffe, 0xffffff00L, 0x00000000L), NO_INEXACT_EXCEPTION },
# endif
#endif
#ifdef TEST_DOUBLE
	{ __LINE__, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(1.1L, 0x3fff, 0x8cccccccL, 0xcccccccdL), HEXCONSTE(1.00000000000000022204e+00, 0x3fff, 0x80000000L, 0x00000800L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), MAX_P, HEXCONSTE(1.00000000000000022204e+00, 0x3fff, 0x80000000L, 0x00000800L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(1.00000000000000022204e+00, 0x3fff, 0x80000000L, 0x00000800L), HEXCONSTE(1.00000000000000022204e+00, 0x3fff, 0x80000000L, 0x00000800L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(0.9L, 0x3ffe, 0xe6666666L, 0x66666666L), HEXCONSTE(9.99999999999999888978e-01, 0x3ffe, 0xffffffffL, 0xfffff800L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), MAX_P, HEXCONSTE(9.99999999999999888978e-01, 0x3ffe, 0xffffffffL, 0xfffff800L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(9.99999999999999888978e-01, 0x3ffe, 0xffffffffL, 0xfffff800L), HEXCONSTE(9.99999999999999888978e-01, 0x3ffe, 0xffffffffL, 0xfffff800L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), HEXCONSTE(-1.1L, 0xbfff, 0x8cccccccL, 0xcccccccdL), HEXCONSTE(-1.00000000000000022204e+00, 0xbfff, 0x80000000L, 0x00000800L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), MAX_M, HEXCONSTE(-1.00000000000000022204e+00, 0xbfff, 0x80000000L, 0x00000800L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), HEXCONSTE(-1.00000000000000022204e+00, 0xbfff, 0x80000000L, 0x00000800L), HEXCONSTE(-1.00000000000000022204e+00, 0xbfff, 0x80000000L, 0x00000800L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), HEXCONSTE(-0.9L, 0xbffe, 0xe6666666L, 0x66666666L), HEXCONSTE(-9.99999999999999888978e-01, 0xbffe, 0xffffffffL, 0xfffff800L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), MAX_P, HEXCONSTE(-9.99999999999999888978e-01, 0xbffe, 0xffffffffL, 0xfffff800L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), HEXCONSTE(-9.99999999999999888978e-01, 0xbffe, 0xffffffffL, 0xfffff800L), HEXCONSTE(-9.99999999999999888978e-01, 0xbffe, 0xffffffffL, 0xfffff800L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), HEXCONSTE(-1.00009999999999998899e+00, 0xbfff, 0x800346dcL, 0x5d638800L), HEXCONSTE(-1.00000000000000022204e+00, 0xbfff, 0x80000000L, 0x00000800L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(4.94065645841246544177e-324, 0x3bcd, 0x80000000L, 0x00000000L), HEXCONSTE(9.88131291682493088353e-324, 0x3bce, 0x80000000L, 0x00000000L), HEXCONSTE(9.88131291682493088353e-324, 0x3bce, 0x80000000L, 0x00000000L), INEXACT_EXCEPTION|UNDERFLOW_EXCEPTION },
# if LDBL_MANT_DIG >= 64
	{ __LINE__, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(1.00000000000000000173e+00, 0x3fff, 0x80000000L, 0x00000010L), HEXCONSTE(1.00000000000000022204e+00, 0x3fff, 0x80000000L, 0x00000800L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(9.99999999999999999946e-01, 0x3ffe, 0xffffffffL, 0xffffffffL), HEXCONSTE(9.99999999999999888978e-01, 0x3ffe, 0xffffffffL, 0xfffff800L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), HEXCONSTE(-1.00000000000000000173e+00, 0xbfff, 0x80000000L, 0x00000010L), HEXCONSTE(-1.00000000000000022204e+00, 0xbfff, 0x80000000L, 0x00000800L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), HEXCONSTE(-9.99999999999999999946e-01, 0xbffe, 0xffffffffL, 0xffffffffL), HEXCONSTE(-9.99999999999999888978e-01, 0xbffe, 0xffffffffL, 0xfffff800L), NO_INEXACT_EXCEPTION },
# endif
#if DBL_MAX_EXP != LDBL_MAX_EXP
	{ __LINE__, HEXCONSTE(-1.7976931348623157081453e+308, 0x43fe, 0xffffffffL, 0xfffff800L), HEXCONSTE(1.7986931348623157080845e+308, 0x43ff, 0x80123a51L, 0x6e82d5baL), INF_P, OVERFLOW_EXCEPTION },
	{ __LINE__, HEXCONSTE(-1.7976931348623157081453e+308, 0xc3fe, 0xffffffffL, 0xfffff800L), HEXCONSTE(-1.7986931348623157080845e+308, 0xc3ff, 0x80123a51L, 0x6e82d5baL), INF_M, OVERFLOW_EXCEPTION },
#endif
	{ __LINE__, HEXCONSTE(2.2250738585072013830902e-308, 0x3c01, 0x80000000L, 0x00000000L), ZERO_P, ZERO_P, UNDERFLOW_EXCEPTION },
	{ __LINE__, HEXCONSTE(-2.2250738585072013830902e-308, 0xbc01, 0x80000000L, 0x00000000L), ZERO_M, ZERO_M, UNDERFLOW_EXCEPTION },
#endif
#ifdef TEST_LDOUBLE
	{ __LINE__, MAX_P, INF_P, INF_P, OVERFLOW_EXCEPTION },
	{ __LINE__, MAX_M, INF_M, INF_M, OVERFLOW_EXCEPTION },
	{ __LINE__, MIN_P, ZERO_P, ZERO_P, UNDERFLOW_EXCEPTION },
	{ __LINE__, MIN_M, ZERO_M, ZERO_M, UNDERFLOW_EXCEPTION },
#endif
};

int main(int argc, char **argv)
{
	int status;
	
	status = 0;
	
	test_init(argc, argv);
	
	status |= test_table_ff_f(nexttoward_data, ARRAY_SIZE(nexttoward_data), __FILE__);
	
	return status ? EXIT_FAILURE : EXIT_SUCCESS;
}

#else

int main(void)
{
	return 77;
}

#endif