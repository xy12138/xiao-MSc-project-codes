data=load('offline_short.txt');
ax = data(:,3);
ay = data(:,4);
az = data(:,5);
ax1 = mean(ax)
ay1 = mean(ay)
az1 = mean(az)

Ax = 0.061/2/1000*9.8*ax; 
Ay = 0.061/2/1000*9.8*ay;
Az = 0.061/2/1000*9.8*az;

figure(1)
subplot(2,2,1);
plot(Ax)
xlabel('0.01s');
ylabel('m/s2');
title('x-Acceleration');

subplot(2,2,2);
plot(Ay)
xlabel('0.01s');
ylabel('m/s2');
title('y-Acceleration');

subplot(2,2,3);
plot(Az)
xlabel('0.01s');
ylabel('m/s2');
title('z-Acceleration');

subplot(2,2,4);
A = sqrt(Ax.^2 + Ay.^2 + Az.^2);
plot(A)
xlabel('0.01s');
ylabel('m/s2');
title('Combined-Acceleration');
saveas(gcf,'raw_unoffset','eps');
