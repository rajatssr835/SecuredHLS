from csv import reader
import math  

trace_count = 4998
tracepoints = 198
adjust=48

muR=[]
muF=[]
csum2R=[]
csum2F=[]
tvla=[]
denom=[]
for i in range(adjust,tracepoints):
 muR.append( float(0))
 muF.append( float(0))
 csum2R.append( float(0))
 csum2F.append( float(0))
 tvla.append( float(0))
 denom.append( float(0))

setcount=0
traceCounter=0
with open('trace.csv', 'r') as read_obj:
 csv_reader = reader(read_obj)
 for row in csv_reader:
  #print(row)
  for pointcount1 in range(adjust,tracepoints):
   pointcount=pointcount1-adjust
   if (traceCounter % 2):
    delta = float(row[pointcount1]) - muR[pointcount]
    muR[pointcount] = muR[pointcount] + ((delta)/(setcount+1));
    csum2R[pointcount] = csum2R[pointcount] + (delta*delta)*(setcount/(setcount+1));
    denom[pointcount]=math.sqrt((csum2R[pointcount]/((setcount+1)*(setcount+1)))+ (csum2F[pointcount]/((setcount+1)*(setcount+1)))) 
    if (denom[pointcount] > 0):
     tvla[pointcount]= (muR[pointcount]-muF[pointcount])/math.sqrt((csum2R[pointcount]/((setcount+1)*(setcount+1)))+ (csum2F[pointcount]/((setcount+1)*(setcount+1))) )  
    else:
     tvla[pointcount]=0  
   else :
    delta = float(row[pointcount1]) - muF[pointcount]
    muF[pointcount] = muF[pointcount] + ((delta)/(setcount+1));
    csum2F[pointcount] = csum2F[pointcount] + (delta*delta)*(setcount/(setcount+1));

  traceCounter=traceCounter + 1
  if (traceCounter == trace_count):
   break
  if (traceCounter > 0 and (traceCounter % 2) == 0):
   setcount=setcount+1
  

for ii in range(adjust,tracepoints):
 i=ii-adjust
 #print (str(muR[i]-muF[i])+","+str(denom[i])+","+str(tvla[i]))
 print (str(tvla[i]))
 

read_obj.close()
