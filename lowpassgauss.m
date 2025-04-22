distance = [17 36 51 13 29 44 63 8 50 76 6 27 39 68 16 72 57 22 59 11 31 47 73 9 65 34 55 21 75 43 28 58 18 66 45 14 79 69 42 23 56 10 74 32 48 67 20 7 54 25 78 37 12 60 30 64 53 19];
gaussian = @(x, sigma) (1 / sqrt(2*pi) * sigma) * exp(-x.^2 / (2 * sigma^2));
kernel_size = 3;
sigma = 1;
kernel_x = linspace(-kernel_size / 2, kernel_size / 2, kernel_size);
kernel = gaussian(kernel_x, sigma);
result = conv(distance, kernel, 'same');

figure;
subplot(3, 1, 1);
plot(distance, '-o', 'DisplayName', 'Orijinal');
title('Orijinal Mesafe Verileri');
xlabel('Ölçüm');
ylabel('Uzaklık');
grid on;
legend;

subplot(3, 1, 2);
plot(result, '-r', 'LineWidth', 2, 'DisplayName', 'Gauss Filtre Uygulanmış Veri');
title('Gauss Filtre Uygulanmış Mesafe Verileri');
xlabel('Ölçüm');
ylabel('Uzaklık');
grid on;
legend;

subplot(3, 1, 3);
plot(distance, '-o', 'DisplayName', 'Orijinal');
hold on;
plot(result, '-r', 'LineWidth', 2, 'DisplayName', 'Gauss Applied Data');
title('Orijinal ve Gauss Filtre Uygulanmış Verinin Üzerinebindirme');
xlabel('Ölçüm');
ylabel('Uzaklık');
grid on;
legend;
