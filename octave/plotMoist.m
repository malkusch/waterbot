n = 2;
Data = csvread ("moist.log");
x = Data(:,1);
y = Data(:,3);
p = polyfit(x,y,n);
f = polyval(p,x);
d = polyder(p);
f2 = polyval(d,x);

subplot(2,1,1);
plot(x,y,'.',x,f,'linewidth',3,'-r');
subplot(2,1,2);
plot(x,f2);
