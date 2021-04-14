#include <stdint.h>
void DOMAND (_Bool a1, _Bool b1, _Bool a2, _Bool  b2, _Bool z, _Bool *i1, _Bool *i2 , _Bool *y1, _Bool *y2) {
#pragma HLS_interface i1 none_registered
#pragma HLS_interface i2 none_registered
_Bool ti1, ti2;
*i1=(a1 & b2)^ z; ti1= *i1; 
*i2=(a2 & b1)^ z; ti2 = *i2;

*y1 = ti1^(a1 & b1);
*y2 = ti2^(a2 & b2);
}



