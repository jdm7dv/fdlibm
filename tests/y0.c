#include "testconfig.h"
#define TEST_FUNC_F_F __MATH_PRECNAME(y0)
#include "testdriver.h"



static test_f_f_data const y0_data[] = {
	{ __LINE__, QNAN_P, QNAN_P, 0 },
	{ __LINE__, QNAN_M, QNAN_P, 0 },
	{ __LINE__, SNAN_P, QNAN_P, 0 },
	{ __LINE__, SNAN_M, QNAN_P, 0 },
	{ __LINE__, INF_P, ZERO_P, 0 },
	{ __LINE__, INF_M, QNAN_P, 0 },
	{ __LINE__, ZERO_P, INF_M, 0 },
	{ __LINE__, ZERO_M, INF_M, 0 },
	{ __LINE__, SUBNORM_P, ZERO_P, FLAG_SUBNORM },
	{ __LINE__, SUBNORM_M, ZERO_M, FLAG_SUBNORM },
	{ __LINE__, MIN_P, ZERO_P, 0 },
	{ __LINE__, MIN_M, ZERO_M, 0 },
	{ __LINE__, MAX_P, MAX_P, 0 },
	{ __LINE__, MAX_M, INF_M, INVALID_EXCEPTION|ERRNO_EDOM },

#if 0 /* TODO: could be either inf or nan */
	{ __LINE__, HEXCONSTE(-1.0, 0xbfff, 0x80000000L, 0x00000000L), INF_M, INVALID_EXCEPTION|ERRNO_EDOM },
#endif
	{ __LINE__, HEXCONSTE(0.125L, 0x3ffc, 0x80000000L, 0x00000000L), HEXCONSTE(-1.38968062514384052915582277745018693L, 0xbfff, 0xb1e10e02L, 0x70563121L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(0.75L, 0x3ffe, 0xc0000000L, 0x00000000L), HEXCONSTE(-0.137172769385772397522814379396581855L, 0xbffc, 0x8c7704b9L, 0xa791e343L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.0, 0x3fff, 0x80000000L, 0x00000000L), HEXCONSTE(0.0882569642156769579829267660235151628L, 0x3ffb, 0xb4c01137L, 0x9ac6f94fL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(1.5, 0x3fff, 0xc0000000L, 0x00000000L), HEXCONSTE(0.382448923797758843955068554978089862L, 0x3ffd, 0xc3d05868L, 0x341b3e63L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(2.0, 0x4000, 0x80000000L, 0x00000000L), HEXCONSTE(0.510375672649745119596606592727157873L, 0x3ffe, 0x82a7fae6L, 0xb46465e1L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(8.0, 0x4002, 0x80000000L, 0x00000000L), HEXCONSTE(0.223521489387566220527323400498620359L, 0x3ffc, 0xe4e2d13bL, 0x7dc16072L), FLAG_INEXACT4 },
	{ __LINE__, HEXCONSTE(10.0, 0x4002, 0xa0000000L, 0x00000000L), HEXCONSTE(0.0556711672835993914244598774101900481L, 0x3ffa, 0xe407732dL, 0x02e2c469L), FLAG_INEXACT4 },

	{ __LINE__, HEXCONSTE(2.36072207283297986806e+22, 0x4049, 0x9ff80000L, 0x00000000L), HEXCONSTE(1.818984347516051243459467456433028748678e-12L, 0x3fd7, 0xffffd15dL, 0xc983090bL), FLAG_INEXACT|FLAG_FAIL_ARANYM },

#ifndef TEST_FLOAT
	{ __LINE__, HEXCONSTE(1.46344799023407084313e+253, 0x4347, 0xff800000L, 0x00001000L), HEXCONSTE(1.846591691699331493194965158699937660696e-127L, 0x3e59, 0xffffdb5eL, 0x5de330edL), FLAG_INEXACT|FLAG_FAIL_ARANYM },
	{ __LINE__, HEXCONSTE(8.98846567431157953865e+307, 0x43fe, 0x80000000L, 0x00000000L), HEXCONSTE(8.2687542933709649327986678723012001545638e-155L, 0x3dff, 0x8de88730L, 0x43bf1671L), FLAG_INEXACT|FLAG_FAIL_ARANYM },
#endif

#if defined TEST_LDOUBLE && LDBL_MAX_EXP >= 16384
	{ __LINE__, HEXCONSTE(2.97432873839307941271e+4931, 0x7ffd, 0x80000000L, 0x00000000L), HEXCONSTE(8.0839224448726336195866026476176740513439e-2467L, 0x1ffe, 0xe1ba855bL, 0xa7e7ba4aL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(5.94865747678615882543e+4931, 0x7ffe, 0x80000000L, 0x00000000L), HEXCONSTE(-3.8895531955766020648617743624167352352217e-2467L, 0x9ffd, 0xd937989aL, 0x926f460eL), OVERFLOW_EXCEPTION_OK },
#endif

	{ __LINE__, HEXCONSTE(9.76562500000000000000e-04, 0x3ff5, 0x80000000L, 0x00000000L), HEXCONSTE(-4.4865150767109739412411806297168793661098L, 0xc001, 0x8f918810L, 0xef818d09L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(9.53674316406250000000e-07, 0x3feb, 0x80000000L, 0x00000000L), HEXCONSTE(-8.8992283012125827603076426611387876938160L, 0xc002, 0x8e633d37L, 0x1587e7dbL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(9.31322574615478515625e-10, 0x3fe1, 0x80000000L, 0x00000000L), HEXCONSTE(-1.3311940304267782826037118027401817264906e+1L, 0xc002, 0xd4fdb51dL, 0xd22691e1L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(9.09494701772928237915e-13, 0x3fd7, 0x80000000L, 0x00000000L), HEXCONSTE(-1.7724652307320814696990854700366226762563e+1L, 0xc003, 0x8dcc1682L, 0x474f8b9cL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(8.88178419700125232339e-16, 0x3fcd, 0x80000000L, 0x00000000L), HEXCONSTE(-2.2137364310373846564919987139743760738155e+1L, 0xc003, 0xb1195275L, 0xa58bce46L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(8.67361737988403547206e-19, 0x3fc3, 0x80000000L, 0x00000000L), HEXCONSTE(-2.6550076313426878432849115782108205929120e+1L, 0xc003, 0xd4668e69L, 0x03c810f0L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(8.47032947254300339068e-22, 0x3fb9, 0x80000000L, 0x00000000L), HEXCONSTE(-3.0962788316479910300778244424468159753887e+1L, 0xc003, 0xf7b3ca5cL, 0x6204539aL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(8.27180612553027674871e-25, 0x3faf, 0x80000000L, 0x00000000L), HEXCONSTE(-3.5375500319532942168707373066828113573541e+1L, 0xc004, 0x8d808327L, 0xe0204b22L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(8.07793566946316088742e-28, 0x3fa5, 0x80000000L, 0x00000000L), HEXCONSTE(-3.9788212322585974036636501709188067393195e+1L, 0xc004, 0x9f272121L, 0x8f3e6c77L), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(7.88860905221011805412e-31, 0x3f9b, 0x80000000L, 0x00000000L), HEXCONSTE(-4.420092432563900590456563035154802121284e+1L, 0xc004, 0xb0cdbf1bL, 0x3e5c8dccL), FLAG_INEXACT },
	{ __LINE__, HEXCONSTE(7.70371977754894341222e-34, 0x3f91, 0x80000000L, 0x00000000L), HEXCONSTE(-4.861363632869203777249475899390797503250e+1L, 0xc004, 0xc2745d14L, 0xed7aaf21L), FLAG_INEXACT },
};


int main(int argc, char **argv)
{
	int status;
	
	status = 0;
	
	test_init(argc, argv);
	
	status |= test_table_f_f(y0_data, ARRAY_SIZE(y0_data), __FILE__);
	
	return status ? EXIT_FAILURE : EXIT_SUCCESS;
}
