/*
 * File: Speed_ca.c
 *
 * Abstract: Tests assumptions in the generated code.
 */

#include "Speed_ca.h"

CA_HWImpl_TestResults CA_Speed_HWRes;
CA_PWS_TestResults CA_Speed_PWSRes;
const CA_HWImpl CA_Speed_ExpHW = {

#ifdef PORTABLE_WORDSIZES

  8,                                   /* BitPerChar */
  16,                                  /* BitPerShort */
  32,                                  /* BitPerInt */
  32,                                  /* BitPerLong */
  64,                                  /* BitPerLongLong */
  32,                                  /* BitPerFloat */
  64,                                  /* BitPerDouble */
  64,                                  /* BitPerPointer */
  64,                                  /* BitPerSizeT */
  64,                                  /* BitPerPtrDiffT */
  CA_LITTLE_ENDIAN,                    /* Endianess */
  CA_ZERO,                             /* IntDivRoundTo */
  1,                                   /* ShiftRightIntArith */

#else

  16,                                  /* BitPerChar */
  16,                                  /* BitPerShort */
  16,                                  /* BitPerInt */
  32,                                  /* BitPerLong */
  64,                                  /* BitPerLongLong */
  32,                                  /* BitPerFloat */
  64,                                  /* BitPerDouble */
  32,                                  /* BitPerPointer */
  32,                                  /* BitPerSizeT */
  32,                                  /* BitPerPtrDiffT */
  CA_LITTLE_ENDIAN,                    /* Endianess */
  CA_ZERO,                             /* IntDivRoundTo */
  1,                                   /* ShiftRightIntArith */

#endif

  0,                                   /* LongLongMode */
  1,                                   /* PortableWordSizes */
  "Texas Instruments->C2000",          /* HWDeviceType */
  0,                                   /* MemoryAtStartup */
  0,                                   /* DynamicMemoryAtStartup */
  0,                                   /* DenormalFlushToZero */
  0                                    /* DenormalAsZero */
};

CA_HWImpl CA_Speed_ActHW = {
  0,                                   /* BitPerChar */
  0,                                   /* BitPerShort */
  0,                                   /* BitPerInt */
  0,                                   /* BitPerLong */
  0,                                   /* BitPerLongLong */
  0,                                   /* BitPerFloat */
  0,                                   /* BitPerDouble */
  0,                                   /* BitPerPointer */
  0,                                   /* BitPerSizeT */
  0,                                   /* BitPerPtrDiffT */
  CA_UNSPECIFIED,                      /* Endianess */
  CA_UNDEFINED,                        /* IntDivRoundTo */
  0,                                   /* ShiftRightIntArith */
  0,                                   /* LongLongMode */
  0,                                   /* PortableWordSizes */
  "",                                  /* HWDeviceType */
  0,                                   /* MemoryAtStartup */
  0,                                   /* DynamicMemoryAtStartup */
  0,                                   /* DenormalFlushToZero */
  0                                    /* DenormalAsZero */
};

void Speed_caRunTests(void)
{
  /* verify hardware implementation */
  caVerifyPortableWordSizes(&CA_Speed_ActHW, &CA_Speed_ExpHW, &CA_Speed_PWSRes);
  caVerifyHWImpl(&CA_Speed_ActHW, &CA_Speed_ExpHW, &CA_Speed_HWRes);
}
