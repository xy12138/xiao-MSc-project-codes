function newData= acc_leaky_intergration(rawData)
samplePeriod = 0.01;
size = length(rawData);
i=1;
while (i <= size)
if(i == 1)
Data(i) = rawData(i);
else
Data(i) =Data(i-1) + 0.3*rawData(i)*samplePeriod ;
end
i = i+1;
end
newData = Data;