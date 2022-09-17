#include "gnss.h"

namespace {
#define DIM 11
#define EDIM 11
#define MEDIM 11
typedef void (*Hfun)(double *, double *, double *);
const static double MAHA_THRESH_6 = 3.8414588206941227;
const static double MAHA_THRESH_20 = 3.8414588206941227;
const static double MAHA_THRESH_7 = 3.8414588206941227;
const static double MAHA_THRESH_21 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with sympy 1.9                        *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_7861368562585023949) {
   out_7861368562585023949[0] = delta_x[0] + nom_x[0];
   out_7861368562585023949[1] = delta_x[1] + nom_x[1];
   out_7861368562585023949[2] = delta_x[2] + nom_x[2];
   out_7861368562585023949[3] = delta_x[3] + nom_x[3];
   out_7861368562585023949[4] = delta_x[4] + nom_x[4];
   out_7861368562585023949[5] = delta_x[5] + nom_x[5];
   out_7861368562585023949[6] = delta_x[6] + nom_x[6];
   out_7861368562585023949[7] = delta_x[7] + nom_x[7];
   out_7861368562585023949[8] = delta_x[8] + nom_x[8];
   out_7861368562585023949[9] = delta_x[9] + nom_x[9];
   out_7861368562585023949[10] = delta_x[10] + nom_x[10];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_6509090499931839816) {
   out_6509090499931839816[0] = -nom_x[0] + true_x[0];
   out_6509090499931839816[1] = -nom_x[1] + true_x[1];
   out_6509090499931839816[2] = -nom_x[2] + true_x[2];
   out_6509090499931839816[3] = -nom_x[3] + true_x[3];
   out_6509090499931839816[4] = -nom_x[4] + true_x[4];
   out_6509090499931839816[5] = -nom_x[5] + true_x[5];
   out_6509090499931839816[6] = -nom_x[6] + true_x[6];
   out_6509090499931839816[7] = -nom_x[7] + true_x[7];
   out_6509090499931839816[8] = -nom_x[8] + true_x[8];
   out_6509090499931839816[9] = -nom_x[9] + true_x[9];
   out_6509090499931839816[10] = -nom_x[10] + true_x[10];
}
void H_mod_fun(double *state, double *out_475664012759985504) {
   out_475664012759985504[0] = 1.0;
   out_475664012759985504[1] = 0;
   out_475664012759985504[2] = 0;
   out_475664012759985504[3] = 0;
   out_475664012759985504[4] = 0;
   out_475664012759985504[5] = 0;
   out_475664012759985504[6] = 0;
   out_475664012759985504[7] = 0;
   out_475664012759985504[8] = 0;
   out_475664012759985504[9] = 0;
   out_475664012759985504[10] = 0;
   out_475664012759985504[11] = 0;
   out_475664012759985504[12] = 1.0;
   out_475664012759985504[13] = 0;
   out_475664012759985504[14] = 0;
   out_475664012759985504[15] = 0;
   out_475664012759985504[16] = 0;
   out_475664012759985504[17] = 0;
   out_475664012759985504[18] = 0;
   out_475664012759985504[19] = 0;
   out_475664012759985504[20] = 0;
   out_475664012759985504[21] = 0;
   out_475664012759985504[22] = 0;
   out_475664012759985504[23] = 0;
   out_475664012759985504[24] = 1.0;
   out_475664012759985504[25] = 0;
   out_475664012759985504[26] = 0;
   out_475664012759985504[27] = 0;
   out_475664012759985504[28] = 0;
   out_475664012759985504[29] = 0;
   out_475664012759985504[30] = 0;
   out_475664012759985504[31] = 0;
   out_475664012759985504[32] = 0;
   out_475664012759985504[33] = 0;
   out_475664012759985504[34] = 0;
   out_475664012759985504[35] = 0;
   out_475664012759985504[36] = 1.0;
   out_475664012759985504[37] = 0;
   out_475664012759985504[38] = 0;
   out_475664012759985504[39] = 0;
   out_475664012759985504[40] = 0;
   out_475664012759985504[41] = 0;
   out_475664012759985504[42] = 0;
   out_475664012759985504[43] = 0;
   out_475664012759985504[44] = 0;
   out_475664012759985504[45] = 0;
   out_475664012759985504[46] = 0;
   out_475664012759985504[47] = 0;
   out_475664012759985504[48] = 1.0;
   out_475664012759985504[49] = 0;
   out_475664012759985504[50] = 0;
   out_475664012759985504[51] = 0;
   out_475664012759985504[52] = 0;
   out_475664012759985504[53] = 0;
   out_475664012759985504[54] = 0;
   out_475664012759985504[55] = 0;
   out_475664012759985504[56] = 0;
   out_475664012759985504[57] = 0;
   out_475664012759985504[58] = 0;
   out_475664012759985504[59] = 0;
   out_475664012759985504[60] = 1.0;
   out_475664012759985504[61] = 0;
   out_475664012759985504[62] = 0;
   out_475664012759985504[63] = 0;
   out_475664012759985504[64] = 0;
   out_475664012759985504[65] = 0;
   out_475664012759985504[66] = 0;
   out_475664012759985504[67] = 0;
   out_475664012759985504[68] = 0;
   out_475664012759985504[69] = 0;
   out_475664012759985504[70] = 0;
   out_475664012759985504[71] = 0;
   out_475664012759985504[72] = 1.0;
   out_475664012759985504[73] = 0;
   out_475664012759985504[74] = 0;
   out_475664012759985504[75] = 0;
   out_475664012759985504[76] = 0;
   out_475664012759985504[77] = 0;
   out_475664012759985504[78] = 0;
   out_475664012759985504[79] = 0;
   out_475664012759985504[80] = 0;
   out_475664012759985504[81] = 0;
   out_475664012759985504[82] = 0;
   out_475664012759985504[83] = 0;
   out_475664012759985504[84] = 1.0;
   out_475664012759985504[85] = 0;
   out_475664012759985504[86] = 0;
   out_475664012759985504[87] = 0;
   out_475664012759985504[88] = 0;
   out_475664012759985504[89] = 0;
   out_475664012759985504[90] = 0;
   out_475664012759985504[91] = 0;
   out_475664012759985504[92] = 0;
   out_475664012759985504[93] = 0;
   out_475664012759985504[94] = 0;
   out_475664012759985504[95] = 0;
   out_475664012759985504[96] = 1.0;
   out_475664012759985504[97] = 0;
   out_475664012759985504[98] = 0;
   out_475664012759985504[99] = 0;
   out_475664012759985504[100] = 0;
   out_475664012759985504[101] = 0;
   out_475664012759985504[102] = 0;
   out_475664012759985504[103] = 0;
   out_475664012759985504[104] = 0;
   out_475664012759985504[105] = 0;
   out_475664012759985504[106] = 0;
   out_475664012759985504[107] = 0;
   out_475664012759985504[108] = 1.0;
   out_475664012759985504[109] = 0;
   out_475664012759985504[110] = 0;
   out_475664012759985504[111] = 0;
   out_475664012759985504[112] = 0;
   out_475664012759985504[113] = 0;
   out_475664012759985504[114] = 0;
   out_475664012759985504[115] = 0;
   out_475664012759985504[116] = 0;
   out_475664012759985504[117] = 0;
   out_475664012759985504[118] = 0;
   out_475664012759985504[119] = 0;
   out_475664012759985504[120] = 1.0;
}
void f_fun(double *state, double dt, double *out_4292385048460003663) {
   out_4292385048460003663[0] = dt*state[3] + state[0];
   out_4292385048460003663[1] = dt*state[4] + state[1];
   out_4292385048460003663[2] = dt*state[5] + state[2];
   out_4292385048460003663[3] = state[3];
   out_4292385048460003663[4] = state[4];
   out_4292385048460003663[5] = state[5];
   out_4292385048460003663[6] = dt*state[7] + state[6];
   out_4292385048460003663[7] = dt*state[8] + state[7];
   out_4292385048460003663[8] = state[8];
   out_4292385048460003663[9] = state[9];
   out_4292385048460003663[10] = state[10];
}
void F_fun(double *state, double dt, double *out_7071174528671579157) {
   out_7071174528671579157[0] = 1;
   out_7071174528671579157[1] = 0;
   out_7071174528671579157[2] = 0;
   out_7071174528671579157[3] = dt;
   out_7071174528671579157[4] = 0;
   out_7071174528671579157[5] = 0;
   out_7071174528671579157[6] = 0;
   out_7071174528671579157[7] = 0;
   out_7071174528671579157[8] = 0;
   out_7071174528671579157[9] = 0;
   out_7071174528671579157[10] = 0;
   out_7071174528671579157[11] = 0;
   out_7071174528671579157[12] = 1;
   out_7071174528671579157[13] = 0;
   out_7071174528671579157[14] = 0;
   out_7071174528671579157[15] = dt;
   out_7071174528671579157[16] = 0;
   out_7071174528671579157[17] = 0;
   out_7071174528671579157[18] = 0;
   out_7071174528671579157[19] = 0;
   out_7071174528671579157[20] = 0;
   out_7071174528671579157[21] = 0;
   out_7071174528671579157[22] = 0;
   out_7071174528671579157[23] = 0;
   out_7071174528671579157[24] = 1;
   out_7071174528671579157[25] = 0;
   out_7071174528671579157[26] = 0;
   out_7071174528671579157[27] = dt;
   out_7071174528671579157[28] = 0;
   out_7071174528671579157[29] = 0;
   out_7071174528671579157[30] = 0;
   out_7071174528671579157[31] = 0;
   out_7071174528671579157[32] = 0;
   out_7071174528671579157[33] = 0;
   out_7071174528671579157[34] = 0;
   out_7071174528671579157[35] = 0;
   out_7071174528671579157[36] = 1;
   out_7071174528671579157[37] = 0;
   out_7071174528671579157[38] = 0;
   out_7071174528671579157[39] = 0;
   out_7071174528671579157[40] = 0;
   out_7071174528671579157[41] = 0;
   out_7071174528671579157[42] = 0;
   out_7071174528671579157[43] = 0;
   out_7071174528671579157[44] = 0;
   out_7071174528671579157[45] = 0;
   out_7071174528671579157[46] = 0;
   out_7071174528671579157[47] = 0;
   out_7071174528671579157[48] = 1;
   out_7071174528671579157[49] = 0;
   out_7071174528671579157[50] = 0;
   out_7071174528671579157[51] = 0;
   out_7071174528671579157[52] = 0;
   out_7071174528671579157[53] = 0;
   out_7071174528671579157[54] = 0;
   out_7071174528671579157[55] = 0;
   out_7071174528671579157[56] = 0;
   out_7071174528671579157[57] = 0;
   out_7071174528671579157[58] = 0;
   out_7071174528671579157[59] = 0;
   out_7071174528671579157[60] = 1;
   out_7071174528671579157[61] = 0;
   out_7071174528671579157[62] = 0;
   out_7071174528671579157[63] = 0;
   out_7071174528671579157[64] = 0;
   out_7071174528671579157[65] = 0;
   out_7071174528671579157[66] = 0;
   out_7071174528671579157[67] = 0;
   out_7071174528671579157[68] = 0;
   out_7071174528671579157[69] = 0;
   out_7071174528671579157[70] = 0;
   out_7071174528671579157[71] = 0;
   out_7071174528671579157[72] = 1;
   out_7071174528671579157[73] = dt;
   out_7071174528671579157[74] = 0;
   out_7071174528671579157[75] = 0;
   out_7071174528671579157[76] = 0;
   out_7071174528671579157[77] = 0;
   out_7071174528671579157[78] = 0;
   out_7071174528671579157[79] = 0;
   out_7071174528671579157[80] = 0;
   out_7071174528671579157[81] = 0;
   out_7071174528671579157[82] = 0;
   out_7071174528671579157[83] = 0;
   out_7071174528671579157[84] = 1;
   out_7071174528671579157[85] = dt;
   out_7071174528671579157[86] = 0;
   out_7071174528671579157[87] = 0;
   out_7071174528671579157[88] = 0;
   out_7071174528671579157[89] = 0;
   out_7071174528671579157[90] = 0;
   out_7071174528671579157[91] = 0;
   out_7071174528671579157[92] = 0;
   out_7071174528671579157[93] = 0;
   out_7071174528671579157[94] = 0;
   out_7071174528671579157[95] = 0;
   out_7071174528671579157[96] = 1;
   out_7071174528671579157[97] = 0;
   out_7071174528671579157[98] = 0;
   out_7071174528671579157[99] = 0;
   out_7071174528671579157[100] = 0;
   out_7071174528671579157[101] = 0;
   out_7071174528671579157[102] = 0;
   out_7071174528671579157[103] = 0;
   out_7071174528671579157[104] = 0;
   out_7071174528671579157[105] = 0;
   out_7071174528671579157[106] = 0;
   out_7071174528671579157[107] = 0;
   out_7071174528671579157[108] = 1;
   out_7071174528671579157[109] = 0;
   out_7071174528671579157[110] = 0;
   out_7071174528671579157[111] = 0;
   out_7071174528671579157[112] = 0;
   out_7071174528671579157[113] = 0;
   out_7071174528671579157[114] = 0;
   out_7071174528671579157[115] = 0;
   out_7071174528671579157[116] = 0;
   out_7071174528671579157[117] = 0;
   out_7071174528671579157[118] = 0;
   out_7071174528671579157[119] = 0;
   out_7071174528671579157[120] = 1;
}
void h_6(double *state, double *sat_pos, double *out_2481230479465319936) {
   out_2481230479465319936[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + state[6];
}
void H_6(double *state, double *sat_pos, double *out_7645196925630164082) {
   out_7645196925630164082[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_7645196925630164082[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_7645196925630164082[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_7645196925630164082[3] = 0;
   out_7645196925630164082[4] = 0;
   out_7645196925630164082[5] = 0;
   out_7645196925630164082[6] = 1;
   out_7645196925630164082[7] = 0;
   out_7645196925630164082[8] = 0;
   out_7645196925630164082[9] = 0;
   out_7645196925630164082[10] = 0;
}
void h_20(double *state, double *sat_pos, double *out_7507301208942135576) {
   out_7507301208942135576[0] = sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2)) + sat_pos[3]*state[10] + state[6] + state[9];
}
void H_20(double *state, double *sat_pos, double *out_1693366137112332184) {
   out_1693366137112332184[0] = (-sat_pos[0] + state[0])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_1693366137112332184[1] = (-sat_pos[1] + state[1])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_1693366137112332184[2] = (-sat_pos[2] + state[2])/sqrt(pow(-sat_pos[0] + state[0], 2) + pow(-sat_pos[1] + state[1], 2) + pow(-sat_pos[2] + state[2], 2));
   out_1693366137112332184[3] = 0;
   out_1693366137112332184[4] = 0;
   out_1693366137112332184[5] = 0;
   out_1693366137112332184[6] = 1;
   out_1693366137112332184[7] = 0;
   out_1693366137112332184[8] = 0;
   out_1693366137112332184[9] = 1;
   out_1693366137112332184[10] = sat_pos[3];
}
void h_7(double *state, double *sat_pos_vel, double *out_2861812996390348550) {
   out_2861812996390348550[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_7(double *state, double *sat_pos_vel, double *out_1823365369839474784) {
   out_1823365369839474784[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1823365369839474784[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1823365369839474784[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1823365369839474784[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1823365369839474784[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1823365369839474784[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1823365369839474784[6] = 0;
   out_1823365369839474784[7] = 1;
   out_1823365369839474784[8] = 0;
   out_1823365369839474784[9] = 0;
   out_1823365369839474784[10] = 0;
}
void h_21(double *state, double *sat_pos_vel, double *out_2861812996390348550) {
   out_2861812996390348550[0] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + (sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2)) + state[7];
}
void H_21(double *state, double *sat_pos_vel, double *out_1823365369839474784) {
   out_1823365369839474784[0] = pow(sat_pos_vel[0] - state[0], 2)*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[3] - state[3])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1823365369839474784[1] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[1] - state[1])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[1] - state[1], 2)*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[4] - state[4])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1823365369839474784[2] = (sat_pos_vel[0] - state[0])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[3] - state[3])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + (sat_pos_vel[1] - state[1])*(sat_pos_vel[2] - state[2])*(sat_pos_vel[4] - state[4])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) + pow(sat_pos_vel[2] - state[2], 2)*(sat_pos_vel[5] - state[5])/pow(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2), 3.0/2.0) - (sat_pos_vel[5] - state[5])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1823365369839474784[3] = -(sat_pos_vel[0] - state[0])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1823365369839474784[4] = -(sat_pos_vel[1] - state[1])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1823365369839474784[5] = -(sat_pos_vel[2] - state[2])/sqrt(pow(sat_pos_vel[0] - state[0], 2) + pow(sat_pos_vel[1] - state[1], 2) + pow(sat_pos_vel[2] - state[2], 2));
   out_1823365369839474784[6] = 0;
   out_1823365369839474784[7] = 1;
   out_1823365369839474784[8] = 0;
   out_1823365369839474784[9] = 0;
   out_1823365369839474784[10] = 0;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void gnss_update_6(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_6, H_6, NULL, in_z, in_R, in_ea, MAHA_THRESH_6);
}
void gnss_update_20(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_20, H_20, NULL, in_z, in_R, in_ea, MAHA_THRESH_20);
}
void gnss_update_7(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_7, H_7, NULL, in_z, in_R, in_ea, MAHA_THRESH_7);
}
void gnss_update_21(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_21, H_21, NULL, in_z, in_R, in_ea, MAHA_THRESH_21);
}
void gnss_err_fun(double *nom_x, double *delta_x, double *out_7861368562585023949) {
  err_fun(nom_x, delta_x, out_7861368562585023949);
}
void gnss_inv_err_fun(double *nom_x, double *true_x, double *out_6509090499931839816) {
  inv_err_fun(nom_x, true_x, out_6509090499931839816);
}
void gnss_H_mod_fun(double *state, double *out_475664012759985504) {
  H_mod_fun(state, out_475664012759985504);
}
void gnss_f_fun(double *state, double dt, double *out_4292385048460003663) {
  f_fun(state,  dt, out_4292385048460003663);
}
void gnss_F_fun(double *state, double dt, double *out_7071174528671579157) {
  F_fun(state,  dt, out_7071174528671579157);
}
void gnss_h_6(double *state, double *sat_pos, double *out_2481230479465319936) {
  h_6(state, sat_pos, out_2481230479465319936);
}
void gnss_H_6(double *state, double *sat_pos, double *out_7645196925630164082) {
  H_6(state, sat_pos, out_7645196925630164082);
}
void gnss_h_20(double *state, double *sat_pos, double *out_7507301208942135576) {
  h_20(state, sat_pos, out_7507301208942135576);
}
void gnss_H_20(double *state, double *sat_pos, double *out_1693366137112332184) {
  H_20(state, sat_pos, out_1693366137112332184);
}
void gnss_h_7(double *state, double *sat_pos_vel, double *out_2861812996390348550) {
  h_7(state, sat_pos_vel, out_2861812996390348550);
}
void gnss_H_7(double *state, double *sat_pos_vel, double *out_1823365369839474784) {
  H_7(state, sat_pos_vel, out_1823365369839474784);
}
void gnss_h_21(double *state, double *sat_pos_vel, double *out_2861812996390348550) {
  h_21(state, sat_pos_vel, out_2861812996390348550);
}
void gnss_H_21(double *state, double *sat_pos_vel, double *out_1823365369839474784) {
  H_21(state, sat_pos_vel, out_1823365369839474784);
}
void gnss_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
}

const EKF gnss = {
  .name = "gnss",
  .kinds = { 6, 20, 7, 21 },
  .feature_kinds = {  },
  .f_fun = gnss_f_fun,
  .F_fun = gnss_F_fun,
  .err_fun = gnss_err_fun,
  .inv_err_fun = gnss_inv_err_fun,
  .H_mod_fun = gnss_H_mod_fun,
  .predict = gnss_predict,
  .hs = {
    { 6, gnss_h_6 },
    { 20, gnss_h_20 },
    { 7, gnss_h_7 },
    { 21, gnss_h_21 },
  },
  .Hs = {
    { 6, gnss_H_6 },
    { 20, gnss_H_20 },
    { 7, gnss_H_7 },
    { 21, gnss_H_21 },
  },
  .updates = {
    { 6, gnss_update_6 },
    { 20, gnss_update_20 },
    { 7, gnss_update_7 },
    { 21, gnss_update_21 },
  },
  .Hes = {
  },
  .sets = {
  },
  .extra_routines = {
  },
};

ekf_init(gnss);
