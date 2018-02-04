/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'pend_v2/Solver Configuration'.
 */

#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "sm_ssci_run_time_errors.h"

PmfMessageId pend_v2_9701bd64_1_output(const double *state, const double *input,
  const double *inputDot, const double *inputDdot, const double *discreteState,
  double *output, NeuDiagnosticManager *neDiagMgr)
{
  (void) input;
  (void) inputDot;
  (void) inputDdot;
  (void) discreteState;
  (void) neDiagMgr;
  output[0] = state[2];
  output[1] = state[0];
  return NULL;
}
