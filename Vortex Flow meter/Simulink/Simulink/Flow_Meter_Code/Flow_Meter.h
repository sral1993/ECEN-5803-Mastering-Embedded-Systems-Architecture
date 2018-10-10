/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Flow_Meter.h
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

#ifndef RTW_HEADER_Flow_Meter_h_
#define RTW_HEADER_Flow_Meter_h_
#include <math.h>
#ifndef Flow_Meter_COMMON_INCLUDES_
# define Flow_Meter_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* Flow_Meter_COMMON_INCLUDES_ */

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM RT_MODEL;

/* Block signals and states (auto storage) for system '<Root>' */
typedef struct {
  real_T ZeroCrossing_InputBuffer;     /* '<Root>/Zero Crossing' */
  real_T count1;                       /* '<Root>/MATLAB Function' */
} DW;

/* Real-time Model Data Structure */
struct tag_RTM {
  const char_T * volatile errorStatus;
  RTWSolverInfo solverInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block signals and states (auto storage) */
extern DW rtDW;

/* Model entry point functions */
extern void Flow_Meter_initialize(void);
extern void Flow_Meter_step(void);

/* Real-time Model object */
extern RT_MODEL *const rtM;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/ ' : Unused code path elimination
 * Block '<Root>/Add' : Unused code path elimination
 * Block '<Root>/Density  ' : Unused code path elimination
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 * Block '<Root>/Divide' : Unused code path elimination
 * Block '<Root>/Divide1' : Unused code path elimination
 * Block '<Root>/Flow Product' : Unused code path elimination
 * Block '<Root>/Flow in gallons//minute ' : Unused code path elimination
 * Block '<Root>/Initial Assumed Velocity' : Unused code path elimination
 * Block '<Root>/PID in meters' : Unused code path elimination
 * Block '<Root>/PID*PID*2.45' : Unused code path elimination
 * Block '<Root>/Product' : Unused code path elimination
 * Block '<Root>/Product1' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 * Block '<Root>/Scope1' : Unused code path elimination
 * Block '<Root>/Strouhal Number' : Unused code path elimination
 * Block '<Root>/Temperature in Celsius' : Unused code path elimination
 * Block '<Root>/Temperature in Kelvin ' : Unused code path elimination
 * Block '<Root>/Velocity Conversion' : Unused code path elimination
 * Block '<Root>/Viscosity' : Unused code path elimination
 * Block '<Root>/d(bluff body width) in meters' : Unused code path elimination
 * Block '<Root>/f*d' : Unused code path elimination
 * Block '<Root>/meters to feet ' : Unused code path elimination
 * Block '<Root>/scaler 1' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Flow_Meter'
 * '<S1>'   : 'Flow_Meter/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_Flow_Meter_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
