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



void encryptdom ( u64 plain,u64 plain1, u80 key, u80 key1,  ap_int<50> IR, ap_int<1> *i1, ap_int<1>  *i2, ap_int<1>  *i12, ap_int<1>  *i22, ap_int<1>  *i13, ap_int<1>  *i23, ap_int<1>  *i14, ap_int<1>  *i24, ap_int<1>  z, ap_int<1>  z1, ap_int<13> *cipher, ap_int<13> *cipher1) {

//ap_int<1> *i1,  *i2,  *i12,  *i22,  *i13,  *i23,  *i14,  *i24,  *y1,  *y2,  *y12,  *y22,  *y13,  *y23,  *y14,  *y24;
ap_int<1> tempi1, tempi2, tempy1, tempy2, tempi14, tempi24, tempy14, tempy24,tempi12, tempi22, tempy12, tempy22,tempi13, tempi23, tempy13, tempy23; 
//ap_int<1> *i1; ap_int<1>  *i2; ap_int<1>  *i12; ap_int<1>  *i22; ap_int<1>  *i13; ap_int<1>  *i23; ap_int<1>  *i14; ap_int<1>  *i24;
 ap_int<1>  y1; ap_int<1>  y2; ap_int<1>  y12; ap_int<1>  y22; ap_int<1>  y13; ap_int<1>  y23; ap_int<1>  y14; ap_int<1>  y24;  

#pragma HLS_interface i1 none_registered
#pragma HLS_interface i2 none_registered
#pragma HLS_interface i12 none_registered
#pragma HLS_interface i22 none_registered
#pragma HLS_interface i13 none_registered
#pragma HLS_interface i23 none_registered
#pragma HLS_interface i14 none_registered
#pragma HLS_interface i24 none_registered

#pragma HLS_interface cipher none_registered
#pragma HLS_interface cipher1 none_registered


//#pragma  array_map variable=f[1] instance=L1_temp horizontal
//#pragma  array_map variable=L1 instance=L1_temp horizontal

//#pragma  array_map variable=f[0] instance=L2_temp horizontal
//#pragma  array_map variable=L2 instance=L2_temp horizontal

  ap_int<1> *f0_reg1, *f1_reg1, *f0_reg0, *f1_reg0;
  ap_int<13> L11, L12, L11_temp, L12_temp; ap_int<19> L21, L22, L21_temp, L22_temp; 
  ap_int<100> k1, k2; ap_int<1> f1, f2, f3, f4;ap_int<2> temp_var;ap_int<32> L_temp;
  int i,j; 
    
  #pragma unroll
  for(i=0;i<19;++i) {
    L21[i] = plain[i];
    L22[i] = plain1[i];
  }
  #pragma unroll
  for(i=0;i<13;++i) {
    L11[i] = plain[i];
    L12[i] = plain1[i];
  }
  #pragma unroll
  for(i=0;i<80;++i){
   k1[i]=key[i];
   k2[i]=key1[i];
 }



  #pragma nounroll
  for(i=0;i<50;++i) {
  *i1=(L11[X3_32] & L12[X4_32]) ^ z; tempi1= *i1;
  *i2=(L11[X4_32] & L12[X3_32]) ^ z; tempi2= *i2;
  y1 = tempi1^(L11[X3_32] & L11[X4_32]);tempy1= y1;
  y2 = tempi2^(L12[X3_32] & L12[X4_32]);tempy2= y2;

  *i12=(L11[X5_32] & 0) ^ z1; tempi12= *i12;
  *i22=(IR[i] & L12[X5_32]) ^ z1; tempi22= *i22;
  y12 = tempi1^(L11[X5_32] & IR[i]);tempy12= y12;
  y22 = tempi2^(L12[X5_32] & 0);tempy22= y22;

  f1 = L11[X1_32] ^ L11[X2_32] ^ tempy1 ^ tempy12     ^ k1[i];
  f2 = L12[X1_32] ^ L12[X2_32] ^ tempy2 ^ tempy22 ;

  *i13=(L11[Y3_32] & L12[Y4_32]) ^ z; tempi13= *i13;
  *i23=(L11[Y4_32] & L12[Y3_32]) ^ z; tempi23= *i23;
  y13 = tempi13^(L11[Y3_32] & L11[Y4_32]);tempy13= y13;
  y23 = tempi23^(L12[Y3_32] & L12[Y4_32]);tempy23= y23;

  *i14=(L11[Y5_32] & L12[Y6_32]) ^ z1; tempi14= *i14;
  *i24=(L11[Y6_32] & L12[Y5_32]) ^ z1; tempi24= *i24;
  y14 = tempi14^(L11[Y5_32] & L11[Y6_32]);tempy14= y14;
  y24 = tempi24^(L12[Y6_32] & L12[Y5_32]);tempy24= y24;

  f2 = L21[Y1_32] ^ L21[Y2_32] ^  tempy13 ^ tempy14     ^ k2[i];
  f4 = L22[Y1_32] ^ L22[Y2_32] ^ tempy23 ^ tempy24 ;

    //f[0] = *f0_reg0; f[1]=*f1_reg1; f[3] = *f0_reg1; f[4]=*f1_reg1;

  #pragma unroll
   for(j=0;j < 13;++j){
      if (j==0){
       L11_temp[j] = f1;
       L12_temp[j] = f12
      }
      else{
       L11_temp[j] = L11[j];
       L12_temp[j] = L12[j];
      }
    }
    #pragma unroll
    for(j=0;j < 19;++j){
      if (j==0){
      L21_temp[j] = f3;
      L22_temp[j] = f4;
      }
      else {
      L21_temp[j] = L21[j];
      L22_temp[j] = L22[j];
      }
    }    
    
  }
*cipher = L11_temp;
*cipher1 = L12_temp;


}



