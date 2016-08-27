data=load('offline_short.txt');
ax = data(:,3);
ay = data(:,4);
az = data(:,5);
ax1 = mean(ax)
ay1 = mean(ay)
az1 = mean(az)
Ax = 0.061/2/1000*9.8*(ax - ax1); 
Ay = 0.061/2/1000*9.8*(ay - ay1);
Az = 0.061/2/1000*9.8*(az - az1);

A = sqrt(Ax.^2 + Ay.^2 + Az.^2);
figure(1)
subplot(3,1,1);
plot(A)
xlabel('0.01s');
ylabel('m/s2');
title('Acceleration');

subplot(3,1,2);
V = acc_leaky_intergration(A);
plot(V);
xlabel('0.01s');
ylabel('m/s');
title('Velocity');

subplot(3,1,3);
D = acc_leaky_intergration(V);
plot(D);
xlabel('0.01s');
ylabel('m');
title('Displacement');
saveas(gcf,'LeakyComA','eps');

figure(2)
subplot(2,2,1);
plot(Ax)
xlabel('0.01s');
ylabel('m/s2');
title('Acceleration');
saveas(gcf,'Leaky-x-Acceleration','eps');

subplot(2,2,2);
plot(Ay)
xlabel('0.01s');
ylabel('m/s2');
title('Acceleration');
saveas(gcf,'Leaky-y-Acceleration','eps');

subplot(2,2,3);
plot(Az)
xlabel('0.01s');
ylabel('m/s2');
title('Acceleration');
saveas(gcf,'Leaky-z-Acceleration','eps');

subplot(2,2,4);
plot(A)
xlabel('0.01s');
ylabel('m/s2');
title('Combined-Acceleration');
saveas(gcf,'diagram of leaky Accelerations','eps');

figure(3)
subplot(3,1,1);
plot(Ax)
xlabel('0.01s');
ylabel('m/s2');
title('leaky-x-Acceleration');

subplot(3,1,2);
Vx = acc_leaky_intergration(Ax);
plot(Vx);
xlabel('0.01s');
ylabel('m/s');
title('leaky-x-Velocity');

subplot(3,1,3);
Dx = acc_leaky_intergration(Vx);
plot(Dx);
xlabel('0.01s');
ylabel('m');
title('leaky-x-Displacement');
saveas(gcf,'Leaky-Ax_com_com','eps');

figure(4)
subplot(3,1,1);
plot(Ay)
xlabel('0.01s');
ylabel('m/s2');
title('leakky-y-Acceleration');

subplot(3,1,2);
Vy = acc_leaky_intergration(Ay);
plot(Vy);
xlabel('0.01s');
ylabel('m/s');
title('leaky-y-Velocity');

subplot(3,1,3);
Dy = acc_leaky_intergration(Vy);
plot(Dy);
xlabel('0.01s');
ylabel('m');
title('y-Displacement');
saveas(gcf,'Leaky-Ay_com','eps');

figure(5)
subplot(3,1,1);
plot(Az)
xlabel('0.01s');
ylabel('m/s2');
title('leaky-z-Acceleration');

subplot(3,1,2);
Vz = acc_leaky_intergration(Az);
plot(Vz);
xlabel('0.01s');
ylabel('m/s');
title('leaky-z-Velocity');

subplot(3,1,3);
Dz = acc_leaky_intergration(Vz);
plot(Dz);
xlabel('0.01s');
ylabel('m');
title('leaky-z-Displacement');
saveas(gcf,'Leaky-Az_com','eps');

figure(6)
A2D = sqrt(Ax.^2 + Ay.^2);
subplot(3,1,1);
plot(A2D)
xlabel('0.01s');
ylabel('m/s2');
title('leaky-2D-Acceleration');

subplot(3,1,2);
V2D = acc_leaky_intergration(A2D);
plot(V2D);
xlabel('0.01s');
ylabel('m/s');
title('leaky-2D-Velocity');

subplot(3,1,3);
D2D = acc_leaky_intergration(V2D);
plot(D2D);
xlabel('0.01s');
ylabel('m');
title('leaky-2D-Displacement');
saveas(gcf,'Leaky-2D','eps');

figure(7)
subplot(4,1,1);
plot(Dx);
xlabel('0.01s');
ylabel('m');
title('Leaky-x-Displacement');

subplot(4,1,2);
plot(Dy);
xlabel('0.01s');
ylabel('m');
title('Leaky-y-Displacement');

subplot(4,1,3);
plot(Dz);
xlabel('0.01s');
ylabel('m');
title('Leaky-z-Displacement');

subplot(4,1,4);
plot(D);
xlabel('0.01s');
ylabel('m');
title('Leaky-Combined-Displacement');

saveas(gcf,'Leaky-displacement','eps');

