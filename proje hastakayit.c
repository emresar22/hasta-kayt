#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ?? Hasta bilgilerini saklayan yapý (struct)
typedef struct {
    char id[10];        // Hasta kimlik numarasý
    char name[50];      // Hasta adý
    char surname[50];   // Hasta soyadý
    int age;            // Yaþ
    char gender;        // Cinsiyet (M/F)
    char status[20];    // Hastanýn saðlýk durumu (Hafif, Orta, Kritik)
    int prescriptionNo; // Reçete numarasý
    int priority;       // Öncelik puaný (Yüksek puan = Öncelikli hasta)
} Patient;

// ?? Rastgele reçete numarasý üreten fonksiyon
int generatePrescription() {
    return rand() % 100000 + 1000;  // 1000 ile 99999 arasýnda rastgele reçete numarasý üretir
}

// ?? Hastanýn aciliyet önceliðini hesaplayan fonksiyon
int calculatePriority(int age, char *status) {
    int score = 0;

    // 65 yaþ üstü hastalar ekstra öncelik alýr
    if (age >= 65) {
        score += 2;
    }

    // Hastanýn saðlýk durumuna göre puan eklenir
    if (strcmp(status, "Kritik") == 0) {
        score += 3;
    } else if (strcmp(status, "Orta") == 0) {
        score += 2;
    } else {
        score += 1;
    }

    return score;  // En yüksek puana sahip hastalar öncelikli olarak sýralanýr
}

// ?? Hastayý HL7 formatýnda dosyaya kaydeden fonksiyon
void saveHL7(Patient patient) {
    FILE *file = fopen("hl7_kayit.txt", "a");  // Dosyayý ekleme modunda aç
    if (!file) {
        printf("Dosya açma hatasý!\n");
        return;
    }

    // HL7 formatýnda hasta kaydýný dosyaya yaz
    fprintf(file, "MSH|^~\\&|HOSPITAL|ER|LAB|202503110800||ADT^A01|%s|P|2.5\n", patient.id);
    fprintf(file, "PID|1|%s||%s^%s||%d|%c|||%s\n",
            patient.id, patient.surname, patient.name, patient.age, patient.gender, patient.status);
    fprintf(file, "PV1|1|E|ER^01^A^HOSPITAL|%d|\n", patient.priority);
    fprintf(file, "RXE|%d|Recete Bilgisi Buraya Yazilabilir|\n", patient.prescriptionNo);

    fclose(file);  // Dosyayý kapat
    printf("\n? Hasta bilgileri HL7 formatýnda kaydedildi!\n");
}

// ?? Kullanýcýdan hasta bilgilerini alarak yeni hasta ekleyen fonksiyon
void addPatient() {
    Patient newPatient;
    
    // Kullanýcýdan hasta bilgilerini al
    printf("Hasta Kimlik No: ");
    scanf("%s", newPatient.id);
    
    printf("Adi: ");
    scanf("%s", newPatient.name);
    
    printf("Soyadi: ");
    scanf("%s", newPatient.surname);
    
    printf("Yasi: ");
    scanf("%d", &newPatient.age);
    
    printf("Cinsiyeti (M/F): ");
    scanf(" %c", &newPatient.gender);
    
    printf("Hastalik Durumu (Hafif/Orta/Kritik): ");
    scanf("%s", newPatient.status);
    
    // Reçete numarasý üret ve öncelik puanýný hesapla
    newPatient.prescriptionNo = generatePrescription();
    newPatient.priority = calculatePriority(newPatient.age, newPatient.status);

    // Hastayý HL7 formatýnda dosyaya kaydet
    saveHL7(newPatient);
}

// ?? Programýn ana fonksiyonu (Menü Sistemi)
int main() {
    printf(" **Acil Servis Yönetim Sistemi** \n");
    
    while (1) {
        int choice;
        printf("\n1 - Yeni Hasta Ekle\n2 - Cikis\nSecim: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            addPatient();  // Yeni hasta ekleme iþlemi
        } else if (choice == 2) {
            printf(" Sistemden cikiliyor...\n");
            break;
        } else {
            printf(" Gecersiz secim! Lutfen tekrar deneyin.\n");
        }
    }
    
    return 0;
}

