
Data = [];
for session = 0:9999
	file = sprintf("waterbot-%d.log", session);
	if !exist(file)
		break
	endif
	L = csvread(file)(:,1:5);
	L = L(and(L(:,3)>0, L(:,2)==Inf),:);
	Data = [Data;L];
endfor

sensors = max(Data(:,4));
n = 2;
sensorColumn = 4;
dataColumn = 3;
plotColumns = 2;
plotRows = sensors;
day = 24 * 3;

for sensor = 1:sensors

	A = Data(and(Data(:,sensorColumn)==sensor, Data(:,2)==Inf), :);
	x = A(:,1);
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
	axis([min(x);max(x)]);
	subplot(plotColumns,plotRows, sensor + sensors);
	# plot(x,f2);
	plot(X,dY, "rx");
	axis([min(x);max(x)]);

endfor
