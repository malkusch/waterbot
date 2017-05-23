
Data1 = csvread ("moist4.log");
Data2 = csvread ("moist5.log");
Data2(:,1) = Data2(:,1) + max(Data1(:,1));

Data = [Data1;Data2];
sensors = max(Data(:,4));
n = 2;
sensorColumn = 4;
dataColumn = 3;
plotColumns = 2;
plotRows = sensors;
day = 24 * 3;

for sensor = 1:sensors

	A = Data(Data(:,sensorColumn)==sensor,:);
	x = round(A(:,1)/(1000*60))/60;
	y = A(:,dataColumn);

	Y = nan(day, ceil(length(y)/day));
	Y(1:length(y)) = y;
	Y = mean(Y)';
	dY = Y - [NaN;Y(1:end-1)];
	X = nan(day, ceil(length(x)/day));
	X(1:length(x)) = x;
	X = mean(X)';

	p = polyfit(x,y,n);
	f = polyval(p,x);
	d = polyder(p);
	f2 = polyval(d,x);

	subplot(plotColumns,plotRows, sensor);
	plot(x,y,'.g',x,f, '-r', X,Y, 'linewidth', 3, 'xr');
	subplot(plotColumns,plotRows, sensor + sensors);
	# plot(x,f2);
	plot(X,dY, "rx");

endfor
