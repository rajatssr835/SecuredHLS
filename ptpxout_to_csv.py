from csv import reader
import math  
from array import * 
import re

trace_count = 4998
tracepoints = 6
muR=[]
muF=[]
csum2R=[]
csum2F=[]
tvla=[]
denom=[]
power= array('L')
power = [0 for i in range(50)]
for i in range(tracepoints):
 muR.append( float(0))
 muF.append( float(0))
 csum2R.append( float(0))
 csum2F.append( float(0))
 tvla.append( float(0))
 denom.append( float(0))

setcount=0
traceCounter=0
i=0
ccounter=10
pt_tracefile= open('primetime_px.out', 'r')
line= pt_tracefile.readline()
while True:
 #line= pt_tracefile.readline()
 p1 = re.compile(";")
 p2 = re.compile(".index *")
 p3 = re.compile(".hier *");p4 = re.compile(".t *"); p5 = re.compile("; file *"); p6= re.compile("^\s*$")
 if (p2.match(line) or p1.match(line) or p3.match(line) or p4.match(line)or p6.match(line)):
  line= pt_tracefile.readline(); 
  continue
 if ((re.compile('0$')).match(line)):
  power = [0 for i in range(50)]
  print(','.join(map(str, power)) )
  while True:
   #print(line.rstrip('\n'))
   line= pt_tracefile.readline()
   data=line.split("  "); 
   if (len(data)>1):
    power[int(data[0])-1]=float(data[1])
   if ((re.compile('10$')).match(line)):
    print(','.join(map(str, power)) )
    break
 i=i+10
 j=i+1
 
 #print (str(i)+","+str(j)+","+str(line))
 ii=str(i) ; jj=str(j); 
 if ((re.compile('%s$'%ii)).match(line)):
  power = [0 for i in range(50)]
  while True:
   #print(line.rstrip('\n'))
   line= pt_tracefile.readline()
   data=line.split("  "); 
   if (len(data)>1):
    power[int(data[0])-1]=float(data[1])
   if ((re.compile('%s$'%jj)).match(line)or p5.match(line)):
    print(','.join(map(str, power)) )
    break
 
 if ((re.compile('%s$'%jj)).match(line)):
  power = [0 for i in range(50)]
  while True:
   #print(line.rstrip('\n'))
   line= pt_tracefile.readline()
   data=line.split("  "); 
   if (len(data)>1):
    power[int(data[0])-1]=float(data[1])
   if ((re.compile('%s$'%str(i+10))).match(line) or p5.match(line)):
    print(','.join(map(str, power)) )
    break
 #i=i+10;  j=i+1;  
 
 if ((not line)):
  break
 

pt_tracefile.close()
 
#python ptpxout_to_csv.py  > trace1.csv
#awk '{printf $0;printf ","}NR % 4 ==0 {print ","}' trace1.csv | sed 's/,,$//g' | sed '$d' | sed '$d' 
 


