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
V = acc_intergration(A);
plot(V);
xlabel('0.01s');
ylabel('m/s');
title('Velocity for resultant acceleration');

subplot(3,1,3);
D = acc_intergration(V);
plot(D);
xlabel('0.01s');
ylabel('m');
title('Displacement for resultant acceleration ');
saveas(gcf,'Combined_A_V_D','eps');

figure(2)
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
plot(A)
xlabel('0.01s');
ylabel('m/s2');
title('Combined-Acceleration');
saveas(gcf,'diagram of Accelerations','eps');

figure(3)
subplot(3,1,1);
plot(Ax)
xlabel('0.01s');
ylabel('m/s2');
title('x-Acceleration');

subplot(3,1,2);
Vx = acc_intergration(Ax);
plot(Vx);
xlabel('0.01s');
ylabel('m/s');
title('x-Velocity');

subplot(3,1,3);
Dx = acc_intergration(Vx);
plot(Dx);
xlabel('0.01s');
ylabel('m');
title('x-Displacement');
saveas(gcf,'Ax_com','eps');

figure(4)
subplot(3,1,1);
plot(Ay)
xlabel('0.01s');
ylabel('m/s2');
title('y-Acceleration');

subplot(3,1,2);
Vy = acc_intergration(Ay);
plot(Vy);
xlabel('0.01s');
ylabel('m/s');
title('y-Velocity');

subplot(3,1,3);
Dy = acc_intergration(Vy);
plot(Dy);
xlabel('0.01s');
ylabel('m');
title('y-Displacement');
saveas(gcf,'Ay_com','eps');

figure(5)
subplot(3,1,1);
plot(Az)
xlabel('0.01s');
ylabel('m/s2');
title('z-Acceleration');

subplot(3,1,2);
Vz = acc_intergration(Az);
plot(Vz);
xlabel('0.01s');
ylabel('m/s');
title('z-Velocity');

subplot(3,1,3);
Dz = acc_intergration(Vz);
plot(Dz);
xlabel('0.01s');
ylabel('m');
title('z-Displacement');
saveas(gcf,'Az_com','eps');

figure(6)
A2D = sqrt(Ax.^2 + Ay.^2);
subplot(3,1,1);
plot(A2D)
xlabel('0.01s');
ylabel('m/s2');
title('2D-Acceleration');

subplot(3,1,2);
V2D = acc_intergration(A2D);
plot(V2D);
xlabel('0.01s');
ylabel('m/s');
title('2D-Velocity');

subplot(3,1,3);
D2D = acc_intergration(V2D);
plot(D2D);
xlabel('0.01s');
ylabel('m');
title('2D-Displacement');
saveas(gcf,'2D','eps');
