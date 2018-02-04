/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'pend_v2/Solver Configuration'.
 */

#include "pm_std.h"
#include "ne_std.h"
#include "ne_dae.h"
#include "ne_default_allocator.h"
#include "sm_ssci_NeDaePrivateData.h"
#include "sm_CTarget.h"
#define ne_allocator_alloc(_allocator, _m, _n) ((_allocator)->mCallocFcn((_allocator), (_m), (_n)))
#define NE_ALLOCATE_ARRAY(_name, _type, _size, _allocator)\
 _name = (_type *) ne_allocator_alloc(_allocator, sizeof(_type), _size)
#define ne_size_to_int(_size)          ((int32_T) (_size))

NeIntVector *neu_create_int_vector(size_t, NeAllocator *);
int_T neu_create_int_vector_fields (NeIntVector *, size_t, NeAllocator *);
int_T neu_create_real_vector_fields(NeRealVector *, size_t, NeAllocator *);
int_T neu_create_char_vector_fields(NeCharVector *, size_t, NeAllocator *);
int_T neu_create_bool_vector_fields(NeBoolVector *, size_t, NeAllocator *);
void neu_rv_equals_rv(const NeRealVector *, const NeRealVector *);
void sm_ssci_setupLoggerFcn_codeGen(const NeDae *dae,
  NeLoggerBuilder *neLoggerBuilder);
int32_T sm_ssci_logFcn_codeGen(const NeDae *dae,
  const NeSystemInput *systemInput,
  NeRealVector *output);
PmfMessageId pend_v2_9701bd64_1_deriv(const double *,
  const double *, const double *, const double *,
  const double *,
  double *,
  NeuDiagnosticManager *neDiagMgr);
PmfMessageId pend_v2_9701bd64_1_outputDyn(const double *,
  const double *, const double *, const double *,
  const double *,
  double *,
  double *,
  NeuDiagnosticManager *neDiagMgr);
PmfMessageId pend_v2_9701bd64_1_outputKin(const double *,
  const double *, const double *, const double *,
  const double *,
  double *,
  NeuDiagnosticManager *neDiagMgr);
PmfMessageId pend_v2_9701bd64_1_output (const double *,
  const double *, const double *, const double *,
  const double *,
  double *,
  NeuDiagnosticManager *neDiagMgr);
PmfMessageId pend_v2_9701bd64_1_project(const double *, const double *, const
  double *,
  double *,
  NeuDiagnosticManager *neDiagMgr);
PmfMessageId pend_v2_9701bd64_1_assemble(const double *u, double *udot, double
  *x,
  NeuDiagnosticManager *neDiagMgr)
{
  (void) x;
  (void) u;
  (void) udot;
  return NULL;
}

static
  PmfMessageId dae_deriv_method(const NeDae *dae,
  const NeSystemInput *systemInput,
  NeDaeMethodOutput *daeMethodOutput,
  NeuDiagnosticManager *neDiagMgr)
{
  const NeDaePrivateData *smData = dae->mPrivateData;
  PmfMessageId errorId = NULL;
  if (smData->mCachedDerivativesAvailable)
    memcpy(daeMethodOutput->mXP0.mX, smData->mCachedDerivatives.mX,
           4 * sizeof(real_T));
  else
    errorId = pend_v2_9701bd64_1_deriv(
      systemInput->mX.mX,
      systemInput->mU.mX,
      systemInput->mU.mX + 2,
      systemInput->mV.mX + 2,
      systemInput->mD.mX,
      daeMethodOutput->mXP0.mX, neDiagMgr);
  return errorId;
}

static
  PmfMessageId dae_output_method(const NeDae *dae,
  const NeSystemInput *systemInput,
  NeDaeMethodOutput *daeMethodOutput,
  NeuDiagnosticManager *neDiagMgr)
{
  PmfMessageId errorId = NULL;
  (void) dae;
  errorId = pend_v2_9701bd64_1_output(
    systemInput->mX.mX,
    systemInput->mU.mX,
    systemInput->mU.mX + 2,
    systemInput->mV.mX + 2,
    systemInput->mD.mX,
    daeMethodOutput->mY.mX, neDiagMgr);
  return errorId;
}

static
  PmfMessageId dae_project_solve(const NeDae *dae,
  const NeSystemInput *systemInput,
  NeuDiagnosticManager *neDiagMgr)
{
  (void) dae;
  return
    pend_v2_9701bd64_1_project(
    systemInput->mU.mX,
    systemInput->mU.mX + 2,
    systemInput->mD.mX,
    systemInput->mX.mX, neDiagMgr);
}

static
  PmfMessageId dae_assemble_solve(const NeDae *dae,
  const NeSystemInput *systemInput,
  NeuDiagnosticManager *neDiagMgr)
{
  PmfMessageId errorId = NULL;
  pend_v2_9701bd64_1_assemble(
    systemInput->mU.mX,
    systemInput->mU.mX + 2,
    systemInput->mX.mX, neDiagMgr);
  neu_rv_equals_rv(&systemInput->mX, &dae->mPrivateData->mInitialStateVector);
  neu_rv_equals_rv(&systemInput->mD, &dae->mPrivateData->mDiscreteStateVector);
  return errorId;
}

typedef struct {
  size_t first;
  size_t second;
} SizePair;

static void checkMemAllocStatus(int_T status)
{
  (void) status;
}

static
  NeCharVector cStringToCharVector(const char *src)
{
  const size_t n = strlen(src);
  NeCharVector charVect;
  const int_T status =
    neu_create_char_vector_fields(&charVect, n + 1, ne_default_allocator());
  checkMemAllocStatus(status);
  strcpy(charVect.mX, src);
  return charVect;
}

static
  void initBasicAttributes(NeDaePrivateData *smData)
{
  size_t i;
  smData->mStateVectorSize = 4;
  smData->mFullStateVectorSize = 4;
  smData->mDiscreteStateSize = 0;
  smData->mInputVectorSize = 2;
  smData->mOutputVectorSize = 2;
  smData->mNumConstraintEqns = 0;
  for (i = 0; i < 4; ++i)
    smData->mChecksum[i] = 0;
}

static
  void initStateVector(NeDaePrivateData *smData)
{
  NeAllocator *alloc = ne_default_allocator();
  const double initialStateVector[4] = {
    +0.000000000000000000e+00, +0.000000000000000000e+00,
    +1.570796326794896600e+00, +0.000000000000000000e+00
  };

  const double *discreteStateVector = NULL;
  int_T status = 0;
  status = neu_create_real_vector_fields(
    &smData->mInitialStateVector, 4, alloc);
  checkMemAllocStatus(status);
  memcpy(smData->mInitialStateVector.mX, initialStateVector,
         4 * sizeof(real_T));
  status = neu_create_real_vector_fields(
    &smData->mDiscreteStateVector, 0, alloc);
  checkMemAllocStatus(status);
  memcpy(smData->mDiscreteStateVector.mX, discreteStateVector,
         0 * sizeof(real_T));
  smData->mNumTargets = 4;
  NE_ALLOCATE_ARRAY(smData->mTargets, CTarget, smData->mNumTargets, alloc);

  {
    const unsigned int targetTypes [4] = {
      0, 0, 0, 0
    };

    const size_t targetJointIndices [4] = {
      21, 21, 44, 44
    };

    const size_t targetPrimIndices [4] = {
      0, 0, 0, 0
    };

    const unsigned int targetStrengths[4] = {
      0, 2, 2, 2
    };

    const char *targetUnits [4] = {
      "deg", "1", "1", "1"
    };

    const bool targetIsVelFlags [4] = {
      false, true, false, true
    };

    const bool targetIsAngFlags [4] = {
      true, true, true, true
    };

    const real_T targetScalarVals [4] = {
      +1.570796326794896600e+00, +0.000000000000000000e+00,
      +0.000000000000000000e+00, +0.000000000000000000e+00
    };

    const real_T targetRotations [4][4] = {
      { +1.000000000000000000e+00, +0.000000000000000000e+00,
        +0.000000000000000000e+00, +0.000000000000000000e+00 },

      { +1.000000000000000000e+00, +0.000000000000000000e+00,
        +0.000000000000000000e+00, +0.000000000000000000e+00 },

      { +1.000000000000000000e+00, +0.000000000000000000e+00,
        +0.000000000000000000e+00, +0.000000000000000000e+00 },

      { +1.000000000000000000e+00, +0.000000000000000000e+00,
        +0.000000000000000000e+00, +0.000000000000000000e+00 }
    };

    const bool targetInFollFrameFlags [4] = {
      false, false, false, false
    };

    const real_T targetAngularVels [4][3] = {
      { +0.000000000000000000e+00, +0.000000000000000000e+00,
        +0.000000000000000000e+00 },

      { +0.000000000000000000e+00, +0.000000000000000000e+00,
        +0.000000000000000000e+00 },

      { +0.000000000000000000e+00, +0.000000000000000000e+00,
        +0.000000000000000000e+00 },

      { +0.000000000000000000e+00, +0.000000000000000000e+00,
        +0.000000000000000000e+00 }
    };

    size_t i;
    for (i = 0; i < smData->mNumTargets; ++i) {
      CTarget *target = smData->mTargets + i;
      target->mType = targetTypes[i];
      target->mJointContIdx = targetJointIndices[i];
      target->mPrimIdx = targetPrimIndices[i];
      target->mStrength = targetStrengths[i];
      sm_compiler_CTarget_setSpecifiedUnit(targetUnits[i], target);
      target->mIsVelocity = targetIsVelFlags[i];
      target->mIsAngular = targetIsAngFlags[i];
      target->mScalarValue = targetScalarVals[i];
      memcpy(target->mRotation, targetRotations[i], 4 * sizeof(real_T));
      target->mInFollowerFrame = targetInFollFrameFlags[i];
      memcpy(target->mAngularVelocity, targetAngularVels[i], 3 * sizeof(real_T));
    }
  }
}

static
  void initVariables(NeDaePrivateData *smData)
{
  const char *varFullPaths[4] = {
    "RIP_System.Rod.Revolute_Joint.Rz.q",
    "RIP_System.Rod.Revolute_Joint.Rz.w",
    "RIP_System.Pendulum.Revolute_Joint.Rz.q",
    "RIP_System.Pendulum.Revolute_Joint.Rz.w"
  };

  const char *varObjects[4] = {
    "pend_v2/RIP System/Rod/Revolute Joint",
    "pend_v2/RIP System/Rod/Revolute Joint",
    "pend_v2/RIP System/Pendulum/Revolute Joint",
    "pend_v2/RIP System/Pendulum/Revolute Joint"
  };

  smData->mNumVarScalars = 4;
  smData->mVarFullPaths = NULL;
  smData->mVarObjects = NULL;
  if (smData->mNumVarScalars > 0) {
    size_t s;
    NeAllocator *alloc = ne_default_allocator();
    NE_ALLOCATE_ARRAY(smData->mVarFullPaths, NeCharVector, 4, alloc);
    NE_ALLOCATE_ARRAY(smData->mVarObjects, NeCharVector, 4, alloc);
    for (s = 0; s < smData->mNumVarScalars; ++s) {
      smData->mVarFullPaths[s] = cStringToCharVector(varFullPaths[s]);
      smData->mVarObjects[s] = cStringToCharVector(varObjects[s]);
    }
  }
}

static
  void initIoInfoHelper(
  size_t n,
  const char *portPathsSource[],
  const char *unitsSource[],
  const SizePair dimensions[],
  bool doInputs,
  NeDaePrivateData *smData)
{
  NeCharVector *portPaths = NULL;
  NeCharVector *units = NULL;
  NeDsIoInfo *infos = NULL;
  if (n > 0) {
    size_t s;
    NeAllocator *alloc = ne_default_allocator();
    NE_ALLOCATE_ARRAY(portPaths, NeCharVector, n, alloc);
    NE_ALLOCATE_ARRAY(units, NeCharVector, n, alloc);
    NE_ALLOCATE_ARRAY(infos, NeDsIoInfo, n, alloc);
    for (s = 0; s < n; ++s) {
      portPaths[s] = cStringToCharVector(portPathsSource[s]);
      units[s] = cStringToCharVector(unitsSource[s]);

      {
        NeDsIoInfo *info = infos + s;
        info->mName = info->mIdentifier = portPaths[s].mX;
        info->mM = dimensions[s].first;
        info->mN = dimensions[s].second;
        info->mUnit = units[s].mX;
      }
    }
  }

  if (doInputs) {
    smData->mNumInputs = n;
    smData->mInputPortPaths = portPaths;
    smData->mInputUnits = units;
    smData->mInputInfos = infos;
  } else {
    smData->mNumOutputs = n;
    smData->mOutputPortPaths = portPaths;
    smData->mOutputUnits = units;
    smData->mOutputInfos = infos;
  }
}

static
  void initIoInfo(NeDaePrivateData *smData)
{
  const char *inputPortPaths[2] = {
    "External_Force_and_Torque.tz",
    "RIP_System.Pendulum.friction.tz"
  };

  const char *inputUnits[2] = {
    "m^2*kg/s^2",
    "m^2*kg/s^2"
  };

  const SizePair inputDimensions[2] = {
    { 1, 1 }, { 1, 1 }
  };

  const char *outputPortPaths[2] = {
    "RIP_System.Pendulum.Revolute_Joint.q",
    "RIP_System.Rod.Revolute_Joint.q"
  };

  const char *outputUnits[2] = {
    "rad",
    "rad"
  };

  const SizePair outputDimensions[2] = {
    { 1, 1 }, { 1, 1 }
  };

  initIoInfoHelper(2, inputPortPaths, inputUnits, inputDimensions,
                   true, smData);
  initIoInfoHelper(2, outputPortPaths, outputUnits, outputDimensions,
                   false, smData);
}

static
  void initInputDerivs(NeDaePrivateData *smData)
{
  const int32_T numInputDerivs[2] = {
    0, 0
  };

  NeAllocator *alloc = ne_default_allocator();
  const int_T status = neu_create_int_vector_fields(
    &smData->mNumInputDerivs, smData->mInputVectorSize, alloc);
  checkMemAllocStatus(status);
  memcpy(smData->mNumInputDerivs.mX, numInputDerivs,
         2 * sizeof(int32_T));
  smData->mInputOrder = 1;
}

static
  void initDirectFeedthrough(NeDaePrivateData *smData)
{
  const boolean_T directFeedthroughVector[2] = {
    false, false
  };

  const boolean_T directFeedthroughMatrix[4] = {
    false, false, false, false
  };

  NeAllocator *alloc = ne_default_allocator();

  {
    const int_T status = neu_create_bool_vector_fields(
      &smData->mDirectFeedthroughVector, 2, alloc);
    checkMemAllocStatus(status);
    memcpy(smData->mDirectFeedthroughVector.mX, directFeedthroughVector,
           2 * sizeof(boolean_T));
  }

  {
    const int_T status = neu_create_bool_vector_fields(
      &smData->mDirectFeedthroughMatrix, 4, alloc);
    checkMemAllocStatus(status);
    memcpy(smData->mDirectFeedthroughMatrix.mX, directFeedthroughMatrix,
           4 * sizeof(boolean_T));
  }
}

static
  void initOutputDerivProc(NeDaePrivateData *smData)
{
  NeAllocator *alloc = ne_default_allocator();
  const int32_T outputFunctionMap[2] = {
    0, 0
  };

  smData->mOutputFunctionMap = neu_create_int_vector(2, alloc);
  memcpy(smData->mOutputFunctionMap->mX, outputFunctionMap,
         2 * sizeof(int32_T));
  smData->mNumOutputClasses = 1;
  smData->mHasKinematicOutputs = 1;
  smData->mHasDynamicOutputs = 0;
  smData->mIsOutputClass0Dynamic = 0;
  smData->mDoComputeDynamicOutputs = false;
  smData->mCachedDerivativesAvailable = false;

  {
    size_t i = 0;
    const int_T status = neu_create_real_vector_fields(
      &smData->mCachedDerivatives, 0, ne_default_allocator());
    checkMemAllocStatus(status);
    for (i = 0; i < smData->mCachedDerivatives.mN; ++i)
      smData->mCachedDerivatives.mX[i] = 0.0;
  }
}

static
  void initComputationFcnPtrs(NeDaePrivateData *smData)
{
  smData->mDerivativeFcn = dae_deriv_method;
  smData->mOutputFcn = dae_output_method;
  smData->mProjectionFcn = dae_project_solve;
  smData->mAssemblyFcn = dae_assemble_solve;
  smData->mSetupLoggerFcn = sm_ssci_setupLoggerFcn_codeGen;
  smData->mLogFcn = sm_ssci_logFcn_codeGen;
  smData->mResidualsFcn = NULL;
  smData->mLinearizeFcn = NULL;
  smData->mGenerateFcn = NULL;
}

static
  void initLiveLinkToSm(NeDaePrivateData *smData)
{
  smData->mLiveSmLink = NULL;
  smData->mLiveSmLink_destroy = NULL;
  smData->mLiveSmLink_copy = NULL;
  smData->mLiveSmLink_destroy = NULL;
  smData->mLiveSmLink_copy = NULL;
}

void pend_v2_9701bd64_1_NeDaePrivateData_create(NeDaePrivateData *smData)
{
  initBasicAttributes (smData);
  initStateVector (smData);
  initVariables (smData);
  initIoInfo (smData);
  initInputDerivs (smData);
  initDirectFeedthrough (smData);
  initOutputDerivProc (smData);
  initComputationFcnPtrs (smData);
  initLiveLinkToSm (smData);
}
