#include "scramble_sim.h"

frame str_to_frame(string signal)
{
  frame _frame = 0;
    
  for (int index(0); index <= 127; index++)
    if (signal[127-index] == '1')
      _frame[index] = 1;
    
  return _frame;
}

spp frame_to_spp(frame frame_in, int spp_no)
{
  spp temp;

  for (int i(0); i < 30; i++)
    temp[i] = frame_in[30*spp_no + i];
    
  return temp;
}

frame attach_spp_to_frame(frame frame_in, spp attachment, int spp_no)
{
  frame frame_out;

  frame_out = frame_in;
  // for (int i(0); i < 8; i++)
  //frame_out[120+i] = frame_in[120+i];
  
  for (int i(0); i < 30; i++)
    frame_out[30*spp_no+i] = attachment[i];

  return frame_out;
}

spp Karol_scramble_TX(spp TX_DATA_IN, int i)
{
  static spp TX_FEEDBACK [4] = {0,0,0,0};
  spp TX_DATA_OUT(0);
    
  TX_DATA_OUT[ 0] = TX_DATA_IN[ 0] ^ TX_FEEDBACK[i][ 0] ^ TX_FEEDBACK[i][ 2];
  TX_DATA_OUT[ 1] = TX_DATA_IN[ 1] ^ TX_FEEDBACK[i][ 1] ^ TX_FEEDBACK[i][ 3];
  TX_DATA_OUT[ 2] = TX_DATA_IN[ 2] ^ TX_FEEDBACK[i][ 2] ^ TX_FEEDBACK[i][ 4];
  TX_DATA_OUT[ 3] = TX_DATA_IN[ 3] ^ TX_FEEDBACK[i][ 3] ^ TX_FEEDBACK[i][ 5];
  TX_DATA_OUT[ 4] = TX_DATA_IN[ 4] ^ TX_FEEDBACK[i][ 4] ^ TX_FEEDBACK[i][ 6];
  TX_DATA_OUT[ 5] = TX_DATA_IN[ 5] ^ TX_FEEDBACK[i][ 5] ^ TX_FEEDBACK[i][ 7];
  TX_DATA_OUT[ 6] = TX_DATA_IN[ 6] ^ TX_FEEDBACK[i][ 6] ^ TX_FEEDBACK[i][ 8];
  TX_DATA_OUT[ 7] = TX_DATA_IN[ 7] ^ TX_FEEDBACK[i][ 7] ^ TX_FEEDBACK[i][ 9];
  TX_DATA_OUT[ 8] = TX_DATA_IN[ 8] ^ TX_FEEDBACK[i][ 8] ^ TX_FEEDBACK[i][10];
  TX_DATA_OUT[ 9] = TX_DATA_IN[ 9] ^ TX_FEEDBACK[i][ 9] ^ TX_FEEDBACK[i][11];
  TX_DATA_OUT[10] = TX_DATA_IN[10] ^ TX_FEEDBACK[i][10] ^ TX_FEEDBACK[i][12];
  TX_DATA_OUT[11] = TX_DATA_IN[11] ^ TX_FEEDBACK[i][11] ^ TX_FEEDBACK[i][13];
  TX_DATA_OUT[12] = TX_DATA_IN[12] ^ TX_FEEDBACK[i][12] ^ TX_FEEDBACK[i][14];
  TX_DATA_OUT[13] = TX_DATA_IN[13] ^ TX_FEEDBACK[i][13] ^ TX_FEEDBACK[i][15];
  TX_DATA_OUT[14] = TX_DATA_IN[14] ^ TX_FEEDBACK[i][14] ^ TX_FEEDBACK[i][16];
  TX_DATA_OUT[15] = TX_DATA_IN[15] ^ TX_FEEDBACK[i][15] ^ TX_FEEDBACK[i][17];
  TX_DATA_OUT[16] = TX_DATA_IN[16] ^ TX_FEEDBACK[i][16] ^ TX_FEEDBACK[i][18];
  TX_DATA_OUT[17] = TX_DATA_IN[17] ^ TX_FEEDBACK[i][17] ^ TX_FEEDBACK[i][19];
  TX_DATA_OUT[18] = TX_DATA_IN[18] ^ TX_FEEDBACK[i][18] ^ TX_FEEDBACK[i][20];
  TX_DATA_OUT[19] = TX_DATA_IN[19] ^ TX_FEEDBACK[i][19] ^ TX_FEEDBACK[i][21];
  TX_DATA_OUT[20] = TX_DATA_IN[20] ^ TX_FEEDBACK[i][20] ^ TX_FEEDBACK[i][22];
  TX_DATA_OUT[21] = TX_DATA_IN[21] ^ TX_FEEDBACK[i][21] ^ TX_FEEDBACK[i][23];
  TX_DATA_OUT[22] = TX_DATA_IN[22] ^ TX_FEEDBACK[i][22] ^ TX_FEEDBACK[i][24];
  TX_DATA_OUT[23] = TX_DATA_IN[23] ^ TX_FEEDBACK[i][23] ^ TX_FEEDBACK[i][25];
  TX_DATA_OUT[24] = TX_DATA_IN[24] ^ TX_FEEDBACK[i][24] ^ TX_FEEDBACK[i][26];
  TX_DATA_OUT[25] = TX_DATA_IN[25] ^ TX_FEEDBACK[i][25] ^ TX_FEEDBACK[i][27];
  TX_DATA_OUT[26] = TX_DATA_IN[26] ^ TX_FEEDBACK[i][26] ^ TX_FEEDBACK[i][28];
  TX_DATA_OUT[27] = TX_DATA_IN[27] ^ TX_FEEDBACK[i][27] ^ TX_FEEDBACK[i][29];
  TX_DATA_OUT[28] = TX_DATA_IN[28] ^ TX_FEEDBACK[i][28] ^ TX_DATA_IN   [ 0] ^ TX_FEEDBACK[i][0] ^ TX_FEEDBACK[i][2];
  TX_DATA_OUT[29] = TX_DATA_IN[29] ^ TX_FEEDBACK[i][29] ^ TX_DATA_IN   [ 1] ^ TX_FEEDBACK[i][1] ^ TX_FEEDBACK[i][3];
    
  TX_FEEDBACK[i] = TX_DATA_OUT;

  return TX_DATA_OUT; //COMMON_FRAME
}

spp Karol_scramble_RX(spp RX_DATA_IN, int i)
{
  static spp RX_FEEDBACK [4] = {0,0,0,0};
  spp RX_DATA_OUT(0);
    
  RX_DATA_OUT[ 0] = RX_DATA_IN[ 0] ^ RX_FEEDBACK[i][ 0] ^ RX_FEEDBACK[i] [ 2];
  RX_DATA_OUT[ 1] = RX_DATA_IN[ 1] ^ RX_FEEDBACK[i][ 1] ^ RX_FEEDBACK[i] [ 3];
  RX_DATA_OUT[ 2] = RX_DATA_IN[ 2] ^ RX_FEEDBACK[i][ 2] ^ RX_FEEDBACK[i] [ 4];
  RX_DATA_OUT[ 3] = RX_DATA_IN[ 3] ^ RX_FEEDBACK[i][ 3] ^ RX_FEEDBACK[i] [ 5];
  RX_DATA_OUT[ 4] = RX_DATA_IN[ 4] ^ RX_FEEDBACK[i][ 4] ^ RX_FEEDBACK[i] [ 6];
  RX_DATA_OUT[ 5] = RX_DATA_IN[ 5] ^ RX_FEEDBACK[i][ 5] ^ RX_FEEDBACK[i] [ 7];
  RX_DATA_OUT[ 6] = RX_DATA_IN[ 6] ^ RX_FEEDBACK[i][ 6] ^ RX_FEEDBACK[i] [ 8];
  RX_DATA_OUT[ 7] = RX_DATA_IN[ 7] ^ RX_FEEDBACK[i][ 7] ^ RX_FEEDBACK[i] [ 9];
  RX_DATA_OUT[ 8] = RX_DATA_IN[ 8] ^ RX_FEEDBACK[i][ 8] ^ RX_FEEDBACK[i] [10];
  RX_DATA_OUT[ 9] = RX_DATA_IN[ 9] ^ RX_FEEDBACK[i][ 9] ^ RX_FEEDBACK[i] [11];
  RX_DATA_OUT[10] = RX_DATA_IN[10] ^ RX_FEEDBACK[i][10] ^ RX_FEEDBACK[i] [12];
  RX_DATA_OUT[11] = RX_DATA_IN[11] ^ RX_FEEDBACK[i][11] ^ RX_FEEDBACK[i] [13];
  RX_DATA_OUT[12] = RX_DATA_IN[12] ^ RX_FEEDBACK[i][12] ^ RX_FEEDBACK[i] [14];
  RX_DATA_OUT[13] = RX_DATA_IN[13] ^ RX_FEEDBACK[i][13] ^ RX_FEEDBACK[i] [15];
  RX_DATA_OUT[14] = RX_DATA_IN[14] ^ RX_FEEDBACK[i][14] ^ RX_FEEDBACK[i] [16];
  RX_DATA_OUT[15] = RX_DATA_IN[15] ^ RX_FEEDBACK[i][15] ^ RX_FEEDBACK[i] [17];
  RX_DATA_OUT[16] = RX_DATA_IN[16] ^ RX_FEEDBACK[i][16] ^ RX_FEEDBACK[i] [18];
  RX_DATA_OUT[17] = RX_DATA_IN[17] ^ RX_FEEDBACK[i][17] ^ RX_FEEDBACK[i] [19];
  RX_DATA_OUT[18] = RX_DATA_IN[18] ^ RX_FEEDBACK[i][18] ^ RX_FEEDBACK[i] [20];
  RX_DATA_OUT[19] = RX_DATA_IN[19] ^ RX_FEEDBACK[i][19] ^ RX_FEEDBACK[i] [21];
  RX_DATA_OUT[20] = RX_DATA_IN[20] ^ RX_FEEDBACK[i][20] ^ RX_FEEDBACK[i] [22];
  RX_DATA_OUT[21] = RX_DATA_IN[21] ^ RX_FEEDBACK[i][21] ^ RX_FEEDBACK[i] [23];
  RX_DATA_OUT[22] = RX_DATA_IN[22] ^ RX_FEEDBACK[i][22] ^ RX_FEEDBACK[i] [24];
  RX_DATA_OUT[23] = RX_DATA_IN[23] ^ RX_FEEDBACK[i][23] ^ RX_FEEDBACK[i] [25];
  RX_DATA_OUT[24] = RX_DATA_IN[24] ^ RX_FEEDBACK[i][24] ^ RX_FEEDBACK[i] [26];
  RX_DATA_OUT[25] = RX_DATA_IN[25] ^ RX_FEEDBACK[i][25] ^ RX_FEEDBACK[i] [27];
  RX_DATA_OUT[26] = RX_DATA_IN[26] ^ RX_FEEDBACK[i][26] ^ RX_FEEDBACK[i] [28];
  RX_DATA_OUT[27] = RX_DATA_IN[27] ^ RX_FEEDBACK[i][27] ^ RX_FEEDBACK[i] [29];
  RX_DATA_OUT[28] = RX_DATA_IN[28] ^ RX_FEEDBACK[i][28] ^ RX_DATA_IN[ 0];
  RX_DATA_OUT[29] = RX_DATA_IN[29] ^ RX_FEEDBACK[i][29] ^ RX_DATA_IN[ 1];
    
  RX_FEEDBACK[i] = RX_DATA_IN;
    
  return RX_DATA_OUT;
}

spp  additive_scramble_TX(spp DATA_IN, int i)
{
  static spp COMMON_FRAME_1_TX [4] = {7,7,7,7};
  static spp COMMON_FRAME_2_TX [4] = {0,0,0,0};
  spp DATA_OUT(0);

  COMMON_FRAME_2_TX[i][0 ] = COMMON_FRAME_1_TX[i][0 ] ^ COMMON_FRAME_1_TX[i][29];
  COMMON_FRAME_2_TX[i][1 ] = COMMON_FRAME_1_TX[i][0 ] ^ COMMON_FRAME_1_TX[i][1 ] ^ COMMON_FRAME_1_TX[i][29];
  COMMON_FRAME_2_TX[i][2 ] = COMMON_FRAME_1_TX[i][1 ] ^ COMMON_FRAME_1_TX[i][2 ];
  COMMON_FRAME_2_TX[i][3 ] = COMMON_FRAME_1_TX[i][2 ] ^ COMMON_FRAME_1_TX[i][3 ];
  COMMON_FRAME_2_TX[i][4 ] = COMMON_FRAME_1_TX[i][3 ] ^ COMMON_FRAME_1_TX[i][4 ];
  COMMON_FRAME_2_TX[i][5 ] = COMMON_FRAME_1_TX[i][4 ] ^ COMMON_FRAME_1_TX[i][5 ];
  COMMON_FRAME_2_TX[i][6 ] = COMMON_FRAME_1_TX[i][5 ] ^ COMMON_FRAME_1_TX[i][6 ];
  COMMON_FRAME_2_TX[i][7 ] = COMMON_FRAME_1_TX[i][6 ] ^ COMMON_FRAME_1_TX[i][7 ];
  COMMON_FRAME_2_TX[i][8 ] = COMMON_FRAME_1_TX[i][7 ] ^ COMMON_FRAME_1_TX[i][8 ];
  COMMON_FRAME_2_TX[i][9 ] = COMMON_FRAME_1_TX[i][8 ] ^ COMMON_FRAME_1_TX[i][9 ];
  COMMON_FRAME_2_TX[i][10] = COMMON_FRAME_1_TX[i][9 ] ^ COMMON_FRAME_1_TX[i][10];
  COMMON_FRAME_2_TX[i][11] = COMMON_FRAME_1_TX[i][10] ^ COMMON_FRAME_1_TX[i][11];
  COMMON_FRAME_2_TX[i][12] = COMMON_FRAME_1_TX[i][11] ^ COMMON_FRAME_1_TX[i][12];
  COMMON_FRAME_2_TX[i][13] = COMMON_FRAME_1_TX[i][12] ^ COMMON_FRAME_1_TX[i][13];
  COMMON_FRAME_2_TX[i][14] = COMMON_FRAME_1_TX[i][13] ^ COMMON_FRAME_1_TX[i][14];
  COMMON_FRAME_2_TX[i][15] = COMMON_FRAME_1_TX[i][14] ^ COMMON_FRAME_1_TX[i][15];
  COMMON_FRAME_2_TX[i][16] = COMMON_FRAME_1_TX[i][15] ^ COMMON_FRAME_1_TX[i][16];
  COMMON_FRAME_2_TX[i][17] = COMMON_FRAME_1_TX[i][16] ^ COMMON_FRAME_1_TX[i][17];
  COMMON_FRAME_2_TX[i][18] = COMMON_FRAME_1_TX[i][17] ^ COMMON_FRAME_1_TX[i][18];
  COMMON_FRAME_2_TX[i][19] = COMMON_FRAME_1_TX[i][18] ^ COMMON_FRAME_1_TX[i][19];
  COMMON_FRAME_2_TX[i][20] = COMMON_FRAME_1_TX[i][19] ^ COMMON_FRAME_1_TX[i][20];
  COMMON_FRAME_2_TX[i][21] = COMMON_FRAME_1_TX[i][20] ^ COMMON_FRAME_1_TX[i][21];
  COMMON_FRAME_2_TX[i][22] = COMMON_FRAME_1_TX[i][21] ^ COMMON_FRAME_1_TX[i][22];
  COMMON_FRAME_2_TX[i][23] = COMMON_FRAME_1_TX[i][22] ^ COMMON_FRAME_1_TX[i][23];
  COMMON_FRAME_2_TX[i][24] = COMMON_FRAME_1_TX[i][23] ^ COMMON_FRAME_1_TX[i][24];
  COMMON_FRAME_2_TX[i][25] = COMMON_FRAME_1_TX[i][24] ^ COMMON_FRAME_1_TX[i][25];
  COMMON_FRAME_2_TX[i][26] = COMMON_FRAME_1_TX[i][25] ^ COMMON_FRAME_1_TX[i][26];
  COMMON_FRAME_2_TX[i][27] = COMMON_FRAME_1_TX[i][26] ^ COMMON_FRAME_1_TX[i][27];
  COMMON_FRAME_2_TX[i][28] = COMMON_FRAME_1_TX[i][27] ^ COMMON_FRAME_1_TX[i][28];
  COMMON_FRAME_2_TX[i][29] = COMMON_FRAME_1_TX[i][28] ^ COMMON_FRAME_1_TX[i][29];
  DATA_OUT[0 ] = DATA_IN[0 ] ^ COMMON_FRAME_1_TX[i][29];
  DATA_OUT[1 ] = DATA_IN[1 ] ^ COMMON_FRAME_1_TX[i][28];
  DATA_OUT[2 ] = DATA_IN[2 ] ^ COMMON_FRAME_1_TX[i][27];
  DATA_OUT[3 ] = DATA_IN[3 ] ^ COMMON_FRAME_1_TX[i][26];
  DATA_OUT[4 ] = DATA_IN[4 ] ^ COMMON_FRAME_1_TX[i][25];
  DATA_OUT[5 ] = DATA_IN[5 ] ^ COMMON_FRAME_1_TX[i][24];
  DATA_OUT[6 ] = DATA_IN[6 ] ^ COMMON_FRAME_1_TX[i][23];
  DATA_OUT[7 ] = DATA_IN[7 ] ^ COMMON_FRAME_1_TX[i][22];
  DATA_OUT[8 ] = DATA_IN[8 ] ^ COMMON_FRAME_1_TX[i][21];
  DATA_OUT[9 ] = DATA_IN[9 ] ^ COMMON_FRAME_1_TX[i][20];
  DATA_OUT[10] = DATA_IN[10] ^ COMMON_FRAME_1_TX[i][19];
  DATA_OUT[11] = DATA_IN[11] ^ COMMON_FRAME_1_TX[i][18];
  DATA_OUT[12] = DATA_IN[12] ^ COMMON_FRAME_1_TX[i][17];
  DATA_OUT[13] = DATA_IN[13] ^ COMMON_FRAME_1_TX[i][16];
  DATA_OUT[14] = DATA_IN[14] ^ COMMON_FRAME_1_TX[i][15];
  DATA_OUT[15] = DATA_IN[15] ^ COMMON_FRAME_1_TX[i][14];
  DATA_OUT[16] = DATA_IN[16] ^ COMMON_FRAME_1_TX[i][13];
  DATA_OUT[17] = DATA_IN[17] ^ COMMON_FRAME_1_TX[i][12];
  DATA_OUT[18] = DATA_IN[18] ^ COMMON_FRAME_1_TX[i][11];
  DATA_OUT[19] = DATA_IN[19] ^ COMMON_FRAME_1_TX[i][10];
  DATA_OUT[20] = DATA_IN[20] ^ COMMON_FRAME_1_TX[i][9 ];
  DATA_OUT[21] = DATA_IN[21] ^ COMMON_FRAME_1_TX[i][8 ];
  DATA_OUT[22] = DATA_IN[22] ^ COMMON_FRAME_1_TX[i][7 ];
  DATA_OUT[23] = DATA_IN[23] ^ COMMON_FRAME_1_TX[i][6 ];
  DATA_OUT[24] = DATA_IN[24] ^ COMMON_FRAME_1_TX[i][5 ];
  DATA_OUT[25] = DATA_IN[25] ^ COMMON_FRAME_1_TX[i][4 ];
  DATA_OUT[26] = DATA_IN[26] ^ COMMON_FRAME_1_TX[i][3 ];
  DATA_OUT[27] = DATA_IN[27] ^ COMMON_FRAME_1_TX[i][2 ];
  DATA_OUT[28] = DATA_IN[28] ^ COMMON_FRAME_1_TX[i][1 ];
  DATA_OUT[29] = DATA_IN[29] ^ COMMON_FRAME_1_TX[i][0 ] ^ COMMON_FRAME_1_TX[i][29 ];

  COMMON_FRAME_1_TX[i] = COMMON_FRAME_2_TX[i];

  return DATA_OUT;
}

spp  additive_scramble_RX(spp DATA_IN, int i)
{
  static spp COMMON_FRAME_1_RX [4] = {7,7,7,7};
  static spp COMMON_FRAME_2_RX [4] = {0,0,0,0};
    
  spp DATA_OUT(0);
    
  COMMON_FRAME_2_RX[i][0 ] = COMMON_FRAME_1_RX[i][0 ] ^ COMMON_FRAME_1_RX[i][29];
  COMMON_FRAME_2_RX[i][1 ] = COMMON_FRAME_1_RX[i][0 ] ^ COMMON_FRAME_1_RX[i][1 ] ^ COMMON_FRAME_1_RX[i][29];
  COMMON_FRAME_2_RX[i][2 ] = COMMON_FRAME_1_RX[i][1 ] ^ COMMON_FRAME_1_RX[i][2 ];
  COMMON_FRAME_2_RX[i][3 ] = COMMON_FRAME_1_RX[i][2 ] ^ COMMON_FRAME_1_RX[i][3 ];
  COMMON_FRAME_2_RX[i][4 ] = COMMON_FRAME_1_RX[i][3 ] ^ COMMON_FRAME_1_RX[i][4 ];
  COMMON_FRAME_2_RX[i][5 ] = COMMON_FRAME_1_RX[i][4 ] ^ COMMON_FRAME_1_RX[i][5 ];
  COMMON_FRAME_2_RX[i][6 ] = COMMON_FRAME_1_RX[i][5 ] ^ COMMON_FRAME_1_RX[i][6 ];
  COMMON_FRAME_2_RX[i][7 ] = COMMON_FRAME_1_RX[i][6 ] ^ COMMON_FRAME_1_RX[i][7 ];
  COMMON_FRAME_2_RX[i][8 ] = COMMON_FRAME_1_RX[i][7 ] ^ COMMON_FRAME_1_RX[i][8 ];
  COMMON_FRAME_2_RX[i][9 ] = COMMON_FRAME_1_RX[i][8 ] ^ COMMON_FRAME_1_RX[i][9 ];
  COMMON_FRAME_2_RX[i][10] = COMMON_FRAME_1_RX[i][9 ] ^ COMMON_FRAME_1_RX[i][10];
  COMMON_FRAME_2_RX[i][11] = COMMON_FRAME_1_RX[i][10] ^ COMMON_FRAME_1_RX[i][11];
  COMMON_FRAME_2_RX[i][12] = COMMON_FRAME_1_RX[i][11] ^ COMMON_FRAME_1_RX[i][12];
  COMMON_FRAME_2_RX[i][13] = COMMON_FRAME_1_RX[i][12] ^ COMMON_FRAME_1_RX[i][13];
  COMMON_FRAME_2_RX[i][14] = COMMON_FRAME_1_RX[i][13] ^ COMMON_FRAME_1_RX[i][14];
  COMMON_FRAME_2_RX[i][15] = COMMON_FRAME_1_RX[i][14] ^ COMMON_FRAME_1_RX[i][15];
  COMMON_FRAME_2_RX[i][16] = COMMON_FRAME_1_RX[i][15] ^ COMMON_FRAME_1_RX[i][16];
  COMMON_FRAME_2_RX[i][17] = COMMON_FRAME_1_RX[i][16] ^ COMMON_FRAME_1_RX[i][17];
  COMMON_FRAME_2_RX[i][18] = COMMON_FRAME_1_RX[i][17] ^ COMMON_FRAME_1_RX[i][18];
  COMMON_FRAME_2_RX[i][19] = COMMON_FRAME_1_RX[i][18] ^ COMMON_FRAME_1_RX[i][19];
  COMMON_FRAME_2_RX[i][20] = COMMON_FRAME_1_RX[i][19] ^ COMMON_FRAME_1_RX[i][20];
  COMMON_FRAME_2_RX[i][21] = COMMON_FRAME_1_RX[i][20] ^ COMMON_FRAME_1_RX[i][21];
  COMMON_FRAME_2_RX[i][22] = COMMON_FRAME_1_RX[i][21] ^ COMMON_FRAME_1_RX[i][22];
  COMMON_FRAME_2_RX[i][23] = COMMON_FRAME_1_RX[i][22] ^ COMMON_FRAME_1_RX[i][23];
  COMMON_FRAME_2_RX[i][24] = COMMON_FRAME_1_RX[i][23] ^ COMMON_FRAME_1_RX[i][24];
  COMMON_FRAME_2_RX[i][25] = COMMON_FRAME_1_RX[i][24] ^ COMMON_FRAME_1_RX[i][25];
  COMMON_FRAME_2_RX[i][26] = COMMON_FRAME_1_RX[i][25] ^ COMMON_FRAME_1_RX[i][26];
  COMMON_FRAME_2_RX[i][27] = COMMON_FRAME_1_RX[i][26] ^ COMMON_FRAME_1_RX[i][27];
  COMMON_FRAME_2_RX[i][28] = COMMON_FRAME_1_RX[i][27] ^ COMMON_FRAME_1_RX[i][28];
  COMMON_FRAME_2_RX[i][29] = COMMON_FRAME_1_RX[i][28] ^ COMMON_FRAME_1_RX[i][29];
  DATA_OUT[0 ] = DATA_IN[0 ] ^ COMMON_FRAME_1_RX[i][29];
  DATA_OUT[1 ] = DATA_IN[1 ] ^ COMMON_FRAME_1_RX[i][28];
  DATA_OUT[2 ] = DATA_IN[2 ] ^ COMMON_FRAME_1_RX[i][27];
  DATA_OUT[3 ] = DATA_IN[3 ] ^ COMMON_FRAME_1_RX[i][26];
  DATA_OUT[4 ] = DATA_IN[4 ] ^ COMMON_FRAME_1_RX[i][25];
  DATA_OUT[5 ] = DATA_IN[5 ] ^ COMMON_FRAME_1_RX[i][24];
  DATA_OUT[6 ] = DATA_IN[6 ] ^ COMMON_FRAME_1_RX[i][23];
  DATA_OUT[7 ] = DATA_IN[7 ] ^ COMMON_FRAME_1_RX[i][22];
  DATA_OUT[8 ] = DATA_IN[8 ] ^ COMMON_FRAME_1_RX[i][21];
  DATA_OUT[9 ] = DATA_IN[9 ] ^ COMMON_FRAME_1_RX[i][20];
  DATA_OUT[10] = DATA_IN[10] ^ COMMON_FRAME_1_RX[i][19];
  DATA_OUT[11] = DATA_IN[11] ^ COMMON_FRAME_1_RX[i][18];
  DATA_OUT[12] = DATA_IN[12] ^ COMMON_FRAME_1_RX[i][17];
  DATA_OUT[13] = DATA_IN[13] ^ COMMON_FRAME_1_RX[i][16];
  DATA_OUT[14] = DATA_IN[14] ^ COMMON_FRAME_1_RX[i][15];
  DATA_OUT[15] = DATA_IN[15] ^ COMMON_FRAME_1_RX[i][14];
  DATA_OUT[16] = DATA_IN[16] ^ COMMON_FRAME_1_RX[i][13];
  DATA_OUT[17] = DATA_IN[17] ^ COMMON_FRAME_1_RX[i][12];
  DATA_OUT[18] = DATA_IN[18] ^ COMMON_FRAME_1_RX[i][11];
  DATA_OUT[19] = DATA_IN[19] ^ COMMON_FRAME_1_RX[i][10];
  DATA_OUT[20] = DATA_IN[20] ^ COMMON_FRAME_1_RX[i][9 ];
  DATA_OUT[21] = DATA_IN[21] ^ COMMON_FRAME_1_RX[i][8 ];
  DATA_OUT[22] = DATA_IN[22] ^ COMMON_FRAME_1_RX[i][7 ];
  DATA_OUT[23] = DATA_IN[23] ^ COMMON_FRAME_1_RX[i][6 ];
  DATA_OUT[24] = DATA_IN[24] ^ COMMON_FRAME_1_RX[i][5 ];
  DATA_OUT[25] = DATA_IN[25] ^ COMMON_FRAME_1_RX[i][4 ];
  DATA_OUT[26] = DATA_IN[26] ^ COMMON_FRAME_1_RX[i][3 ];
  DATA_OUT[27] = DATA_IN[27] ^ COMMON_FRAME_1_RX[i][2 ];
  DATA_OUT[28] = DATA_IN[28] ^ COMMON_FRAME_1_RX[i][1 ];
  DATA_OUT[29] = DATA_IN[29] ^ COMMON_FRAME_1_RX[i][0 ] ^ COMMON_FRAME_1_RX[i][29 ];
    
  COMMON_FRAME_1_RX[i] = COMMON_FRAME_2_RX[i];
    
  return DATA_OUT;
}

spp VeloPix_scramble_TX(spp dataIn, int i)
{
  static spp state [4] = {7,7,7,7};
  static spp COMMON_FRAME_2_TX [4] = {0,0,0,0};
  spp nextState(0);
  spp dataOutEval(0);

  nextState[0] = dataIn[0] ^ state[i][0] ^ state[1] ^ state[15] ^ state[16];
  nextState[1] = dataIn[1] ^ state[1] ^ state[2] ^ state[16] ^ state[17];
  nextState[2] = dataIn[2] ^ state[2] ^ state[3] ^ state[17] ^ state[18];
  nextState[3] = dataIn[3] ^ state[3] ^ state[4] ^ state[18] ^ state[19];
  nextState[4] = dataIn[4] ^ state[4] ^ state[5] ^ state[19] ^ state[20];
  nextState[5] = dataIn[5] ^ state[5] ^ state[6] ^ state[20] ^ state[21];
  nextState[6] = dataIn[6] ^ state[6] ^ state[7] ^ state[21] ^ state[22];
  nextState[7] = dataIn[7] ^ state[7] ^ state[8] ^ state[22] ^ state[23];
  nextState[8] = dataIn[8] ^ state[8] ^ state[9] ^ state[23] ^ state[24];
  nextState[9] = dataIn[9] ^ state[9] ^ state[10] ^ state[24] ^ state[25];
  nextState[10] = dataIn[10] ^ state[10] ^ state[11] ^ state[25] ^ state[26];
  nextState[11] = dataIn[11] ^ state[11] ^ state[12] ^ state[26] ^ state[27];
  nextState[12] = dataIn[12] ^ state[12] ^ state[13] ^ state[27] ^ state[28];
  nextState[13] = dataIn[13] ^ state[13] ^ state[14] ^ state[28] ^ state[29];
  nextState[14] = dataIn[14] ^ state[14] ^ state[15] ^ state[29] ^ nextState[0];
  nextState[15] = dataIn[15] ^ state[15] ^ state[16] ^ nextState[0] ^ nextState[1];
  nextState[16] = dataIn[16] ^ state[16] ^ state[17] ^ nextState[1] ^ nextState[2];
  nextState[17] = dataIn[17] ^ state[17] ^ state[18] ^ nextState[2] ^ nextState[3];
  nextState[18] = dataIn[18] ^ state[18] ^ state[19] ^ nextState[3] ^ nextState[4];
  nextState[19] = dataIn[19] ^ state[19] ^ state[20] ^ nextState[4] ^ nextState[5];
  nextState[20] = dataIn[20] ^ state[20] ^ state[21] ^ nextState[5] ^ nextState[6];
  nextState[21] = dataIn[21] ^ state[21] ^ state[22] ^ nextState[6] ^ nextState[7];
  nextState[22] = dataIn[22] ^ state[22] ^ state[23] ^ nextState[7] ^ nextState[8];
  nextState[23] = dataIn[23] ^ state[23] ^ state[24] ^ nextState[8] ^ nextState[9];
  nextState[24] = dataIn[24] ^ state[24] ^ state[25] ^ nextState[9] ^ nextState[10];
  nextState[25] = dataIn[25] ^ state[25] ^ state[26] ^ nextState[10] ^ nextState[11];
  nextState[26] = dataIn[26] ^ state[26] ^ state[27] ^ nextState[11] ^ nextState[12];
  nextState[27] = dataIn[27] ^ state[27] ^ state[28] ^ nextState[12] ^ nextState[13];
  nextState[28] = dataIn[28] ^ state[28] ^ state[29] ^ nextState[13] ^ nextState[14];
  nextState[29] = dataIn[29] ^ state[29] ^ nextState[0] ^ nextState[14] ^ nextState[15];
  dataOutEval = nextState;

  return nextState;
}

spp  VeloPix_scramble_RX(spp DATA_IN, int i)
{
  static spp COMMON_FRAME_1_RX [4] = {7,7,7,7};
  static spp COMMON_FRAME_2_RX [4] = {0,0,0,0};
    
  spp DATA_OUT(0);
    
  COMMON_FRAME_2_RX[i][0 ] = COMMON_FRAME_1_RX[i][0 ] ^ COMMON_FRAME_1_RX[i][29];
  COMMON_FRAME_2_RX[i][1 ] = COMMON_FRAME_1_RX[i][0 ] ^ COMMON_FRAME_1_RX[i][1 ] ^ COMMON_FRAME_1_RX[i][29];
  COMMON_FRAME_2_RX[i][2 ] = COMMON_FRAME_1_RX[i][1 ] ^ COMMON_FRAME_1_RX[i][2 ];
  COMMON_FRAME_2_RX[i][3 ] = COMMON_FRAME_1_RX[i][2 ] ^ COMMON_FRAME_1_RX[i][3 ];
  COMMON_FRAME_2_RX[i][4 ] = COMMON_FRAME_1_RX[i][3 ] ^ COMMON_FRAME_1_RX[i][4 ];
  COMMON_FRAME_2_RX[i][5 ] = COMMON_FRAME_1_RX[i][4 ] ^ COMMON_FRAME_1_RX[i][5 ];
  COMMON_FRAME_2_RX[i][6 ] = COMMON_FRAME_1_RX[i][5 ] ^ COMMON_FRAME_1_RX[i][6 ];
  COMMON_FRAME_2_RX[i][7 ] = COMMON_FRAME_1_RX[i][6 ] ^ COMMON_FRAME_1_RX[i][7 ];
  COMMON_FRAME_2_RX[i][8 ] = COMMON_FRAME_1_RX[i][7 ] ^ COMMON_FRAME_1_RX[i][8 ];
  COMMON_FRAME_2_RX[i][9 ] = COMMON_FRAME_1_RX[i][8 ] ^ COMMON_FRAME_1_RX[i][9 ];
  COMMON_FRAME_2_RX[i][10] = COMMON_FRAME_1_RX[i][9 ] ^ COMMON_FRAME_1_RX[i][10];
  COMMON_FRAME_2_RX[i][11] = COMMON_FRAME_1_RX[i][10] ^ COMMON_FRAME_1_RX[i][11];
  COMMON_FRAME_2_RX[i][12] = COMMON_FRAME_1_RX[i][11] ^ COMMON_FRAME_1_RX[i][12];
  COMMON_FRAME_2_RX[i][13] = COMMON_FRAME_1_RX[i][12] ^ COMMON_FRAME_1_RX[i][13];
  COMMON_FRAME_2_RX[i][14] = COMMON_FRAME_1_RX[i][13] ^ COMMON_FRAME_1_RX[i][14];
  COMMON_FRAME_2_RX[i][15] = COMMON_FRAME_1_RX[i][14] ^ COMMON_FRAME_1_RX[i][15];
  COMMON_FRAME_2_RX[i][16] = COMMON_FRAME_1_RX[i][15] ^ COMMON_FRAME_1_RX[i][16];
  COMMON_FRAME_2_RX[i][17] = COMMON_FRAME_1_RX[i][16] ^ COMMON_FRAME_1_RX[i][17];
  COMMON_FRAME_2_RX[i][18] = COMMON_FRAME_1_RX[i][17] ^ COMMON_FRAME_1_RX[i][18];
  COMMON_FRAME_2_RX[i][19] = COMMON_FRAME_1_RX[i][18] ^ COMMON_FRAME_1_RX[i][19];
  COMMON_FRAME_2_RX[i][20] = COMMON_FRAME_1_RX[i][19] ^ COMMON_FRAME_1_RX[i][20];
  COMMON_FRAME_2_RX[i][21] = COMMON_FRAME_1_RX[i][20] ^ COMMON_FRAME_1_RX[i][21];
  COMMON_FRAME_2_RX[i][22] = COMMON_FRAME_1_RX[i][21] ^ COMMON_FRAME_1_RX[i][22];
  COMMON_FRAME_2_RX[i][23] = COMMON_FRAME_1_RX[i][22] ^ COMMON_FRAME_1_RX[i][23];
  COMMON_FRAME_2_RX[i][24] = COMMON_FRAME_1_RX[i][23] ^ COMMON_FRAME_1_RX[i][24];
  COMMON_FRAME_2_RX[i][25] = COMMON_FRAME_1_RX[i][24] ^ COMMON_FRAME_1_RX[i][25];
  COMMON_FRAME_2_RX[i][26] = COMMON_FRAME_1_RX[i][25] ^ COMMON_FRAME_1_RX[i][26];
  COMMON_FRAME_2_RX[i][27] = COMMON_FRAME_1_RX[i][26] ^ COMMON_FRAME_1_RX[i][27];
  COMMON_FRAME_2_RX[i][28] = COMMON_FRAME_1_RX[i][27] ^ COMMON_FRAME_1_RX[i][28];
  COMMON_FRAME_2_RX[i][29] = COMMON_FRAME_1_RX[i][28] ^ COMMON_FRAME_1_RX[i][29];
  DATA_OUT[0 ] = DATA_IN[0 ] ^ COMMON_FRAME_1_RX[i][29];
  DATA_OUT[1 ] = DATA_IN[1 ] ^ COMMON_FRAME_1_RX[i][28];
  DATA_OUT[2 ] = DATA_IN[2 ] ^ COMMON_FRAME_1_RX[i][27];
  DATA_OUT[3 ] = DATA_IN[3 ] ^ COMMON_FRAME_1_RX[i][26];
  DATA_OUT[4 ] = DATA_IN[4 ] ^ COMMON_FRAME_1_RX[i][25];
  DATA_OUT[5 ] = DATA_IN[5 ] ^ COMMON_FRAME_1_RX[i][24];
  DATA_OUT[6 ] = DATA_IN[6 ] ^ COMMON_FRAME_1_RX[i][23];
  DATA_OUT[7 ] = DATA_IN[7 ] ^ COMMON_FRAME_1_RX[i][22];
  DATA_OUT[8 ] = DATA_IN[8 ] ^ COMMON_FRAME_1_RX[i][21];
  DATA_OUT[9 ] = DATA_IN[9 ] ^ COMMON_FRAME_1_RX[i][20];
  DATA_OUT[10] = DATA_IN[10] ^ COMMON_FRAME_1_RX[i][19];
  DATA_OUT[11] = DATA_IN[11] ^ COMMON_FRAME_1_RX[i][18];
  DATA_OUT[12] = DATA_IN[12] ^ COMMON_FRAME_1_RX[i][17];
  DATA_OUT[13] = DATA_IN[13] ^ COMMON_FRAME_1_RX[i][16];
  DATA_OUT[14] = DATA_IN[14] ^ COMMON_FRAME_1_RX[i][15];
  DATA_OUT[15] = DATA_IN[15] ^ COMMON_FRAME_1_RX[i][14];
  DATA_OUT[16] = DATA_IN[16] ^ COMMON_FRAME_1_RX[i][13];
  DATA_OUT[17] = DATA_IN[17] ^ COMMON_FRAME_1_RX[i][12];
  DATA_OUT[18] = DATA_IN[18] ^ COMMON_FRAME_1_RX[i][11];
  DATA_OUT[19] = DATA_IN[19] ^ COMMON_FRAME_1_RX[i][10];
  DATA_OUT[20] = DATA_IN[20] ^ COMMON_FRAME_1_RX[i][9 ];
  DATA_OUT[21] = DATA_IN[21] ^ COMMON_FRAME_1_RX[i][8 ];
  DATA_OUT[22] = DATA_IN[22] ^ COMMON_FRAME_1_RX[i][7 ];
  DATA_OUT[23] = DATA_IN[23] ^ COMMON_FRAME_1_RX[i][6 ];
  DATA_OUT[24] = DATA_IN[24] ^ COMMON_FRAME_1_RX[i][5 ];
  DATA_OUT[25] = DATA_IN[25] ^ COMMON_FRAME_1_RX[i][4 ];
  DATA_OUT[26] = DATA_IN[26] ^ COMMON_FRAME_1_RX[i][3 ];
  DATA_OUT[27] = DATA_IN[27] ^ COMMON_FRAME_1_RX[i][2 ];
  DATA_OUT[28] = DATA_IN[28] ^ COMMON_FRAME_1_RX[i][1 ];
  DATA_OUT[29] = DATA_IN[29] ^ COMMON_FRAME_1_RX[i][0 ] ^ COMMON_FRAME_1_RX[i][29 ];
    
  COMMON_FRAME_1_RX[i] = COMMON_FRAME_2_RX[i];
    
  return DATA_OUT;
}

