
Data = csvread ("moist5.log");
sensors = max(Data(:,4));
n = 2;
sensorColumn = 4;
dataColumn = 3;
plotColumns = 2;
plotRows = sensors;

for sensor = 1:sensors

	A = Data(Data(:,sensorColumn)==sensor,:);
	x = round(A(:,1)/(1000*60))/60;
	y = A(:,dataColumn);
	p = polyfit(x,y,n);
	f = polyval(p,x);
	d = polyder(p);
	f2 = polyval(d,x);

	subplot(plotColumns,plotRows, sensor);
	plot(x,y,'.',x,f,'linewidth',3,'-r');
	subplot(plotColumns,plotRows, sensor + sensors);
	plot(x,f2);

endfor
