/* Simscape target specific file.
 * This file is generated for the Simscape network associated with the solver block 'pend_v2/Solver Configuration'.
 */

#include <math.h>
#include <string.h>
#include "pm_std.h"
#include "sm_std.h"
#include "sm_ssci_run_time_errors.h"

PmfMessageId pend_v2_9701bd64_1_deriv(const double *state, const double *input,
  const double *inputDot, const double *inputDdot, const double *discreteState,
  double *deriv, NeuDiagnosticManager *neDiagMgr)
{
  double xx[73];
  int ii[4];
  (void) inputDot;
  (void) inputDdot;
  (void) discreteState;
  (void) neDiagMgr;
  xx[0] = 0.8485372026601608;
  xx[1] = 0.5;
  xx[2] = xx[1] * state[2];
  xx[3] = cos(xx[2]);
  xx[4] = xx[0] * xx[3];
  xx[5] = - xx[4];
  xx[6] = 0.5291357252177076;
  xx[7] = sin(xx[2]);
  xx[2] = xx[6] * xx[7];
  xx[8] = - xx[2];
  xx[9] = xx[0] * xx[7];
  xx[10] = xx[5];
  xx[11] = xx[8];
  xx[12] = xx[9];
  xx[0] = 1.414213562373095 * 0.7071067811865476 * input[1];
  xx[7] = input[1] - xx[0];
  xx[13] = xx[4] * xx[7];
  xx[15] = xx[0] * xx[4];
  xx[17] = xx[2] * xx[7] - xx[0] * xx[9];
  xx[18] = - xx[13];
  xx[19] = - xx[15];
  pm_math_cross3(xx + 10, xx + 17, xx + 20);
  xx[14] = xx[6] * xx[3];
  xx[3] = 2.0;
  xx[6] = 0.08;
  xx[16] = 0.01799999999999999;
  xx[18] = xx[6] * xx[2] - xx[16] * xx[9];
  xx[17] = xx[6] * xx[4];
  xx[24] = xx[16] * xx[4];
  xx[26] = xx[18];
  xx[27] = - xx[17];
  xx[28] = - xx[24];
  pm_math_cross3(xx + 10, xx + 26, xx + 29);
  xx[19] = (xx[14] * xx[18] + xx[29]) * xx[3];
  xx[18] = 8.235242758695742e-3 - (xx[16] + xx[3] * (xx[30] - xx[14] * xx[17]));
  xx[16] = 0.03964996467615679 - ((xx[31] - xx[24] * xx[14]) * xx[3] - xx[6]);
  xx[24] = - xx[19];
  xx[25] = xx[18];
  xx[26] = xx[16];
  xx[27] = xx[14];
  xx[28] = xx[5];
  xx[29] = xx[8];
  xx[30] = xx[9];
  xx[5] = 0.022;
  xx[6] = 0.8979826962075781;
  xx[8] = xx[6] * state[1];
  xx[17] = 0.4400307685966615;
  xx[31] = xx[17] * state[1];
  xx[35] = xx[8] * xx[16] + xx[31] * xx[18];
  xx[37] = xx[8] * xx[8] * xx[19] + xx[31] * xx[31] * xx[19];
  xx[38] = - xx[31] * xx[35];
  xx[39] = - xx[8] * xx[35];
  pm_math_quatInverseXform(xx + 27, xx + 37, xx + 32);
  xx[35] = xx[5] * xx[32];
  xx[36] = 1.76e-3;
  xx[37] = 0.08000000000000002;
  xx[39] = 1.408000000000001e-4;
  ii[0] = 0;
  memcpy(ii + 2, ii + 0, 1 * sizeof(int));
  ii[1] = factorSymmetric(xx + 39, 1, xx + 42, xx + 41, ii + 2, ii + 3);
  if (ii[3] != 0) {
    return sm_ssci_recordRunTimeError(
      "sm:compiler:messages:simulationErrors:DegenerateMass",
      "'pend_v2/RIP System/Pendulum/Revolute Joint' has a degenerate mass distribution on its follower side.",
      neDiagMgr);
  }

  xx[40] = (xx[37] * xx[35] + xx[0]) / xx[39];
  xx[38] = xx[31] * xx[4];
  xx[42] = xx[8] * xx[4];
  xx[43] = xx[8] * xx[9] - xx[31] * xx[2];
  xx[44] = xx[38];
  xx[45] = xx[42];
  pm_math_cross3(xx + 10, xx + 43, xx + 46);
  xx[10] = xx[31] + xx[3] * (xx[48] - xx[14] * xx[42]);
  xx[12] = xx[37] * state[3];
  xx[32] = (xx[47] - xx[14] * xx[38]) * xx[3] - xx[8];
  xx[42] = xx[35] - xx[36] * xx[40];
  xx[43] = (xx[33] - (xx[10] + xx[10]) * xx[12]) * xx[5];
  xx[44] = xx[5] * (xx[34] + (xx[32] + xx[32] - state[3]) * xx[12]);
  pm_math_quatXform(xx + 27, xx + 42, xx + 10);
  pm_math_cross3(xx + 24, xx + 10, xx + 32);
  xx[11] = 0.3741554594695026;
  xx[12] = xx[11] * input[0];
  xx[37] = xx[11] * xx[12];
  xx[41] = xx[14] * xx[14];
  xx[43] = 1.0;
  xx[44] = (xx[41] + xx[4] * xx[4]) * xx[3] - xx[43];
  xx[42] = xx[2] * xx[4];
  xx[45] = xx[14] * xx[9];
  xx[46] = xx[42] - xx[45];
  xx[48] = xx[4] * xx[9];
  xx[49] = xx[14] * xx[2];
  xx[50] = xx[48] + xx[49];
  xx[52] = (xx[42] + xx[45]) * xx[3];
  xx[45] = (xx[41] + xx[2] * xx[2]) * xx[3] - xx[43];
  xx[42] = xx[14] * xx[4];
  xx[53] = xx[2] * xx[9];
  xx[2] = xx[42] - xx[53];
  xx[54] = xx[3] * (xx[49] - xx[48]);
  xx[48] = xx[53] + xx[42];
  xx[42] = (xx[41] + xx[9] * xx[9]) * xx[3] - xx[43];
  xx[55] = xx[44];
  xx[56] = xx[3] * xx[46];
  xx[57] = - xx[50] * xx[3];
  xx[58] = xx[52];
  xx[59] = xx[45];
  xx[60] = xx[3] * xx[2];
  xx[61] = xx[54];
  xx[62] = - xx[48] * xx[3];
  xx[63] = xx[42];
  xx[9] = xx[36] / xx[39];
  xx[39] = xx[5] - xx[36] * xx[9];
  xx[36] = 0.044;
  xx[64] = xx[39] * xx[44];
  xx[65] = xx[52] * xx[39];
  xx[66] = xx[54] * xx[39];
  xx[67] = xx[36] * xx[46];
  xx[68] = xx[5] * xx[45];
  xx[69] = - xx[48] * xx[36];
  xx[70] = - xx[50] * xx[36];
  xx[71] = xx[36] * xx[2];
  xx[72] = xx[5] * xx[42];
  pm_math_matrix3x3Compose(xx + 55, xx + 64, xx + 41);
  pm_math_matrix3x3PostCross(xx + 41, xx + 24, xx + 50);
  xx[2] = 0.1167712576148805;
  xx[36] = xx[2] * state[1];
  xx[39] = xx[8] * xx[36];
  xx[8] = xx[31] * xx[36];
  xx[20] = 0.6000064100900635;
  xx[23] = xx[20] * xx[12];
  pm_math_matrix3x3PreCross(xx + 50, xx + 24, xx + 61);
  xx[12] = (0.2546731798581232 + xx[41]) * xx[2] + xx[17] * xx[52] - xx[6] * xx
    [51];
  xx[25] = xx[17] * (xx[17] * (2.015633494905782e-5 - xx[69]) + xx[6] * xx[68] +
                     xx[2] * xx[52]) - xx[6] * (xx[2] * xx[51] - (xx[6] *
    (3.037378882141068e-4 - xx[65]) + xx[17] * xx[66])) + xx[2] * xx[12];
  ii[1] = factorSymmetric(xx + 25, 1, xx + 35, xx + 31, ii + 0, ii + 2);
  if (ii[2] != 0) {
    return sm_ssci_recordRunTimeError(
      "sm:compiler:messages:simulationErrors:DegenerateMass",
      "'pend_v2/RIP System/Rod/Revolute Joint' has a degenerate mass distribution on its follower side.",
      neDiagMgr);
  }

  xx[48] = - xx[12] / xx[25];
  xx[49] = - (xx[2] * xx[44] + xx[17] * xx[55] - xx[6] * xx[54]) / xx[25];
  xx[50] = - (xx[2] * xx[47] + xx[17] * xx[58] - xx[6] * xx[57]) / xx[25];
  xx[12] = xx[1] * state[0];
  xx[1] = cos(xx[12]);
  xx[26] = xx[20] * xx[1];
  xx[31] = sin(xx[12]);
  xx[12] = xx[17] * xx[31];
  xx[32] = xx[20] * xx[12];
  xx[35] = xx[6] * xx[31];
  xx[31] = xx[11] * xx[35];
  xx[36] = xx[26] - xx[32] - xx[31];
  xx[41] = 9.800000000000001;
  xx[44] = xx[11] * xx[1];
  xx[1] = xx[11] * xx[12];
  xx[11] = xx[20] * xx[35];
  xx[12] = xx[44] - xx[1] + xx[11];
  xx[20] = xx[41] * xx[12];
  xx[35] = xx[11] - xx[44] - xx[1];
  xx[1] = xx[41] * xx[35];
  xx[11] = xx[26] + xx[31] + xx[32];
  xx[26] = xx[3] * (xx[36] * xx[20] + xx[1] * xx[11]);
  xx[31] = (xx[36] * xx[1] - xx[20] * xx[11]) * xx[3];
  xx[11] = xx[41] - (xx[20] * xx[12] + xx[1] * xx[35]) * xx[3];
  xx[44] = xx[26];
  xx[45] = xx[31];
  xx[46] = xx[11];
  xx[1] = (((xx[22] - xx[14] * xx[15]) * xx[3] - xx[7] + xx[34] - (input[0] -
             (xx[37] + xx[37]) * xx[3]) + xx[58] * xx[39] + xx[55] * xx[8]) *
           xx[17] - (xx[0] + (xx[21] - xx[14] * xx[13]) * xx[3] + xx[33] + xx[3]
                     * (xx[23] + xx[23]) + xx[57] * xx[39] + xx[54] * xx[8]) *
           xx[6] - (xx[10] - (xx[42] * xx[8] + xx[43] * xx[39])) * xx[2]) / xx
    [25] + pm_math_dot3(xx + 48, xx + 44);
  xx[0] = xx[1] * xx[17];
  xx[3] = xx[1] * xx[6];
  xx[5] = xx[26] + xx[1] * xx[2] + xx[0] * xx[18] + xx[3] * xx[16];
  xx[6] = xx[31] - xx[8] + xx[19] * xx[0];
  xx[7] = xx[11] - xx[39] + xx[19] * xx[3];
  pm_math_quatInverseXform(xx + 27, xx + 5, xx + 2);
  deriv[0] = state[1];
  deriv[1] = - xx[1];
  deriv[2] = state[3];
  deriv[3] = xx[40] + xx[9] * xx[2];
  return NULL;
}
