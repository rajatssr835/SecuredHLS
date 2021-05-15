#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ap_int.h>


typedef ap_int<32> u64;
typedef ap_int<80> u80;

#define ONES 0xFFFFFFFFFFFFFFFFULL

#define X1_32  12
#define X2_32  7
#define X3_32  8
#define X4_32  5
#define X5_32  3
#define Y1_32  18
#define Y2_32  7
#define Y3_32  12
#define Y4_32  10
#define Y5_32  8
#define Y6_32  3

#define X1_48  18
#define X2_48  12
#define X3_48  15
#define X4_48  7
#define X5_48  6
#define Y1_48  28
#define Y2_48  19
#define Y3_48  21
#define Y4_48  13
#define Y5_48  15
#define Y6_48  6

#define X1_64  24
#define X2_64  15
#define X3_64  20
#define X4_64  11
#define X5_64  9
#define Y1_64  38
#define Y2_64  25
#define Y3_64  33
#define Y4_64  21
#define Y5_64  14
#define Y6_64  9


//set_directive_array_map -instance L_temp -mode horizontal encrypt L1_temp
//set_directive_array_map -instance L_temp -mode horizontal encrypt L2_temp


#pragma HLS_interface f_reg none_registered
void encrypt( u64 plain, ap_int<13>  *cipher, u80 key, ap_int<1>* f_reg0,  ap_int<1>* f_reg1) {

//#pragma  array_map variable=f[1] instance=L1_temp horizontal
//#pragma  array_map variable=L1 instance=L1_temp horizontal

//#pragma  array_map variable=f[0] instance=L2_temp horizontal
//#pragma  array_map variable=L2 instance=L2_temp horizontal


  ap_int<13> L1, L1_temp; ap_int<19> L2, L2_temp; ap_int<100> k; ap_int<2> f;ap_int<2> temp_var;ap_int<32> L_temp;
  int i,j;
    
  #pragma unroll
  for(i=0;i<19;++i) 
    L2[i] = plain[i];
  #pragma unroll
  for(i=0;i<13;++i) 
    L1[i] = plain[i];
  #pragma unroll
  for(i=0;i<80;++i)
   k[i]=key[i];



  #pragma nounroll
  for(i=0;i<50;++i) {
   //f[0] = L1[X1_32] ^ L1[X2_32] ^ (L1[X3_32] & L1[X4_32]) ^ (L1[X5_32]  )     ^ k[i];
   //f[1] = L2[Y1_32] ^ L2[Y2_32] ^ (L2[Y3_32] & L2[Y4_32]) ^ (L2[Y5_32] & L2[Y6_32]) ^ k[i];
    *f_reg0 = L1[X1_32] ^ L1[X2_32] ^ (L1[X3_32] & L1[X4_32]) ^ (L1[X5_32]  )     ^ k[i];
    *f_reg1 = L2[Y1_32] ^ L2[Y2_32] ^ (L2[Y3_32] & L2[Y4_32]) ^ (L2[Y5_32] & L2[Y6_32]) ^ k[i];
    f[0] = *f_reg0; f[1]=*f_reg1;

  #pragma unroll
   for(j=0;j < 13;++j){
      if (j==0)
       L1_temp[j] = f[1];
      else
       L1_temp[j] = L1[j];
    }
    #pragma unroll
    for(j=0;j < 19;++j){
      if (j==0)
      L2_temp[j] = f[0];
      else
      L2_temp[j] = L2[j];
    }    
    
  }
 //#pragma  HLS_array_map variable=L1_temp instance=L_temp horizontal
//#pragma  HLS_array_map variable=L2_temp instance=L_temp horizontal
  *cipher=L1_temp;
}



