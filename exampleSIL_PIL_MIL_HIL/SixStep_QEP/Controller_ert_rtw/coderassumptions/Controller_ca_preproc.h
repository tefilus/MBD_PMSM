/*
 * File: Controller_ca_preproc.h
 *
 * Abstract: Preprocessor checks for hardware implementation settings.
 *
 * Hardware Implementation Specification:
 *
 * HWDeviceType: Texas Instruments->C2000
 * PortableWordSizes: on
 * PreprocMaxBitsUint: 32
 * PreprocMaxBitsSint: 32
 * BitPerChar: 16
 * BitPerShort: 16
 * BitPerInt: 16
 * BitPerLong: 32
 * LongLongMode: on
 * BitPerLongLong: 64
 */

#ifndef CONTROLLER_CA_PREPROC_H
#define CONTROLLER_CA_PREPROC_H
#ifndef PORTABLE_WORDSIZES

/* make sure limits are available */
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if (UCHAR_MAX != (0xFFFFU)) || (SCHAR_MAX != (0x7FFF))
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Hardware Implementation data type sizes to \
match your compiler (defined in limits.h).
#endif

#if (USHRT_MAX != (0xFFFFU)) || (SHRT_MAX != (0x7FFF))
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Hardware Implementation data type sizes to \
match your compiler (defined in limits.h).
#endif

#if (UINT_MAX != (0xFFFFU)) || (INT_MAX != (0x7FFF))
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Hardware Implementation data type sizes to \
match your compiler (defined in limits.h).
#endif

#if (ULONG_MAX != (0xFFFFFFFFUL)) || (LONG_MAX != (0x7FFFFFFFL))
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Hardware Implementation data type sizes to \
match your compiler (defined in limits.h).
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */
#endif                                 /* !PORTABLE_WORDSIZES */
#endif                                 /* CONTROLLER_CA_PREPROC_H */
