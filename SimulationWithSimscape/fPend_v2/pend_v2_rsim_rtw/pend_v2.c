/*
 * pend_v2.c
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
#include <math.h>
#include "pend_v2.h"
#include "pend_v2_private.h"
#include "pend_v2_dt.h"

/* user code (top of parameter file) */
const int_T gblNumToFiles = 0;
const int_T gblNumFrFiles = 0;
const int_T gblNumFrWksBlocks = 0;
const char *gblSlvrJacPatternFileName = "pend_v2_rsim_rtw\\pend_v2_Jpattern.mat";

/* Root inports information  */
const int_T gblNumRootInportBlks = 0;
const int_T gblNumModelInputs = 0;
extern rtInportTUtable *gblInportTUtables;
extern const char *gblInportFileName;
const int_T gblInportDataTypeIdx[] = { -1 };

const int_T gblInportDims[] = { -1 } ;

const int_T gblInportComplex[] = { -1 };

const int_T gblInportInterpoFlag[] = { -1 };

const int_T gblInportContinuous[] = { -1 };

#include "simstruc.h"
#include "fixedpoint.h"
#include "pend_v2_9701bd64_1.h"

const real_T pend_v2_RGND = 0.0;       /* real_T ground */

/* Block signals (auto storage) */
B rtB;

/* Continuous states */
X rtX;

/* Block states (auto storage) */
DW rtDW;

/* Parent Simstruct */
static SimStruct model_S;
SimStruct *const rtS = &model_S;

/* Simscape gateway function (for <S14>/EXEC_STATE_1) */
void pend_v2_9701bd64_1_dae_gateway(void)
{
  NeModelParameters modelparams = { (NeSolverType) 1, 0.001, 1, 0.001, 0, 0, 0,
    0, (SscLoggingSetting) 0, };

  NeSolverParameters solverparams = { 0, 0, 1, 0, 0, 0, 0, 1e-09, 0,
    (NeAdvancerChoice) 0, 0.001, 0, 3, 2, (NeLinearAlgebraChoice) 0, 1024, };

  const NeInputParameters * inputparameters;
  const NeOutputParameters * outputparameters;
  const NeLinearAlgebra * linear_algebra_ptr;
  NeDae *dae[1];
  size_t numInputs = 0;
  size_t numOutputs = 0;
  linear_algebra_ptr =
    (solverparams.mLinearAlgebra == NE_FULL_LA) ?
    (get_rtw_linear_algebra()) : (neu_get_csparse_linear_algebra());

  {
    static const NeInputParameters inputparameterinit[] = { { 0, 0, 0, 0.001, 1,
        0, "pend_v2/RIP System/Pendulum/Simulink-PS\nConverter", }, };

    inputparameters = inputparameterinit;
    numInputs = sizeof(inputparameterinit)/sizeof(inputparameterinit[0]);
  }

  {
    static const NeOutputParameters outputparameterinit[] = { { 0, 0,
        "pend_v2/Solver\nConfiguration", }, };

    outputparameters = outputparameterinit;
    numOutputs = sizeof(outputparameterinit)/sizeof(outputparameterinit[0]);
  }

  pend_v2_9701bd64_1_dae(
    &dae[0],
    &modelparams,
    &solverparams,
    linear_algebra_ptr);
  nesl_register_simulator_group("pend_v2/Solver Configuration",
    1,
    dae,
    solverparams,
    modelparams,
    numInputs,
    inputparameters,
    numOutputs,
    outputparameters);
}

/* Initial conditions for root system: '<Root>' */
void MdlInitialize(void)
{
  /* SimscapeExecutionBlock Block: <S14>/EXEC_STATE_1 */
  {
  }

  /* SimscapeExecutionBlock Block: <S14>/EXEC_OUTPUT_3 */
  {
  }

  /* InitializeConditions for Derivative: '<S7>/beta dot' */
  rtDW.betadot_RWORK.TimeStampA = rtInf;
  rtDW.betadot_RWORK.TimeStampB = rtInf;

  /* SimscapeExecutionBlock Block: <S13>/EXEC_INPUT_1 */
  {
  }

  /* SimscapeExecutionBlock Block: <S14>/EXEC_SINK_2 */
  {
  }
}

/* Start for root system: '<Root>' */
void MdlStart(void)
{
  /* SimscapeExecutionBlock Block: <S14>/EXEC_STATE_1 */
  {
    const NeslSimulatorGroupRegistry * registry;
    const char * key;
    NeslSimulatorCategory category;
    size_t index;
    NeslSimulator* simulator;
    NeslSimulationData* sim_data;
    NeuDiagnosticManager* diag_mgr;
    NeModelParameters modelparams = { (NeSolverType) 1, 0.001, 1, 0.001, 0, 0, 0,
      0, (SscLoggingSetting) 0, };

    registry = nesl_get_registry();
    key = "pend_v2/Solver Configuration";
    category = (NeslSimulatorCategory)0;
    index = (size_t) 0;
    simulator = (NeslSimulator *) registry->mLeaseSimulator(registry, key,
      category, index);
    if (simulator == NULL) {
      pend_v2_9701bd64_1_dae_gateway();
      simulator = (NeslSimulator *) registry->mLeaseSimulator(registry, key,
        category, index);
    }

    rtDW.EXEC_STATE_1_PWORK[0] = simulator;
    sim_data = nesl_create_simulation_data(
      1-1, 2);
    rtDW.EXEC_STATE_1_PWORK[1] = sim_data;
    diag_mgr = neu_create_diagnostic_manager(ne_default_allocator());
    rtDW.EXEC_STATE_1_PWORK[3] = diag_mgr;

    {
      NeModelParameters mp;
      NeBoolVector fimts;
      const NeuDiagnosticTree *tree = diag_mgr->mGetInitialTree(diag_mgr);
      mp = modelparams;
      mp.mSolverTolerance = 0.001;
      mp.mFixedStepSize = 0.0;
      mp.mVariableStepSolver = true;
      fimts.mN = 2;

      {
        static boolean_T fimts_buffer[2] = {
          0,
          0,
        };

        fimts.mX = fimts_buffer;
      }

      if ((*simulator).mInitialize(simulator, mp, &fimts, diag_mgr) !=
          NESL_SIM_OK) {
        static char_T errorMsg[1024];
        NeuDiagnosticTreePrinter *printer = neu_create_diagnostic_tree_printer
          (ne_default_allocator());
        const char *msg = printer->mPrint(printer, tree);
        strncpy( errorMsg, msg, sizeof(errorMsg) - 1 );
        printer->mDestroy(printer);
        ssSetErrorStatus(rtS, errorMsg);
        return;
      }
    }

    sim_data = (NeslSimulationData *) rtDW.EXEC_STATE_1_PWORK[1];
    sim_data->mData->mTime.mX[0] = ssGetT(rtS);
    sim_data->mData->mContStates.mX = &rtX.EXEC_STATE_1_CSTATE[0];
    sim_data->mData->mContStates.mN = 4;
    sim_data->mData->mModeVector.mX = NULL;
    sim_data->mData->mModeVector.mN = 0;
    sim_data->mData->mDiscStates.mX = NULL;
    sim_data->mData->mDiscStates.mN = 0;

    {
      sim_data->mData->mInputPorts[0] = (const real_T *)
        rtB.TmpSignalConversionAtEXEC_STATE;
      sim_data->mData->mInputPorts[1] = (const real_T *) rtB.EXEC_INPUT_1;
    }

    sim_data->mData->mNumInputPorts = 2;
    sim_data->mData->mFoundZcEvents = ssIsMajorTimeStep(rtS) &&
      ssGetRTWSolverInfo(rtS)->foundContZcEvents;
    sim_data->mData->mIsMajorTimeStep = ssIsMajorTimeStep(rtS);
    sim_data->mData->mIsSolverAssertCheck = (ssGetMdlInfoPtr(rtS)
      ->mdlFlags.solverAssertCheck == 1U);
    sim_data->mData->mIsSolverCheckingCIC = ssIsSolverCheckingCIC(rtS);
    sim_data->mData->mIsComputingJacobian = ssIsSolverComputingJacobian(rtS);
    sim_data->mData->mIsSolverRequestingReset = ssIsSolverRequestingReset(rtS);

    {
      NeuDiagnosticManager *mgr = (NeuDiagnosticManager *)
        rtDW.EXEC_STATE_1_PWORK[3];
      const NeuDiagnosticTree *tree = mgr->mGetInitialTree(mgr);
      if (ne_simulator_method(simulator, NESL_SIM_START, sim_data, mgr) !=
          NESL_SIM_OK) {
        static char_T errorMsg[1024];
        NeuDiagnosticTreePrinter *printer = neu_create_diagnostic_tree_printer
          (ne_default_allocator());
        const char *msg = printer->mPrint(printer, tree);
        strncpy( errorMsg, msg, sizeof(errorMsg) - 1 );
        printer->mDestroy(printer);
        ssSetErrorStatus(rtS, errorMsg);
        return;
      }
    }
  }

  /* SimscapeExecutionBlock Block: <S14>/EXEC_OUTPUT_3 */
  {
    const NeslSimulatorGroupRegistry * registry;
    const char * key;
    NeslSimulatorCategory category;
    size_t index;
    NeslSimulator* simulator;
    NeslSimulationData* sim_data;
    NeuDiagnosticManager* diag_mgr;
    NeModelParameters modelparams = { (NeSolverType) 1, 0.001, 1, 0.001, 0, 0, 0,
      0, (SscLoggingSetting) 0, };

    registry = nesl_get_registry();
    key = "pend_v2/Solver Configuration";
    category = (NeslSimulatorCategory)3;
    index = (size_t) 0;
    simulator = (NeslSimulator *) registry->mLeaseSimulator(registry, key,
      category, index);
    if (simulator == NULL) {
      pend_v2_9701bd64_1_dae_gateway();
      simulator = (NeslSimulator *) registry->mLeaseSimulator(registry, key,
        category, index);
    }

    rtDW.EXEC_OUTPUT_3_PWORK[0] = simulator;
    sim_data = nesl_create_simulation_data(
      1-1, 3);
    rtDW.EXEC_OUTPUT_3_PWORK[1] = sim_data;
    diag_mgr = neu_create_diagnostic_manager(ne_default_allocator());
    rtDW.EXEC_OUTPUT_3_PWORK[3] = diag_mgr;

    {
      NeModelParameters mp;
      NeBoolVector fimts;
      const NeuDiagnosticTree *tree = diag_mgr->mGetInitialTree(diag_mgr);
      mp = modelparams;
      mp.mSolverTolerance = 1e-3;
      mp.mFixedStepSize = 0.0;
      mp.mVariableStepSolver = true;
      fimts.mN = 3;

      {
        static boolean_T fimts_buffer[3] = {
          0,
          0,
          0,
        };

        fimts.mX = fimts_buffer;
      }

      if ((*simulator).mInitialize(simulator, mp, &fimts, diag_mgr) !=
          NESL_SIM_OK) {
        static char_T errorMsg[1024];
        NeuDiagnosticTreePrinter *printer = neu_create_diagnostic_tree_printer
          (ne_default_allocator());
        const char *msg = printer->mPrint(printer, tree);
        strncpy( errorMsg, msg, sizeof(errorMsg) - 1 );
        printer->mDestroy(printer);
        ssSetErrorStatus(rtS, errorMsg);
        return;
      }
    }

    sim_data = (NeslSimulationData *) rtDW.EXEC_OUTPUT_3_PWORK[1];
    sim_data->mData->mTime.mX[0] = ssGetT(rtS);
    sim_data->mData->mContStates.mX = NULL;
    sim_data->mData->mContStates.mN = 0;
    sim_data->mData->mModeVector.mX = NULL;
    sim_data->mData->mModeVector.mN = 0;
    sim_data->mData->mDiscStates.mX = NULL;
    sim_data->mData->mDiscStates.mN = 0;

    {
      sim_data->mData->mInputPorts[0] = (const real_T *)
        rtB.TmpSignalConversionAtEXEC_OUTPU;
      sim_data->mData->mInputPorts[1] = (const real_T *) rtB.EXEC_INPUT_1;
      sim_data->mData->mInputPorts[2] = (const real_T *) rtB.EXEC_STATE_1;
    }

    sim_data->mData->mNumInputPorts = 3;
    sim_data->mData->mFoundZcEvents = ssIsMajorTimeStep(rtS) &&
      ssGetRTWSolverInfo(rtS)->foundContZcEvents;
    sim_data->mData->mIsMajorTimeStep = ssIsMajorTimeStep(rtS);
    sim_data->mData->mIsSolverAssertCheck = (ssGetMdlInfoPtr(rtS)
      ->mdlFlags.solverAssertCheck == 1U);
    sim_data->mData->mIsSolverCheckingCIC = ssIsSolverCheckingCIC(rtS);
    sim_data->mData->mIsComputingJacobian = false;
    sim_data->mData->mIsSolverRequestingReset = ssIsSolverRequestingReset(rtS);

    {
      NeuDiagnosticManager *mgr = (NeuDiagnosticManager *)
        rtDW.EXEC_OUTPUT_3_PWORK[3];
      const NeuDiagnosticTree *tree = mgr->mGetInitialTree(mgr);
      if (ne_simulator_method(simulator, NESL_SIM_START, sim_data, mgr) !=
          NESL_SIM_OK) {
        static char_T errorMsg[1024];
        NeuDiagnosticTreePrinter *printer = neu_create_diagnostic_tree_printer
          (ne_default_allocator());
        const char *msg = printer->mPrint(printer, tree);
        strncpy( errorMsg, msg, sizeof(errorMsg) - 1 );
        printer->mDestroy(printer);
        ssSetErrorStatus(rtS, errorMsg);
        return;
      }
    }
  }

  /* SimscapeExecutionBlock Block: <S13>/EXEC_INPUT_1 */
  {
    const NeslSimulatorGroupRegistry * registry;
    const char * key;
    NeslSimulatorCategory category;
    size_t index;
    NeslSimulator* simulator;
    NeslSimulationData* sim_data;
    NeuDiagnosticManager* diag_mgr;
    NeModelParameters modelparams = { (NeSolverType) 1, 0.001, 1, 0.001, 0, 0, 0,
      0, (SscLoggingSetting) 0, };

    registry = nesl_get_registry();
    key = "pend_v2/Solver Configuration";
    category = (NeslSimulatorCategory)2;
    index = (size_t) 0;
    simulator = (NeslSimulator *) registry->mLeaseSimulator(registry, key,
      category, index);
    if (simulator == NULL) {
      pend_v2_9701bd64_1_dae_gateway();
      simulator = (NeslSimulator *) registry->mLeaseSimulator(registry, key,
        category, index);
    }

    rtDW.EXEC_INPUT_1_PWORK[0] = simulator;
    sim_data = nesl_create_simulation_data(
      2-1, 3);
    rtDW.EXEC_INPUT_1_PWORK[1] = sim_data;
    diag_mgr = neu_create_diagnostic_manager(ne_default_allocator());
    rtDW.EXEC_INPUT_1_PWORK[3] = diag_mgr;

    {
      NeModelParameters mp;
      NeBoolVector fimts;
      const NeuDiagnosticTree *tree = diag_mgr->mGetInitialTree(diag_mgr);
      mp = modelparams;
      mp.mSolverTolerance = 1e-3;
      mp.mFixedStepSize = 0.0;
      mp.mVariableStepSolver = true;
      fimts.mN = 3;

      {
        static boolean_T fimts_buffer[3] = {
          0,
          1,
          1,
        };

        fimts.mX = fimts_buffer;
      }

      if ((*simulator).mInitialize(simulator, mp, &fimts, diag_mgr) !=
          NESL_SIM_OK) {
        static char_T errorMsg[1024];
        NeuDiagnosticTreePrinter *printer = neu_create_diagnostic_tree_printer
          (ne_default_allocator());
        const char *msg = printer->mPrint(printer, tree);
        strncpy( errorMsg, msg, sizeof(errorMsg) - 1 );
        printer->mDestroy(printer);
        ssSetErrorStatus(rtS, errorMsg);
        return;
      }
    }

    sim_data = (NeslSimulationData *) rtDW.EXEC_INPUT_1_PWORK[1];
    sim_data->mData->mTime.mX[0] = ssGetT(rtS);
    sim_data->mData->mContStates.mX = NULL;
    sim_data->mData->mContStates.mN = 0;
    sim_data->mData->mModeVector.mX = NULL;
    sim_data->mData->mModeVector.mN = 0;
    sim_data->mData->mDiscStates.mX = &rtDW.EXEC_INPUT_1_DSTATE;
    sim_data->mData->mDiscStates.mN = 1;

    {
      sim_data->mData->mInputPorts[0] = (const real_T *) &rtB.Gain;
      sim_data->mData->mInputPorts[1] = (const real_T *) (real_T*)&pend_v2_RGND;
      sim_data->mData->mInputPorts[2] = (const real_T *) (real_T*)&pend_v2_RGND;
    }

    sim_data->mData->mNumInputPorts = 3;
    sim_data->mData->mFoundZcEvents = ssIsMajorTimeStep(rtS) &&
      ssGetRTWSolverInfo(rtS)->foundContZcEvents;
    sim_data->mData->mIsMajorTimeStep = ssIsMajorTimeStep(rtS);
    sim_data->mData->mIsSolverAssertCheck = (ssGetMdlInfoPtr(rtS)
      ->mdlFlags.solverAssertCheck == 1U);
    sim_data->mData->mIsSolverCheckingCIC = ssIsSolverCheckingCIC(rtS);
    sim_data->mData->mIsComputingJacobian = false;
    sim_data->mData->mIsSolverRequestingReset = ssIsSolverRequestingReset(rtS);

    {
      NeuDiagnosticManager *mgr = (NeuDiagnosticManager *)
        rtDW.EXEC_INPUT_1_PWORK[3];
      const NeuDiagnosticTree *tree = mgr->mGetInitialTree(mgr);
      if (ne_simulator_method(simulator, NESL_SIM_START, sim_data, mgr) !=
          NESL_SIM_OK) {
        static char_T errorMsg[1024];
        NeuDiagnosticTreePrinter *printer = neu_create_diagnostic_tree_printer
          (ne_default_allocator());
        const char *msg = printer->mPrint(printer, tree);
        strncpy( errorMsg, msg, sizeof(errorMsg) - 1 );
        printer->mDestroy(printer);
        ssSetErrorStatus(rtS, errorMsg);
        return;
      }
    }
  }

  /* SimscapeExecutionBlock Block: <S14>/EXEC_SINK_2 */
  {
    const NeslSimulatorGroupRegistry * registry;
    const char * key;
    NeslSimulatorCategory category;
    size_t index;
    NeslSimulator* simulator;
    NeslSimulationData* sim_data;
    NeuDiagnosticManager* diag_mgr;
    NeModelParameters modelparams = { (NeSolverType) 1, 0.001, 1, 0.001, 0, 0, 0,
      0, (SscLoggingSetting) 0, };

    registry = nesl_get_registry();
    key = "pend_v2/Solver Configuration";
    category = (NeslSimulatorCategory)1;
    index = (size_t) 0;
    simulator = (NeslSimulator *) registry->mLeaseSimulator(registry, key,
      category, index);
    if (simulator == NULL) {
      pend_v2_9701bd64_1_dae_gateway();
      simulator = (NeslSimulator *) registry->mLeaseSimulator(registry, key,
        category, index);
    }

    rtDW.EXEC_SINK_2_PWORK[0] = simulator;
    sim_data = nesl_create_simulation_data(
      1-1, 3);
    rtDW.EXEC_SINK_2_PWORK[1] = sim_data;
    diag_mgr = neu_create_diagnostic_manager(ne_default_allocator());
    rtDW.EXEC_SINK_2_PWORK[3] = diag_mgr;

    {
      NeModelParameters mp;
      NeBoolVector fimts;
      const NeuDiagnosticTree *tree = diag_mgr->mGetInitialTree(diag_mgr);
      mp = modelparams;
      mp.mSolverTolerance = 1e-3;
      mp.mFixedStepSize = 0.0;
      mp.mVariableStepSolver = true;
      fimts.mN = 3;

      {
        static boolean_T fimts_buffer[3] = {
          0,
          0,
          0,
        };

        fimts.mX = fimts_buffer;
      }

      if ((*simulator).mInitialize(simulator, mp, &fimts, diag_mgr) !=
          NESL_SIM_OK) {
        static char_T errorMsg[1024];
        NeuDiagnosticTreePrinter *printer = neu_create_diagnostic_tree_printer
          (ne_default_allocator());
        const char *msg = printer->mPrint(printer, tree);
        strncpy( errorMsg, msg, sizeof(errorMsg) - 1 );
        printer->mDestroy(printer);
        ssSetErrorStatus(rtS, errorMsg);
        return;
      }
    }

    sim_data = (NeslSimulationData *) rtDW.EXEC_SINK_2_PWORK[1];
    sim_data->mData->mTime.mX[0] = ssGetT(rtS);
    sim_data->mData->mContStates.mX = NULL;
    sim_data->mData->mContStates.mN = 0;
    sim_data->mData->mModeVector.mX = NULL;
    sim_data->mData->mModeVector.mN = 0;
    sim_data->mData->mDiscStates.mX = NULL;
    sim_data->mData->mDiscStates.mN = 0;

    {
      sim_data->mData->mInputPorts[0] = (const real_T *)
        rtB.TmpSignalConversionAtEXEC_SINK_;
      sim_data->mData->mInputPorts[1] = (const real_T *) rtB.EXEC_INPUT_1;
      sim_data->mData->mInputPorts[2] = (const real_T *) rtB.EXEC_STATE_1;
    }

    sim_data->mData->mNumInputPorts = 3;
    sim_data->mData->mFoundZcEvents = ssIsMajorTimeStep(rtS) &&
      ssGetRTWSolverInfo(rtS)->foundContZcEvents;
    sim_data->mData->mIsMajorTimeStep = ssIsMajorTimeStep(rtS);
    sim_data->mData->mIsSolverAssertCheck = (ssGetMdlInfoPtr(rtS)
      ->mdlFlags.solverAssertCheck == 1U);
    sim_data->mData->mIsSolverCheckingCIC = ssIsSolverCheckingCIC(rtS);
    sim_data->mData->mIsComputingJacobian = false;
    sim_data->mData->mIsSolverRequestingReset = ssIsSolverRequestingReset(rtS);

    {
      NeuDiagnosticManager *mgr = (NeuDiagnosticManager *)
        rtDW.EXEC_SINK_2_PWORK[3];
      const NeuDiagnosticTree *tree = mgr->mGetInitialTree(mgr);
      if (ne_simulator_method(simulator, NESL_SIM_START, sim_data, mgr) !=
          NESL_SIM_OK) {
        static char_T errorMsg[1024];
        NeuDiagnosticTreePrinter *printer = neu_create_diagnostic_tree_printer
          (ne_default_allocator());
        const char *msg = printer->mPrint(printer, tree);
        strncpy( errorMsg, msg, sizeof(errorMsg) - 1 );
        printer->mDestroy(printer);
        ssSetErrorStatus(rtS, errorMsg);
        return;
      }
    }
  }

  MdlInitialize();
}

/* Outputs for root system: '<Root>' */
void MdlOutputs(int_T tid)
{
  /* local block i/o variables */
  real_T rtb_betadot;

  /* SimscapeExecutionBlock Block: <S14>/EXEC_STATE_1 */
  {
    NeslSimulator* simulator;
    NeslSimulationData* sim_data;
    simulator = (NeslSimulator *) rtDW.EXEC_STATE_1_PWORK[0];
    sim_data = (NeslSimulationData *) rtDW.EXEC_STATE_1_PWORK[1];
    sim_data->mData->mTime.mX[0] = ssGetT(rtS);
    sim_data->mData->mContStates.mX = &rtX.EXEC_STATE_1_CSTATE[0];
    sim_data->mData->mContStates.mN = 4;
    sim_data->mData->mModeVector.mX = NULL;
    sim_data->mData->mModeVector.mN = 0;
    sim_data->mData->mDiscStates.mX = NULL;
    sim_data->mData->mDiscStates.mN = 0;

    {
      sim_data->mData->mInputPorts[0] = (const real_T *)
        rtB.TmpSignalConversionAtEXEC_STATE;
      sim_data->mData->mInputPorts[1] = (const real_T *) rtB.EXEC_INPUT_1;
    }

    sim_data->mData->mNumInputPorts = 2;
    sim_data->mData->mFoundZcEvents = ssIsMajorTimeStep(rtS) &&
      ssGetRTWSolverInfo(rtS)->foundContZcEvents;
    sim_data->mData->mIsMajorTimeStep = ssIsMajorTimeStep(rtS);
    sim_data->mData->mIsSolverAssertCheck = (ssGetMdlInfoPtr(rtS)
      ->mdlFlags.solverAssertCheck == 1U);
    sim_data->mData->mIsSolverCheckingCIC = ssIsSolverCheckingCIC(rtS);
    sim_data->mData->mIsComputingJacobian = ssIsSolverComputingJacobian(rtS);
    sim_data->mData->mIsSolverRequestingReset = ssIsSolverRequestingReset(rtS);
    sim_data->mData->mOutputs.mX = rtB.EXEC_STATE_1;
    sim_data->mData->mOutputs.mN = 4;
    sim_data->mData->mSampleHits.mN = 1-1;
    sim_data->mData->mIsFundamentalSampleHit = false;

    {
      NeuDiagnosticManager *mgr = (NeuDiagnosticManager *)
        rtDW.EXEC_STATE_1_PWORK[3];
      const NeuDiagnosticTree *tree = mgr->mGetInitialTree(mgr);
      if (ne_simulator_method(simulator, NESL_SIM_OUTPUTS, sim_data, mgr) !=
          NESL_SIM_OK) {
        static char_T errorMsg[1024];
        NeuDiagnosticTreePrinter *printer = neu_create_diagnostic_tree_printer
          (ne_default_allocator());
        const char *msg = printer->mPrint(printer, tree);
        strncpy( errorMsg, msg, sizeof(errorMsg) - 1 );
        printer->mDestroy(printer);
        ssSetErrorStatus(rtS, errorMsg);
        return;
      }
    }

    if (ssIsMajorTimeStep(rtS)) {
      rtDW.EXEC_STATE_1_RWORK = ssGetT(rtS);
    }
  }

  /* SimscapeExecutionBlock Block: <S14>/EXEC_OUTPUT_3 */
  {
    NeslSimulator* simulator;
    NeslSimulationData* sim_data;
    simulator = (NeslSimulator *) rtDW.EXEC_OUTPUT_3_PWORK[0];
    sim_data = (NeslSimulationData *) rtDW.EXEC_OUTPUT_3_PWORK[1];
    sim_data->mData->mTime.mX[0] = ssGetT(rtS);
    sim_data->mData->mContStates.mX = NULL;
    sim_data->mData->mContStates.mN = 0;
    sim_data->mData->mModeVector.mX = NULL;
    sim_data->mData->mModeVector.mN = 0;
    sim_data->mData->mDiscStates.mX = NULL;
    sim_data->mData->mDiscStates.mN = 0;

    {
      sim_data->mData->mInputPorts[0] = (const real_T *)
        rtB.TmpSignalConversionAtEXEC_OUTPU;
      sim_data->mData->mInputPorts[1] = (const real_T *) rtB.EXEC_INPUT_1;
      sim_data->mData->mInputPorts[2] = (const real_T *) rtB.EXEC_STATE_1;
    }

    sim_data->mData->mNumInputPorts = 3;
    sim_data->mData->mFoundZcEvents = ssIsMajorTimeStep(rtS) &&
      ssGetRTWSolverInfo(rtS)->foundContZcEvents;
    sim_data->mData->mIsMajorTimeStep = ssIsMajorTimeStep(rtS);
    sim_data->mData->mIsSolverAssertCheck = (ssGetMdlInfoPtr(rtS)
      ->mdlFlags.solverAssertCheck == 1U);
    sim_data->mData->mIsSolverCheckingCIC = ssIsSolverCheckingCIC(rtS);
    sim_data->mData->mIsComputingJacobian = false;
    sim_data->mData->mIsSolverRequestingReset = ssIsSolverRequestingReset(rtS);
    sim_data->mData->mOutputs.mX = rtB.EXEC_OUTPUT_3;
    sim_data->mData->mOutputs.mN = 2;
    sim_data->mData->mSampleHits.mN = 1-1;
    sim_data->mData->mIsFundamentalSampleHit = false;

    {
      NeuDiagnosticManager *mgr = (NeuDiagnosticManager *)
        rtDW.EXEC_OUTPUT_3_PWORK[3];
      const NeuDiagnosticTree *tree = mgr->mGetInitialTree(mgr);
      if (ne_simulator_method(simulator, NESL_SIM_OUTPUTS, sim_data, mgr) !=
          NESL_SIM_OK) {
        static char_T errorMsg[1024];
        NeuDiagnosticTreePrinter *printer = neu_create_diagnostic_tree_printer
          (ne_default_allocator());
        const char *msg = printer->mPrint(printer, tree);
        strncpy( errorMsg, msg, sizeof(errorMsg) - 1 );
        printer->mDestroy(printer);
        ssSetErrorStatus(rtS, errorMsg);
        return;
      }
    }

    if (ssIsMajorTimeStep(rtS)) {
      rtDW.EXEC_OUTPUT_3_RWORK = ssGetT(rtS);
    }
  }

  /* Derivative: '<S7>/beta dot' */
  {
    real_T t = ssGetTaskTime(rtS,0);
    real_T timeStampA = rtDW.betadot_RWORK.TimeStampA;
    real_T timeStampB = rtDW.betadot_RWORK.TimeStampB;
    real_T *lastU = &rtDW.betadot_RWORK.LastUAtTimeA;
    if (timeStampA >= t && timeStampB >= t) {
      rtb_betadot = 0.0;
    } else {
      real_T deltaT;
      real_T lastTime = timeStampA;
      if (timeStampA < timeStampB) {
        if (timeStampB < t) {
          lastTime = timeStampB;
          lastU = &rtDW.betadot_RWORK.LastUAtTimeB;
        }
      } else if (timeStampA >= t) {
        lastTime = timeStampB;
        lastU = &rtDW.betadot_RWORK.LastUAtTimeB;
      }

      deltaT = t - lastTime;
      rtb_betadot = (rtB.EXEC_OUTPUT_3[0] - *lastU++) / deltaT;
    }
  }

  /* Gain: '<S7>/Gain' */
  rtB.Gain = rtP.Gain_Gain * rtb_betadot;

  /* SimscapeExecutionBlock Block: <S13>/EXEC_INPUT_1 */
  {
    NeslSimulator* simulator;
    NeslSimulationData* sim_data;
    simulator = (NeslSimulator *) rtDW.EXEC_INPUT_1_PWORK[0];
    sim_data = (NeslSimulationData *) rtDW.EXEC_INPUT_1_PWORK[1];
    sim_data->mData->mTime.mX[0] = ssGetT(rtS);
    sim_data->mData->mContStates.mX = NULL;
    sim_data->mData->mContStates.mN = 0;
    sim_data->mData->mModeVector.mX = NULL;
    sim_data->mData->mModeVector.mN = 0;
    sim_data->mData->mDiscStates.mX = &rtDW.EXEC_INPUT_1_DSTATE;
    sim_data->mData->mDiscStates.mN = 1;

    {
      sim_data->mData->mInputPorts[0] = (const real_T *) &rtB.Gain;
      sim_data->mData->mInputPorts[1] = (const real_T *) (real_T*)&pend_v2_RGND;
      sim_data->mData->mInputPorts[2] = (const real_T *) (real_T*)&pend_v2_RGND;
    }

    sim_data->mData->mNumInputPorts = 3;
    sim_data->mData->mFoundZcEvents = ssIsMajorTimeStep(rtS) &&
      ssGetRTWSolverInfo(rtS)->foundContZcEvents;
    sim_data->mData->mIsMajorTimeStep = ssIsMajorTimeStep(rtS);
    sim_data->mData->mIsSolverAssertCheck = (ssGetMdlInfoPtr(rtS)
      ->mdlFlags.solverAssertCheck == 1U);
    sim_data->mData->mIsSolverCheckingCIC = ssIsSolverCheckingCIC(rtS);
    sim_data->mData->mIsComputingJacobian = false;
    sim_data->mData->mIsSolverRequestingReset = ssIsSolverRequestingReset(rtS);
    sim_data->mData->mOutputs.mX = rtB.EXEC_INPUT_1;
    sim_data->mData->mOutputs.mN = 4;
    sim_data->mData->mSampleHits.mN = 0;
    sim_data->mData->mSampleHits.mX = NULL;
    sim_data->mData->mIsFundamentalSampleHit = false;

    {
      NeuDiagnosticManager *mgr = (NeuDiagnosticManager *)
        rtDW.EXEC_INPUT_1_PWORK[3];
      const NeuDiagnosticTree *tree = mgr->mGetInitialTree(mgr);
      if (ne_simulator_method(simulator, NESL_SIM_OUTPUTS, sim_data, mgr) !=
          NESL_SIM_OK) {
        static char_T errorMsg[1024];
        NeuDiagnosticTreePrinter *printer = neu_create_diagnostic_tree_printer
          (ne_default_allocator());
        const char *msg = printer->mPrint(printer, tree);
        strncpy( errorMsg, msg, sizeof(errorMsg) - 1 );
        printer->mDestroy(printer);
        ssSetErrorStatus(rtS, errorMsg);
        return;
      }
    }

    if (ssIsMajorTimeStep(rtS)) {
      rtDW.EXEC_INPUT_1_RWORK = ssGetT(rtS);
    }
  }

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEXEC_SINK_2Inport1' */
  rtB.TmpSignalConversionAtEXEC_SINK_[0] = 0.0;
  rtB.TmpSignalConversionAtEXEC_SINK_[1] = 0.0;
  rtB.TmpSignalConversionAtEXEC_SINK_[2] = 0.0;
  rtB.TmpSignalConversionAtEXEC_SINK_[3] = 0.0;

  /* SimscapeExecutionBlock Block: <S14>/EXEC_SINK_2 */
  {
    NeslSimulator* simulator;
    NeslSimulationData* sim_data;
    simulator = (NeslSimulator *) rtDW.EXEC_SINK_2_PWORK[0];
    sim_data = (NeslSimulationData *) rtDW.EXEC_SINK_2_PWORK[1];
    sim_data->mData->mTime.mX[0] = ssGetT(rtS);
    sim_data->mData->mContStates.mX = NULL;
    sim_data->mData->mContStates.mN = 0;
    sim_data->mData->mModeVector.mX = NULL;
    sim_data->mData->mModeVector.mN = 0;
    sim_data->mData->mDiscStates.mX = NULL;
    sim_data->mData->mDiscStates.mN = 0;

    {
      sim_data->mData->mInputPorts[0] = (const real_T *)
        rtB.TmpSignalConversionAtEXEC_SINK_;
      sim_data->mData->mInputPorts[1] = (const real_T *) rtB.EXEC_INPUT_1;
      sim_data->mData->mInputPorts[2] = (const real_T *) rtB.EXEC_STATE_1;
    }

    sim_data->mData->mNumInputPorts = 3;
    sim_data->mData->mFoundZcEvents = ssIsMajorTimeStep(rtS) &&
      ssGetRTWSolverInfo(rtS)->foundContZcEvents;
    sim_data->mData->mIsMajorTimeStep = ssIsMajorTimeStep(rtS);
    sim_data->mData->mIsSolverAssertCheck = (ssGetMdlInfoPtr(rtS)
      ->mdlFlags.solverAssertCheck == 1U);
    sim_data->mData->mIsSolverCheckingCIC = ssIsSolverCheckingCIC(rtS);
    sim_data->mData->mIsComputingJacobian = false;
    sim_data->mData->mIsSolverRequestingReset = ssIsSolverRequestingReset(rtS);
    sim_data->mData->mOutputs.mX = NULL;
    sim_data->mData->mOutputs.mN = 0;
    sim_data->mData->mSampleHits.mN = 1-1;
    sim_data->mData->mIsFundamentalSampleHit = false;

    {
      NeuDiagnosticManager *mgr = (NeuDiagnosticManager *)
        rtDW.EXEC_SINK_2_PWORK[3];
      const NeuDiagnosticTree *tree = mgr->mGetInitialTree(mgr);
      if (ne_simulator_method(simulator, NESL_SIM_OUTPUTS, sim_data, mgr) !=
          NESL_SIM_OK) {
        static char_T errorMsg[1024];
        NeuDiagnosticTreePrinter *printer = neu_create_diagnostic_tree_printer
          (ne_default_allocator());
        const char *msg = printer->mPrint(printer, tree);
        strncpy( errorMsg, msg, sizeof(errorMsg) - 1 );
        printer->mDestroy(printer);
        ssSetErrorStatus(rtS, errorMsg);
        return;
      }
    }

    if (ssIsMajorTimeStep(rtS)) {
      rtDW.EXEC_SINK_2_RWORK = ssGetT(rtS);
    }
  }

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEXEC_OUTPUT_3Inport1' */
  rtB.TmpSignalConversionAtEXEC_OUTPU[0] = 0.0;
  rtB.TmpSignalConversionAtEXEC_OUTPU[1] = 0.0;
  rtB.TmpSignalConversionAtEXEC_OUTPU[2] = 0.0;
  rtB.TmpSignalConversionAtEXEC_OUTPU[3] = 0.0;

  /* SignalConversion: '<S14>/TmpSignal ConversionAtEXEC_STATE_1Inport1' */
  rtB.TmpSignalConversionAtEXEC_STATE[0] = 0.0;
  rtB.TmpSignalConversionAtEXEC_STATE[1] = 0.0;
  rtB.TmpSignalConversionAtEXEC_STATE[2] = 0.0;
  rtB.TmpSignalConversionAtEXEC_STATE[3] = 0.0;

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Update for root system: '<Root>' */
void MdlUpdate(int_T tid)
{
  /* Update for Derivative: '<S7>/beta dot' */
  {
    real_T timeStampA = rtDW.betadot_RWORK.TimeStampA;
    real_T timeStampB = rtDW.betadot_RWORK.TimeStampB;
    real_T* lastTime = &rtDW.betadot_RWORK.TimeStampA;
    real_T* lastU = &rtDW.betadot_RWORK.LastUAtTimeA;
    if (timeStampA != rtInf) {
      if (timeStampB == rtInf) {
        lastTime = &rtDW.betadot_RWORK.TimeStampB;
        lastU = &rtDW.betadot_RWORK.LastUAtTimeB;
      } else if (timeStampA >= timeStampB) {
        lastTime = &rtDW.betadot_RWORK.TimeStampB;
        lastU = &rtDW.betadot_RWORK.LastUAtTimeB;
      }
    }

    *lastTime = ssGetTaskTime(rtS,0);
    *lastU++ = rtB.EXEC_OUTPUT_3[0];
  }

  /* tid is required for a uniform function interface.
   * Argument tid is not used in the function. */
  UNUSED_PARAMETER(tid);
}

/* Derivatives for root system: '<Root>' */
void MdlDerivatives(void)
{
  /* SimscapeExecutionBlock Block: <S14>/EXEC_STATE_1 */
  {
    NeslSimulator* simulator;
    NeslSimulationData* sim_data;
    simulator = (NeslSimulator *) rtDW.EXEC_STATE_1_PWORK[0];
    sim_data = (NeslSimulationData *) rtDW.EXEC_STATE_1_PWORK[1];
    sim_data->mData->mTime.mX[0] = ssGetT(rtS);
    sim_data->mData->mContStates.mX = &rtX.EXEC_STATE_1_CSTATE[0];
    sim_data->mData->mContStates.mN = 4;
    sim_data->mData->mModeVector.mX = NULL;
    sim_data->mData->mModeVector.mN = 0;
    sim_data->mData->mDiscStates.mX = NULL;
    sim_data->mData->mDiscStates.mN = 0;

    {
      sim_data->mData->mInputPorts[0] = (const real_T *)
        rtB.TmpSignalConversionAtEXEC_STATE;
      sim_data->mData->mInputPorts[1] = (const real_T *) rtB.EXEC_INPUT_1;
    }

    sim_data->mData->mNumInputPorts = 2;
    sim_data->mData->mFoundZcEvents = ssIsMajorTimeStep(rtS) &&
      ssGetRTWSolverInfo(rtS)->foundContZcEvents;
    sim_data->mData->mIsMajorTimeStep = ssIsMajorTimeStep(rtS);
    sim_data->mData->mIsSolverAssertCheck = (ssGetMdlInfoPtr(rtS)
      ->mdlFlags.solverAssertCheck == 1U);
    sim_data->mData->mIsSolverCheckingCIC = ssIsSolverCheckingCIC(rtS);
    sim_data->mData->mIsComputingJacobian = ssIsSolverComputingJacobian(rtS);
    sim_data->mData->mIsSolverRequestingReset = ssIsSolverRequestingReset(rtS);
    sim_data->mData->mDx.mX = &((XDot *) ssGetdX(rtS))->EXEC_STATE_1_CSTATE[0];
    sim_data->mData->mDx.mN = 4;

    {
      NeuDiagnosticManager *mgr = (NeuDiagnosticManager *)
        rtDW.EXEC_STATE_1_PWORK[3];
      const NeuDiagnosticTree *tree = mgr->mGetInitialTree(mgr);
      if (ne_simulator_method(simulator, NESL_SIM_DERIVATIVES, sim_data, mgr) !=
          NESL_SIM_OK) {
        if (ssIsMajorTimeStep(rtS) ||
            (ssGetT(rtS) == 0.0) ||
            (ssGetT(rtS) - rtDW.EXEC_STATE_1_RWORK < 64.0e-16 * ssGetT(rtS))) {
          static char_T errorMsg[1024];
          NeuDiagnosticTreePrinter *printer = neu_create_diagnostic_tree_printer
            (ne_default_allocator());
          const char *msg = printer->mPrint(printer, tree);
          strncpy( errorMsg, msg, sizeof(errorMsg) - 1 );
          printer->mDestroy(printer);
          ssSetErrorStatus(rtS, errorMsg);
          return;
        } else {
          sim_data->mData->mDx.mX[0] = rtNaN;
        }
      }
    }
  }
}

/* Projection for root system: '<Root>' */
void MdlProjection(void)
{
  /* SimscapeExecutionBlock Block: <S14>/EXEC_STATE_1 */
  {
    NeslSimulator* simulator;
    NeslSimulationData* sim_data;
    simulator = (NeslSimulator *) rtDW.EXEC_STATE_1_PWORK[0];
    sim_data = (NeslSimulationData *) rtDW.EXEC_STATE_1_PWORK[1];
    sim_data->mData->mTime.mX[0] = ssGetT(rtS);
    sim_data->mData->mContStates.mX = &rtX.EXEC_STATE_1_CSTATE[0];
    sim_data->mData->mContStates.mN = 4;
    sim_data->mData->mModeVector.mX = NULL;
    sim_data->mData->mModeVector.mN = 0;
    sim_data->mData->mDiscStates.mX = NULL;
    sim_data->mData->mDiscStates.mN = 0;

    {
      sim_data->mData->mInputPorts[0] = (const real_T *)
        rtB.TmpSignalConversionAtEXEC_STATE;
      sim_data->mData->mInputPorts[1] = (const real_T *) rtB.EXEC_INPUT_1;
    }

    sim_data->mData->mNumInputPorts = 2;
    sim_data->mData->mFoundZcEvents = ssIsMajorTimeStep(rtS) &&
      ssGetRTWSolverInfo(rtS)->foundContZcEvents;
    sim_data->mData->mIsMajorTimeStep = ssIsMajorTimeStep(rtS);
    sim_data->mData->mIsSolverAssertCheck = (ssGetMdlInfoPtr(rtS)
      ->mdlFlags.solverAssertCheck == 1U);
    sim_data->mData->mIsSolverCheckingCIC = ssIsSolverCheckingCIC(rtS);
    sim_data->mData->mIsComputingJacobian = ssIsSolverComputingJacobian(rtS);
    sim_data->mData->mIsSolverRequestingReset = ssIsSolverRequestingReset(rtS);

    {
      NeuDiagnosticManager *mgr = (NeuDiagnosticManager *)
        rtDW.EXEC_STATE_1_PWORK[3];
      const NeuDiagnosticTree *tree = mgr->mGetInitialTree(mgr);
      if (ne_simulator_method(simulator, NESL_SIM_PROJECTION, sim_data, mgr) !=
          NESL_SIM_OK) {
        static char_T errorMsg[1024];
        NeuDiagnosticTreePrinter *printer = neu_create_diagnostic_tree_printer
          (ne_default_allocator());
        const char *msg = printer->mPrint(printer, tree);
        strncpy( errorMsg, msg, sizeof(errorMsg) - 1 );
        printer->mDestroy(printer);
        ssSetErrorStatus(rtS, errorMsg);
        return;
      }
    }
  }
}

/* Termination for root system: '<Root>' */
void MdlTerminate(void)
{
  /* SimscapeExecutionBlock Block: <S14>/EXEC_STATE_1 */
  {
    const NeslSimulatorGroupRegistry * registry;
    const char * key;
    NeslSimulationData* sim_data;
    NeuDiagnosticManager* diag_mgr;
    registry = nesl_get_registry();
    key = "pend_v2/Solver Configuration";
    registry->mErase(registry, key);
    sim_data = (NeslSimulationData *) rtDW.EXEC_STATE_1_PWORK[1];
    diag_mgr = (NeuDiagnosticManager *) rtDW.EXEC_STATE_1_PWORK[3];
    if (sim_data != NULL) {
      sim_data->mDestroy(sim_data);
    }

    if (diag_mgr != NULL) {
      diag_mgr->mDestroy(diag_mgr);
    }
  }

  /* SimscapeExecutionBlock Block: <S14>/EXEC_OUTPUT_3 */
  {
    const NeslSimulatorGroupRegistry * registry;
    const char * key;
    NeslSimulationData* sim_data;
    NeuDiagnosticManager* diag_mgr;
    registry = nesl_get_registry();
    key = "pend_v2/Solver Configuration";
    registry->mErase(registry, key);
    sim_data = (NeslSimulationData *) rtDW.EXEC_OUTPUT_3_PWORK[1];
    diag_mgr = (NeuDiagnosticManager *) rtDW.EXEC_OUTPUT_3_PWORK[3];
    if (sim_data != NULL) {
      sim_data->mDestroy(sim_data);
    }

    if (diag_mgr != NULL) {
      diag_mgr->mDestroy(diag_mgr);
    }
  }

  /* SimscapeExecutionBlock Block: <S13>/EXEC_INPUT_1 */
  {
    const NeslSimulatorGroupRegistry * registry;
    const char * key;
    NeslSimulationData* sim_data;
    NeuDiagnosticManager* diag_mgr;
    registry = nesl_get_registry();
    key = "pend_v2/Solver Configuration";
    registry->mErase(registry, key);
    sim_data = (NeslSimulationData *) rtDW.EXEC_INPUT_1_PWORK[1];
    diag_mgr = (NeuDiagnosticManager *) rtDW.EXEC_INPUT_1_PWORK[3];
    if (sim_data != NULL) {
      sim_data->mDestroy(sim_data);
    }

    if (diag_mgr != NULL) {
      diag_mgr->mDestroy(diag_mgr);
    }
  }

  /* SimscapeExecutionBlock Block: <S14>/EXEC_SINK_2 */
  {
    const NeslSimulatorGroupRegistry * registry;
    const char * key;
    NeslSimulationData* sim_data;
    NeuDiagnosticManager* diag_mgr;
    registry = nesl_get_registry();
    key = "pend_v2/Solver Configuration";
    registry->mErase(registry, key);
    sim_data = (NeslSimulationData *) rtDW.EXEC_SINK_2_PWORK[1];
    diag_mgr = (NeuDiagnosticManager *) rtDW.EXEC_SINK_2_PWORK[3];
    if (sim_data != NULL) {
      sim_data->mDestroy(sim_data);
    }

    if (diag_mgr != NULL) {
      diag_mgr->mDestroy(diag_mgr);
    }
  }
}

/* Function to initialize sizes */
void MdlInitializeSizes(void)
{
  ssSetNumContStates(rtS, 4);          /* Number of continuous states */
  ssSetNumY(rtS, 0);                   /* Number of model outputs */
  ssSetNumU(rtS, 0);                   /* Number of model inputs */
  ssSetDirectFeedThrough(rtS, 0);      /* The model is not direct feedthrough */
  ssSetNumSampleTimes(rtS, 2);         /* Number of sample times */
  ssSetNumBlocks(rtS, 68);             /* Number of blocks */
  ssSetNumBlockIO(rtS, 7);             /* Number of block outputs */
  ssSetNumBlockParams(rtS, 1);         /* Sum of parameter "widths" */
}

/* Function to initialize sample times. */
void MdlInitializeSampleTimes(void)
{
  /* task periods */
  ssSetSampleTime(rtS, 0, 0.0);
  ssSetSampleTime(rtS, 1, 0.0);

  /* task offsets */
  ssSetOffsetTime(rtS, 0, 0.0);
  ssSetOffsetTime(rtS, 1, 1.0);
}

/* Function to register the model */
SimStruct * pend_v2(void)
{
  static struct _ssMdlInfo mdlInfo;
  (void) memset((char *)rtS, 0,
                sizeof(SimStruct));
  (void) memset((char *)&mdlInfo, 0,
                sizeof(struct _ssMdlInfo));
  ssSetMdlInfoPtr(rtS, &mdlInfo);

  /* timing info */
  {
    static time_T mdlPeriod[NSAMPLE_TIMES];
    static time_T mdlOffset[NSAMPLE_TIMES];
    static time_T mdlTaskTimes[NSAMPLE_TIMES];
    static int_T mdlTsMap[NSAMPLE_TIMES];
    static int_T mdlSampleHits[NSAMPLE_TIMES];
    static boolean_T mdlTNextWasAdjustedPtr[NSAMPLE_TIMES];
    static int_T mdlPerTaskSampleHits[NSAMPLE_TIMES * NSAMPLE_TIMES];
    static time_T mdlTimeOfNextSampleHit[NSAMPLE_TIMES];

    {
      int_T i;
      for (i = 0; i < NSAMPLE_TIMES; i++) {
        mdlPeriod[i] = 0.0;
        mdlOffset[i] = 0.0;
        mdlTaskTimes[i] = 0.0;
        mdlTsMap[i] = i;
        mdlSampleHits[i] = 1;
      }
    }

    ssSetSampleTimePtr(rtS, &mdlPeriod[0]);
    ssSetOffsetTimePtr(rtS, &mdlOffset[0]);
    ssSetSampleTimeTaskIDPtr(rtS, &mdlTsMap[0]);
    ssSetTPtr(rtS, &mdlTaskTimes[0]);
    ssSetSampleHitPtr(rtS, &mdlSampleHits[0]);
    ssSetTNextWasAdjustedPtr(rtS, &mdlTNextWasAdjustedPtr[0]);
    ssSetPerTaskSampleHitsPtr(rtS, &mdlPerTaskSampleHits[0]);
    ssSetTimeOfNextSampleHitPtr(rtS, &mdlTimeOfNextSampleHit[0]);
  }

  ssSetSolverMode(rtS, SOLVER_MODE_SINGLETASKING);

  /*
   * initialize model vectors and cache them in SimStruct
   */

  /* block I/O */
  {
    ssSetBlockIO(rtS, ((void *) &rtB));
    (void) memset(((void *) &rtB), 0,
                  sizeof(B));
  }

  /* parameters */
  ssSetDefaultParam(rtS, (real_T *) &rtP);

  /* states (continuous)*/
  {
    real_T *x = (real_T *) &rtX;
    ssSetContStates(rtS, x);
    (void) memset((void *)x, 0,
                  sizeof(X));
  }

  /* states (dwork) */
  {
    void *dwork = (void *) &rtDW;
    ssSetRootDWork(rtS, dwork);
    (void) memset(dwork, 0,
                  sizeof(DW));
  }

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    ssSetModelMappingInfo(rtS, &dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Model specific registration */
  ssSetRootSS(rtS, rtS);
  ssSetVersion(rtS, SIMSTRUCT_VERSION_LEVEL2);
  ssSetModelName(rtS, "pend_v2");
  ssSetPath(rtS, "pend_v2");
  ssSetTStart(rtS, 0.0);
  ssSetTFinal(rtS, 10.0);

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    ssSetRTWLogInfo(rtS, &rt_DataLoggingInfo);
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogXSignalPtrs(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogT(ssGetRTWLogInfo(rtS), "tout");
    rtliSetLogX(ssGetRTWLogInfo(rtS), "");
    rtliSetLogXFinal(ssGetRTWLogInfo(rtS), "");
    rtliSetSigLog(ssGetRTWLogInfo(rtS), "");
    rtliSetLogVarNameModifier(ssGetRTWLogInfo(rtS), "rt_");
    rtliSetLogFormat(ssGetRTWLogInfo(rtS), 0);
    rtliSetLogMaxRows(ssGetRTWLogInfo(rtS), 1000);
    rtliSetLogDecimation(ssGetRTWLogInfo(rtS), 1);
    rtliSetLogY(ssGetRTWLogInfo(rtS), "");
    rtliSetLogYSignalInfo(ssGetRTWLogInfo(rtS), (NULL));
    rtliSetLogYSignalPtrs(ssGetRTWLogInfo(rtS), (NULL));
  }

  {
    static struct _ssStatesInfo2 statesInfo2;
    ssSetStatesInfo2(rtS, &statesInfo2);
  }

  {
    static ssSolverInfo slvrInfo;
    static struct _ssSFcnModelMethods3 mdlMethods3;
    static struct _ssSFcnModelMethods2 mdlMethods2;
    static boolean_T contStatesDisabled[4];
    static real_T absTol[4] = { 1.0E-6, 1.0E-6, 1.0E-6, 1.0E-6 };

    static uint8_T absTolControl[4] = { 0U, 0U, 0U, 0U };

    ssSetSolverRelTol(rtS, 0.001);
    ssSetStepSize(rtS, 0.0);
    ssSetMinStepSize(rtS, 0.0);
    ssSetMaxNumMinSteps(rtS, -1);
    ssSetMinStepViolatedError(rtS, 0);
    ssSetMaxStepSize(rtS, 0.2);
    ssSetSolverMaxOrder(rtS, -1);
    ssSetSolverRefineFactor(rtS, 2);
    ssSetOutputTimes(rtS, (NULL));
    ssSetNumOutputTimes(rtS, 0);
    ssSetOutputTimesOnly(rtS, 0);
    ssSetOutputTimesIndex(rtS, 0);
    ssSetZCCacheNeedsReset(rtS, 0);
    ssSetDerivCacheNeedsReset(rtS, 0);
    ssSetNumNonContDerivSigInfos(rtS, 0);
    ssSetNonContDerivSigInfos(rtS, (NULL));
    ssSetSolverInfo(rtS, &slvrInfo);
    ssSetSolverName(rtS, "ode45");
    ssSetVariableStepSolver(rtS, 1);
    ssSetSolverConsistencyChecking(rtS, 0);
    ssSetSolverAdaptiveZcDetection(rtS, 0);
    ssSetSolverRobustResetMethod(rtS, 0);
    _ssSetSolverUpdateJacobianAtReset(rtS, 1);
    ssSetAbsTolVector(rtS, absTol);
    ssSetAbsTolControlVector(rtS, absTolControl);
    ssSetSolverAbsTol_Obsolete(rtS, absTol);
    ssSetSolverAbsTolControl_Obsolete(rtS, absTolControl);
    ssSetSolverStateProjection(rtS, 1);
    (void) memset((void *)&mdlMethods2, 0,
                  sizeof(mdlMethods2));
    ssSetModelMethods2(rtS, &mdlMethods2);
    (void) memset((void *)&mdlMethods3, 0,
                  sizeof(mdlMethods3));
    ssSetModelMethods3(rtS, &mdlMethods3);
    ssSetModelProjection(rtS, MdlProjection);
    ssSetSolverMassMatrixType(rtS, (ssMatrixType)0);
    ssSetSolverMassMatrixNzMax(rtS, 0);
    ssSetModelOutputs(rtS, MdlOutputs);
    ssSetModelLogData(rtS, rt_UpdateTXYLogVars);
    ssSetModelUpdate(rtS, MdlUpdate);
    ssSetModelDerivatives(rtS, MdlDerivatives);
    ssSetSolverMaxConsecutiveMinStep(rtS, 1);
    ssSetSolverShapePreserveControl(rtS, 2);
    ssSetTNextTid(rtS, INT_MIN);
    ssSetTNext(rtS, rtMinusInf);
    ssSetSolverNeedsReset(rtS);
    ssSetNumNonsampledZCs(rtS, 0);
    ssSetContStateDisabled(rtS, contStatesDisabled);
    ssSetSolverMaxConsecutiveMinStep(rtS, 1);
  }

  ssSetChecksumVal(rtS, 0, 3689672122U);
  ssSetChecksumVal(rtS, 1, 1574980793U);
  ssSetChecksumVal(rtS, 2, 860458499U);
  ssSetChecksumVal(rtS, 3, 1780324092U);
  return rtS;
}
