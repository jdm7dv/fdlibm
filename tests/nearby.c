#include "testconfig.h"
#if defined(HAVE_NEARBYINT)
#define TEST_FUNC_F_F __MATH_PRECNAME(nearbyint)
#include "testdriver.h"



static test_f_f_data const nearbyint_data[] = {
	{ __LINE__, QNAN_P, QNAN_P, 0 },
	{ __LINE__, QNAN_M, QNAN_P, 0 },
	{ __LINE__, SNAN_P, QNAN_P, 0 },
	{ __LINE__, SNAN_M, QNAN_P, 0 },
	{ __LINE__, INF_P, INF_P, 0 },
	{ __LINE__, INF_M, INF_M, 0 },
	{ __LINE__, ZERO_P, ZERO_P, 0 },
	{ __LINE__, ZERO_M, ZERO_M, FLAG_IGNORE_ZEROSIGN },
	{ __LINE__, SUBNORM_P, ZERO_P, FLAG_SUBNORM },
	{ __LINE__, SUBNORM_M, ZERO_M, FLAG_SUBNORM },
	{ __LINE__, MIN_P, ZERO_P, 0 },
	{ __LINE__, MIN_M, ZERO_M, 0 },
	{ __LINE__, MAX_P, MAX_P, 0 },
	{ __LINE__, MAX_M, MAX_M, 0 },
	
	/* Subnormal values */
	{ __LINE__, HEXCONSTE(-8.98847e+307, 0xc3fe, 0x80000409L, 0x7954f717L), HEXCONSTE(-8.98847e+307, 0xc3fe, 0x80000409L, 0x7954f717L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-4.45015e-308, 0xbc02, 0x8000044dL, 0xb01f4deeL), ZERO_M, NO_INEXACT_EXCEPTION|FLAG_IGNORE_ZEROSIGN },

	/* Default rounding mode is round to nearest.  */
	{ __LINE__, HEXCONSTE(0.5, 0x3ffe, 0x80000000L, 0x00000000L), ZERO_P, NO_INEXACT_EXCEPTION|FLAG_FAIL_ARANYM }, /* FIXME: x86 used round-to-odd */
	{ __LINE__, HEXCONSTE(1.5, 0x3fff, 0xc0000000L, 0x00000000L), HEXCONSTE(2.0, 0x4000, 0x80000000L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-0.5, 0xbffe, 0x80000000L, 0x00000000L), ZERO_M, NO_INEXACT_EXCEPTION|FLAG_FAIL_ARANYM }, /* FIXME: x86 used round-to-odd */
	{ __LINE__, HEXCONSTE(-1.5, 0xbfff, 0xc0000000L, 0x00000000L), HEXCONSTE(-2.0, 0xc000, 0x80000000L, 0x00000000L), NO_INEXACT_EXCEPTION },

	{ __LINE__, HEXCONSTE(262144.75, 0x4011, 0x80001800L, 0x00000000L), HEXCONSTE(262145.0, 0x4011, 0x80002000L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(262142.75, 0x4010, 0xffffb000L, 0x00000000L), HEXCONSTE(262143.0, 0x4010, 0xffffc000L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(524286.75, 0x4011, 0xffffd800L, 0x00000000L), HEXCONSTE(524287.0, 0x4011, 0xffffe000L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(524288.75, 0x4012, 0x80000c00L, 0x00000000L), HEXCONSTE(524289.0, 0x4012, 0x80001000L, 0x00000000L), NO_INEXACT_EXCEPTION },

	{ __LINE__, HEXCONSTE(1048576.75, 0x4013, 0x80000600L, 0x00000000L), HEXCONSTE(1048577.0, 0x4013, 0x80000800L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(2097152.75, 0x4014, 0x80000300L, 0x00000000L), HEXCONSTE(2097153.0, 0x4014, 0x80000400L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(2492472.75, 0x4014, 0x9820e300L, 0x00000000L), HEXCONSTE(2492473.0, 0x4014, 0x9820e400L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(2886220.75, 0x4014, 0xb0293300L, 0x00000000L), HEXCONSTE(2886221.0, 0x4014, 0xb0293400L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(3058792.75, 0x4014, 0xbab1a300L, 0x00000000L), HEXCONSTE(3058793.0, 0x4014, 0xbab1a400L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-1048576.75, 0xc013, 0x80000600L, 0x00000000L), HEXCONSTE(-1048577.0, 0xc013, 0x80000800L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-2097152.75, 0xc014, 0x80000300L, 0x00000000L), HEXCONSTE(-2097153.0, 0xc014, 0x80000400L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-2492472.75, 0xc014, 0x9820e300L, 0x00000000L), HEXCONSTE(-2492473.0, 0xc014, 0x9820e400L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-2886220.75, 0xc014, 0xb0293300L, 0x00000000L), HEXCONSTE(-2886221.0, 0xc014, 0xb0293400L, 0x00000000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-3058792.75, 0xc014, 0xbab1a300L, 0x00000000L), HEXCONSTE(-3058793.0, 0xc014, 0xbab1a400L, 0x00000000L), NO_INEXACT_EXCEPTION },
#ifndef TEST_FLOAT
	{ __LINE__, HEXCONSTE(70368744177664.75, 0x402d, 0x80000000L, 0x00018000L), HEXCONSTE(70368744177665.0, 0x402d, 0x80000000L, 0x00020000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(140737488355328.75, 0x402e, 0x80000000L, 0x0000c000L), HEXCONSTE(140737488355329.0, 0x402e, 0x80000000L, 0x00010000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(281474976710656.75, 0x402f, 0x80000000L, 0x00006000L), HEXCONSTE(281474976710657.0, 0x402f, 0x80000000L, 0x00008000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(562949953421312.75, 0x4030, 0x80000000L, 0x00003000L), HEXCONSTE(562949953421313.0, 0x4030, 0x80000000L, 0x00004000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(1125899906842624.75, 0x4031, 0x80000000L, 0x00001800L), HEXCONSTE(1125899906842625.0, 0x4031, 0x80000000L, 0x00002000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-70368744177664.75, 0xc02d, 0x80000000L, 0x00018000L), HEXCONSTE(-70368744177665.0, 0xc02d, 0x80000000L, 0x00020000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-140737488355328.75, 0xc02e, 0x80000000L, 0x0000c000L), HEXCONSTE(-140737488355329.0, 0xc02e, 0x80000000L, 0x00010000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-281474976710656.75, 0xc02f, 0x80000000L, 0x00006000L), HEXCONSTE(-281474976710657.0, 0xc02f, 0x80000000L, 0x00008000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-562949953421312.75, 0xc030, 0x80000000L, 0x00003000L), HEXCONSTE(-562949953421313.0, 0xc030, 0x80000000L, 0x00004000L), NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(-1125899906842624.75, 0xc031, 0x80000000L, 0x00001800L), HEXCONSTE(-1125899906842625.0, 0xc031, 0x80000000L, 0x00002000L), NO_INEXACT_EXCEPTION },
#endif
};


int main(int argc, char **argv)
{
	int status;
	
	status = 0;
	
	test_init(argc, argv);
	
	status |= test_table_f_f(nearbyint_data, ARRAY_SIZE(nearbyint_data), __FILE__);

	return status ? EXIT_FAILURE : EXIT_SUCCESS;
}

#else

int main(void)
{
	return 77;
}

#endif
