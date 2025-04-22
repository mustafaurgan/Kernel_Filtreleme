distance = [17 36 51 13 29 44 63 8 50 76 6 27 39 68 16 72 57 22 59 11 31 47 73 9 65 34 55 21 75 43 28 58 18 66 45 14 79 69 42 23 56 10 74 32 48 67 20 7 54 25 78 37 12 60 30 64 53 19];
kernela = -1;
kernelb = 0;
kernelc = 1;
kernel = [kernela/2 kernelb kernelc/2]
result = conv(distance, kernel, 'same');

figure;
subplot(3, 1, 1);
plot(distance, '-o', 'DisplayName', 'Original');
title('Original Distance Data');
xlabel('Measurement');
ylabel('Displacement');
grid on;
legend;

subplot(3, 1, 2);
plot(result, '-r', 'LineWidth', 2, 'DisplayName', 'Kernel Applied Data');
title('Kernel Applied Distance Data');
xlabel('Measurement');
ylabel('Displacement');
grid on;
legend;

subplot(3, 1, 3);
plot(distance, '-o', 'DisplayName', 'Original');
hold on;
plot(result, '-r', 'LineWidth', 2, 'DisplayName', 'Kernel Applied Data');
title('Overlay of Original and Kernel Applied Data');
xlabel('Measurement');
ylabel('Displacement');
grid on;
legend;