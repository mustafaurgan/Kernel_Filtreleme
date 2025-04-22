% Metin belgesinin yolu ve adı
dosyaYolu = 'C:\Users\monster\OneDrive\Masaüstü'; % Dosya yolu doğru şekilde güncellenmeli
dosyaAdi = 'mesafe.txt';

% Dosyayı aç
dosyaID = fopen(fullfile(dosyaYolu, dosyaAdi), 'r');

% Dosyadan tüm içeriği oku
metinIcerik = fileread(fullfile(dosyaYolu, dosyaAdi));

% Dosyayı kapat
fclose(dosyaID);

% Metin içeriğini ekrana yazdır
disp('Okunan Metin:');
disp(metinIcerik);
