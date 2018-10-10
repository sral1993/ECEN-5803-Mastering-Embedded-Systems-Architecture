/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Flow_Meter.c
 *
 * Code generated for Simulink model 'Flow_Meter'.
 *
 * Model version                  : 1.35
 * Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
 * C/C++ source code generated on : Wed Oct 11 21:56:08 2017
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. RAM efficiency
 *    2. Execution efficiency
 * Validation result: Not run
 */

#include "Flow_Meter.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

/* Block signals and states (auto storage) */
DW rtDW;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *const rtM = &rtM_;

/* Model step function */
void Flow_Meter_step(void)
{
  int32_T ct_zc;
  real_T FrequencyInput;

  /* Sin: '<Root>/Sine Wave  ' */
  FrequencyInput = sin(12566.370614359172 * rtM->Timing.t[0]) * 5.0;

  /* S-Function (sdspzc): '<Root>/Zero Crossing' */
  ct_zc = 0;
  if (((rtDW.ZeroCrossing_InputBuffer < 0.0) && (FrequencyInput > 0.0)) ||
      ((rtDW.ZeroCrossing_InputBuffer > 0.0) && (FrequencyInput < 0.0))) {
    ct_zc = 1;
  }

  if (FrequencyInput != 0.0) {
    rtDW.ZeroCrossing_InputBuffer = FrequencyInput;
  }

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  S-Function (sdspzc): '<Root>/Zero Crossing'
   */
  if ((uint32_T)ct_zc > 0U) {
    rtDW.count1++;
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  rtM->Timing.t[0] =
    (++rtM->Timing.clockTick0) * rtM->Timing.stepSize0;

  {
    /* Update absolute timer for sample time: [0.00016666666666666666s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 0.00016666666666666666, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    rtM->Timing.clockTick1++;
  }
}

/* Model initialize function */
void Flow_Meter_initialize(void)
{
  /* Registration code */
  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&rtM->solverInfo, &rtM->Timing.simTimeStep);
    rtsiSetTPtr(&rtM->solverInfo, &rtmGetTPtr(rtM));
    rtsiSetStepSizePtr(&rtM->solverInfo, &rtM->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&rtM->solverInfo, ((const char_T **)
      (&rtmGetErrorStatus(rtM))));
    rtsiSetRTModelPtr(&rtM->solverInfo, rtM);
  }

  rtsiSetSimTimeStep(&rtM->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&rtM->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(rtM, &rtM->Timing.tArray[0]);
  rtM->Timing.stepSize0 = 0.00016666666666666666;

  /* SystemInitialize for MATLAB Function: '<Root>/MATLAB Function' */
  rtDW.count1 = 1.0;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
