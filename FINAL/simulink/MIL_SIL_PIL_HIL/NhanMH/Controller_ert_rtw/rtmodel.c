/*
 * File: rtmodel.c
 *
 * Code generated for Simulink model 'Controller'.
 *
 * Model version                  : 1.17
 * Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
 * C/C++ source code generated on : Mon Jun 23 13:25:10 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtmodel.h"

/* Use this function only if you need to maintain compatibility with an existing static main program. */
void Controller_step(int_T tid)
{
  switch (tid) {
   case 0 :
    Controller_step0();
    break;

   case 1 :
    Controller_step1();
    break;

   case 2 :
    Controller_step2();
    break;

   case 3 :
    Controller_step3();
    break;

   case 4 :
    Controller_step4();
    break;

   default :
    /* do nothing */
    break;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
