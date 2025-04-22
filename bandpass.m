distance = [17 36 51 13 29 44 63 8 50 76 6 27 39 68 16 72 57 22 59 11 31 47 73 9 65 34 55 21 75 43 28 58 18 66 45 14 79 69 42 23 56 10 74 32 48 67 20 7 54 25 78 37 12 60 30 64 53 19];
kernel_size_lowpass = 3;
kernel_size_highpass = 3;
kernel_a_lowpass = 1 / kernel_size_lowpass;
kernel_a_highpass = 1 / kernel_size_highpass;
kernel_lowpass = ones(1, kernel_size_lowpass) * kernel_a_lowpass;
kernel_highpass = -ones(1, kernel_size_highpass) * kernel_a_highpass;
kernel_highpass(floor(kernel_size_highpass / 2) + 1) = 1 + kernel_a_highpass;
result_lowpass = conv(distance, kernel_lowpass, 'same');
result_highpass = conv(distance, kernel_highpass, 'same');
result_bandpass = result_lowpass + result_highpass;

figure;
subplot(3, 1, 1);
plot(distance, '-o', 'DisplayName', 'Original');
title('Original Distance Data');
xlabel('Measurement');
ylabel('Displacement');
grid on;
legend;

subplot(3, 1, 2);
plot(result_lowpass, '-b', 'LineWidth', 2, 'DisplayName', 'Low Pass Filter Applied Distance Data');
title('Low Pass Filter Applied Distance Datas');
xlabel('Measurement');
ylabel('Displacement');
grid on;
legend;

subplot(3, 1, 3);
plot(result_highpass, '-r', 'LineWidth', 2, 'DisplayName', 'High Pass Filter Applied Data');
title('High Pass Filter Applied Distance Data');
xlabel('Measurement');
ylabel('Displacement');
grid on;
legend;

figure;
subplot(2, 1, 1);
plot(result_bandpass, '-g', 'LineWidth', 2, 'DisplayName', 'Bandpass Filter Applied Data');
title('Bandpass Filter Applied Distance Datas');
xlabel('Measurement');
ylabel('Displacement');
grid on;
legend;
