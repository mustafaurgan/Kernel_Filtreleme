% Verileri içe aktarılacak metin dosyasının adını ve yolunu belirtin
dosya_yolu = 'C:\Users\monster\OneDrive\Masaüstü\mesafe.txt';

% Dosyayı açın
fileID = fopen(dosya_yolu, 'r');

% Dosyadan veriyi okuyun
mesafe = fscanf(fileID, '%f', [1, 60]);

% Dosyayı kapatın
fclose(fileID);
