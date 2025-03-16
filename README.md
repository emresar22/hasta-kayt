# Acil Servis Hasta Kayıt Sistemi (C Programı)

## 📌 Proje Açıklaması
Bu proje, bir hastanedeki acil servis hasta kayıtlarını yönetmek için geliştirilmiştir. Hasta bilgileri HL7 formatında saklanır ve öncelik sıralamasına göre hastaların işlemleri yapılır.

## 📋 Özellikler
- **Hasta Kaydı**: Kullanıcıdan hasta bilgileri alınır.
- **Öncelik Belirleme**: Yaş ve hastalık durumuna göre hastalara öncelik verilir.
- **Reçete No Üretme**: Her hasta için rastgele reçete numarası atanır.
- **HL7 Formatında Kayıt**: Hasta bilgileri uluslararası HL7 formatında bir dosyaya yazılır.
- **Menü Sistemi**: Kullanıcı dostu menü ile hasta ekleme ve çıkış işlemleri yapılabilir.

## 🏥 Kullanım Talimatları

### 1️⃣ Derleme ve Çalıştırma
Kod dosyanızı bir C derleyicisi ile derlemek için aşağıdaki komutu kullanabilirsiniz:
```bash
gcc hospital_er.c -o hospital_er
./hospital_er
```

### 2️⃣ Kullanım
1. Program çalıştırıldığında bir menü görüntülenir.
2. **Yeni Hasta Ekle** seçeneği ile hasta bilgileri girilir.
3. Hasta öncelik durumu hesaplanır ve HL7 formatında kaydedilir.
4. **Çıkış** seçeneği ile programdan çıkılabilir.

## 📄 HL7 Formatında Kayıt Örneği
```
MSH|^~\&|HOSPITAL|ER|LAB|202503110800||ADT^A01|00123|P|2.5
PID|1|00123||Doe^John||72|M|||Kritik
PV1|1|E|ER^01^A^HOSPITAL|5|
RXE|75634|Recete Bilgisi Buraya Yazilabilir|
```

## 🛠 Gereksinimler
- **C Programlama Dili**
- **GCC veya benzeri bir C derleyicisi**
- **Bir metin editörü (VS Code, Code::Blocks, vb.)**

## 📌 Geliştirme
Bu proje geliştirilmeye açıktır. Eklenebilecek özellikler:
- Hasta kayıtlarını bir veri tabanında saklama
- Daha gelişmiş hasta öncelik algoritmaları
- Hasta bilgilerini görüntüleme ve düzenleme seçenekleri

**📌 Katkılarınızı bekliyoruz!** 🚀

