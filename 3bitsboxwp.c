
_Bool f1 (_Bool, _Bool);
_Bool f2 (_Bool, _Bool);
_Bool f3 (_Bool, _Bool);
_Bool f4 (_Bool, _Bool);
_Bool f5 (_Bool, _Bool);
_Bool f6 (_Bool, _Bool);
//#pragma HLS_interface s1 none

#pragma HLS_interface T01temp none_registered
#pragma HLS_interface T21temp none_registered
#pragma HLS_interface T02temp none_registered
#pragma HLS_interface T22temp none_registered
#pragma HLS_interface T03temp none_registered
#pragma HLS_interface T23temp none_registered
//#pragma HLS_interface r0 none_registered
//#pragma HLS_interface r1 none_registered
//#pragma HLS_interface t0 none_registered
//#pragma HLS_interface t1 none_registered
//#pragma HLS_interface s0 none_registered
//#pragma HLS_interface s1 none_registered

void sbox (_Bool a0, _Bool a1, _Bool b0, _Bool b1, _Bool c0, _Bool c1, _Bool *r0, _Bool *r1, _Bool *s0, _Bool *s1, _Bool *t0, _Bool *t1, _Bool *T01temp, _Bool *T21temp,  _Bool *T02temp, _Bool *T22temp,  _Bool *T03temp, _Bool *T23temp)

{
 	//_Bool zero = '0';
 	//_Bool one = '1';
        _Bool T01temp1, T21temp1,T02temp1,T22temp1,T03temp1,T23temp1 ;
        _Bool T01, T11, T21, T31;
        _Bool T02, T12, T22, T32;
        _Bool T03, T13, T23, T33;
         	
 	//------------------
 	T01 = ~b0 & c1;
 	T21 = a1 & b1;
 	
 	T11 = ~b0 & c0;
 	T31 = a1 & b0;
 	
       	/*T0 = T0 ^ a0;
 	T2 = T2 ^ c1;
 	*r0 = T0 ^ T1;
 	*t1 = T2 ^ T3;*/

        *T01temp = f1 (T01, a0);T01temp1 = *T01temp;
        *T21temp = f2 (T21, c1);T21temp1 = *T21temp;
 	*r0 = T01temp1 ^ T11;
 	*t1 = T21temp1 ^ T31;
 	

 	//-----------------
 	
 	//------------------
 	T02 = ~c0 & a1;
 	T22 = b1 & c1;
 	
 	T12 = ~c0 & a0;
 	T32 = b1 & c0;
 	

 	/*T0 = T0 ^ b0;
 	T2 = T2 ^ a1; 	
 	*s0 = T0 ^ T1;
 	*r1 = T2 ^ T3;*/

        *T02temp = f3 (T02, b0);T02temp1 = *T02temp;
        *T22temp = f4 (T22, a1);T22temp1 = *T22temp;
 	*s0 = T02temp1 ^ T12;
 	*r1 = T22temp1 ^ T32;


 	//-----------------

 	//------------------
 	T03 = ~a0 & b1;
 	T23 = c1 & a1;
 	
 	T13 = ~a0 & b0;
 	T33 = c1 & a0;
 
 	/*T0 = T0 ^ c0;
 	T2 = T2 ^ b1;
 	*t0 = T0 ^ T1;
        *s1 = T2 ^ T3;*/


        *T03temp = f5 (T03, c0);T03temp1 = *T03temp;
        *T23temp = f6 (T23, b1);T23temp1 = *T23temp;
 	*t0 = T03temp1 ^ T13;
 	*s1 = T23temp1 ^ T33;

 	//-----------------	


}


_Bool __attribute__((noinline)) f1(_Bool b , _Bool c)
{
return (b ^ c);
}
_Bool __attribute__((noinline)) f2(_Bool b , _Bool c)
{
return (b ^ c);
}
_Bool __attribute__((noinline)) f3(_Bool b , _Bool c)
{
return (b ^ c);
}
_Bool __attribute__((noinline)) f4(_Bool b , _Bool c)
{
return (b ^ c);
}
_Bool __attribute__((noinline)) f5(_Bool b , _Bool c)
{
return (b ^ c);
}
_Bool __attribute__((noinline)) f6(_Bool b , _Bool c)
{
return (b ^ c);
}





