#include "testconfig.h"

#if defined(HAVE_ISLESS) || defined(HAVE___ISLESS)
#define TEST_FUNC_FF_I __MATH_PRECNAME(wrap_isless)
static int TEST_FUNC_FF_I(REAL x, REAL y)
{
#ifdef HAVE___ISLESS
	return __isless(x, y);
#else
	return isless(x, y);
#endif
}
#include "testdriver.h"



static test_ff_i_data const isless_data[] = {
	{ __LINE__, ZERO_M, ZERO_M, 0, NO_INEXACT_EXCEPTION },
	{ __LINE__, ZERO_M, ZERO_P, 0, NO_INEXACT_EXCEPTION },
	{ __LINE__, ZERO_M, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), 1, NO_INEXACT_EXCEPTION },
	{ __LINE__, ZERO_M, QNAN_P, 0, NO_INEXACT_EXCEPTION },
	{ __LINE__, ZERO_M, QNAN_M, 0, NO_INEXACT_EXCEPTION },
	{ __LINE__, ZERO_P, ZERO_M, 0, NO_INEXACT_EXCEPTION },
	{ __LINE__, ZERO_P, ZERO_P, 0, NO_INEXACT_EXCEPTION },
	{ __LINE__, ZERO_P, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), 1, NO_INEXACT_EXCEPTION },
	{ __LINE__, ZERO_P, QNAN_P, 0, NO_INEXACT_EXCEPTION },
	{ __LINE__, ZERO_P, QNAN_M, 0, NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), ZERO_M, 0, NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), ZERO_P, 0, NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), 0, NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), QNAN_P, 0, NO_INEXACT_EXCEPTION },
	{ __LINE__, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), QNAN_M, 0, NO_INEXACT_EXCEPTION },
	{ __LINE__, QNAN_P, ZERO_M, 0, NO_INEXACT_EXCEPTION },
	{ __LINE__, QNAN_P, ZERO_P, 0, NO_INEXACT_EXCEPTION },
	{ __LINE__, QNAN_P, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), 0, NO_INEXACT_EXCEPTION },
	{ __LINE__, QNAN_P, QNAN_P, 0, NO_INEXACT_EXCEPTION },
	{ __LINE__, QNAN_M, ZERO_M, 0, NO_INEXACT_EXCEPTION },
	{ __LINE__, QNAN_M, ZERO_P, 0, NO_INEXACT_EXCEPTION },
	{ __LINE__, QNAN_M, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), 0, NO_INEXACT_EXCEPTION },
	{ __LINE__, QNAN_M, QNAN_P, 0, NO_INEXACT_EXCEPTION },
	{ __LINE__, QNAN_M, QNAN_M, 0, NO_INEXACT_EXCEPTION },
};

int main(int argc, char **argv)
{
	int status;
	
	status = 0;
	
	test_init(argc, argv);
	
	status |= test_table_ff_i(isless_data, ARRAY_SIZE(isless_data), __FILE__);
	(void)check_fp;
		
	return status ? EXIT_FAILURE : EXIT_SUCCESS;
}

#else

int main(void)
{
	return 77;
}

#endif
