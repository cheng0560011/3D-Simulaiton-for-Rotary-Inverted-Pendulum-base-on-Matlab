/*
 * pend_v2.h
 *
 * Code generation for model "pend_v2".
 *
 * Model version              : 1.36
 * Simulink Coder version : 8.4 (R2013a) 13-Feb-2013
 * C source code generated on : Tue Aug 23 13:45:14 2016
 *
 * Target selection: rsim.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_pend_v2_h_
#define RTW_HEADER_pend_v2_h_
#ifndef pend_v2_COMMON_INCLUDES_
# define pend_v2_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rsim.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "rt_defines.h"
#include "rt_matrixlib.h"
#include "rt_nonfinite.h"
#endif                                 /* pend_v2_COMMON_INCLUDES_ */

#include "pend_v2_types.h"
#define MODEL_NAME                     pend_v2
#define NSAMPLE_TIMES                  (2)                       /* Number of sample times */
#define NINPUTS                        (0)                       /* Number of model inputs */
#define NOUTPUTS                       (0)                       /* Number of model outputs */
#define NBLOCKIO                       (7)                       /* Number of data output port signals */
#define NUM_ZC_EVENTS                  (0)                       /* Number of zero-crossing events */
#ifndef NCSTATES
# define NCSTATES                      (4)                       /* Number of continuous states */
#elif NCSTATES != 4
# error Invalid specification of NCSTATES defined in compiler command
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        (NULL)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T EXEC_STATE_1[4];              /* '<S14>/EXEC_STATE_1' */
  real_T EXEC_OUTPUT_3[2];             /* '<S14>/EXEC_OUTPUT_3' */
  real_T Gain;                         /* '<S7>/Gain' */
  real_T EXEC_INPUT_1[4];              /* '<S13>/EXEC_INPUT_1' */
  real_T TmpSignalConversionAtEXEC_SINK_[4];
  real_T TmpSignalConversionAtEXEC_OUTPU[4];
  real_T TmpSignalConversionAtEXEC_STATE[4];
} B;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T EXEC_INPUT_1_DSTATE;          /* '<S13>/EXEC_INPUT_1' */
  real_T EXEC_STATE_1_RWORK;           /* '<S14>/EXEC_STATE_1' */
  real_T EXEC_OUTPUT_3_RWORK;          /* '<S14>/EXEC_OUTPUT_3' */
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } betadot_RWORK;                     /* '<S7>/beta dot' */

  real_T EXEC_INPUT_1_RWORK;           /* '<S13>/EXEC_INPUT_1' */
  real_T EXEC_SINK_2_RWORK;            /* '<S14>/EXEC_SINK_2' */
  void *EXEC_STATE_1_PWORK[5];         /* '<S14>/EXEC_STATE_1' */
  void *EXEC_OUTPUT_3_PWORK[5];        /* '<S14>/EXEC_OUTPUT_3' */
  struct {
    void *LoggedData;
  } beta_PWORK;                        /* '<Root>/beta' */

  struct {
    void *LoggedData;
  } alpha_PWORK;                       /* '<Root>/alpha' */

  void *EXEC_INPUT_1_PWORK[5];         /* '<S13>/EXEC_INPUT_1' */
  void *EXEC_SINK_2_PWORK[5];          /* '<S14>/EXEC_SINK_2' */
} DW;

/* Continuous states (auto storage) */
typedef struct {
  real_T EXEC_STATE_1_CSTATE[4];       /* '<S14>/EXEC_STATE_1' */
} X;

/* State derivatives (auto storage) */
typedef struct {
  real_T EXEC_STATE_1_CSTATE[4];       /* '<S14>/EXEC_STATE_1' */
} XDot;

/* State disabled  */
typedef struct {
  boolean_T EXEC_STATE_1_CSTATE[4];    /* '<S14>/EXEC_STATE_1' */
} XDis;

/* Continuous State Absolute Tolerance  */
typedef struct {
  real_T EXEC_STATE_1_CSTATE[4];       /* '<S14>/EXEC_STATE_1' */
} CStateAbsTol;

/* Parameters (auto storage) */
struct P_ {
  real_T Gain_Gain;                    /* Expression: -8.3e-5
                                        * Referenced by: '<S7>/Gain'
                                        */
};

extern P rtP;                          /* parameters */

/* External data declarations for dependent source files */
extern const real_T pend_v2_RGND;      /* real_T ground */
extern const char *RT_MEMORY_ALLOCATION_ERROR;
extern B rtB;                          /* block i/o */
extern X rtX;                          /* states (continuous) */
extern DW rtDW;                        /* states (dwork) */

/* Simulation Structure */
extern SimStruct *const rtS;

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
 * '<Root>' : 'pend_v2'
 * '<S1>'   : 'pend_v2/PS-Simulink Converter'
 * '<S2>'   : 'pend_v2/PS-Simulink Converter1'
 * '<S3>'   : 'pend_v2/RIP System'
 * '<S4>'   : 'pend_v2/Solver Configuration'
 * '<S5>'   : 'pend_v2/PS-Simulink Converter/EVAL_KEY'
 * '<S6>'   : 'pend_v2/PS-Simulink Converter1/EVAL_KEY'
 * '<S7>'   : 'pend_v2/RIP System/Pendulum'
 * '<S8>'   : 'pend_v2/RIP System/Rod'
 * '<S9>'   : 'pend_v2/RIP System/box'
 * '<S10>'  : 'pend_v2/RIP System/Pendulum/PS-Simulink Converter'
 * '<S11>'  : 'pend_v2/RIP System/Pendulum/Simulink-PS Converter'
 * '<S12>'  : 'pend_v2/RIP System/Pendulum/PS-Simulink Converter/EVAL_KEY'
 * '<S13>'  : 'pend_v2/RIP System/Pendulum/Simulink-PS Converter/EVAL_KEY'
 * '<S14>'  : 'pend_v2/Solver Configuration/EVAL_KEY'
 */

/* user code (bottom of header file) */
extern const int_T gblNumToFiles;
extern const int_T gblNumFrFiles;
extern const int_T gblNumFrWksBlocks;
extern rtInportTUtable *gblInportTUtables;
extern const char *gblInportFileName;
extern const int_T gblNumRootInportBlks;
extern const int_T gblNumModelInputs;
extern const int_T gblInportDataTypeIdx[];
extern const int_T gblInportDims[];
extern const int_T gblInportComplex[];
extern const int_T gblInportInterpoFlag[];
extern const int_T gblInportContinuous[];

#endif                                 /* RTW_HEADER_pend_v2_h_ */
