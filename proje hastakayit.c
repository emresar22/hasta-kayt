#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ?? Hasta bilgilerini saklayan yap� (struct)
typedef struct {
    char id[10];        // Hasta kimlik numaras�
    char name[50];      // Hasta ad�
    char surname[50];   // Hasta soyad�
    int age;            // Ya�
    char gender;        // Cinsiyet (M/F)
    char status[20];    // Hastan�n sa�l�k durumu (Hafif, Orta, Kritik)
    int prescriptionNo; // Re�ete numaras�
    int priority;       // �ncelik puan� (Y�ksek puan = �ncelikli hasta)
} Patient;

// ?? Rastgele re�ete numaras� �reten fonksiyon
int generatePrescription() {
    return rand() % 100000 + 1000;  // 1000 ile 99999 aras�nda rastgele re�ete numaras� �retir
}

// ?? Hastan�n aciliyet �nceli�ini hesaplayan fonksiyon
int calculatePriority(int age, char *status) {
    int score = 0;

    // 65 ya� �st� hastalar ekstra �ncelik al�r
    if (age >= 65) {
        score += 2;
    }

    // Hastan�n sa�l�k durumuna g�re puan eklenir
    if (strcmp(status, "Kritik") == 0) {
        score += 3;
    } else if (strcmp(status, "Orta") == 0) {
        score += 2;
    } else {
        score += 1;
    }

    return score;  // En y�ksek puana sahip hastalar �ncelikli olarak s�ralan�r
}

// ?? Hastay� HL7 format�nda dosyaya kaydeden fonksiyon
void saveHL7(Patient patient) {
    FILE *file = fopen("hl7_kayit.txt", "a");  // Dosyay� ekleme modunda a�
    if (!file) {
        printf("Dosya a�ma hatas�!\n");
        return;
    }

    // HL7 format�nda hasta kayd�n� dosyaya yaz
    fprintf(file, "MSH|^~\\&|HOSPITAL|ER|LAB|202503110800||ADT^A01|%s|P|2.5\n", patient.id);
    fprintf(file, "PID|1|%s||%s^%s||%d|%c|||%s\n",
            patient.id, patient.surname, patient.name, patient.age, patient.gender, patient.status);
    fprintf(file, "PV1|1|E|ER^01^A^HOSPITAL|%d|\n", patient.priority);
    fprintf(file, "RXE|%d|Recete Bilgisi Buraya Yazilabilir|\n", patient.prescriptionNo);

    fclose(file);  // Dosyay� kapat
    printf("\n? Hasta bilgileri HL7 format�nda kaydedildi!\n");
}

// ?? Kullan�c�dan hasta bilgilerini alarak yeni hasta ekleyen fonksiyon
void addPatient() {
    Patient newPatient;
    
    // Kullan�c�dan hasta bilgilerini al
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
    
    // Re�ete numaras� �ret ve �ncelik puan�n� hesapla
    newPatient.prescriptionNo = generatePrescription();
    newPatient.priority = calculatePriority(newPatient.age, newPatient.status);

    // Hastay� HL7 format�nda dosyaya kaydet
    saveHL7(newPatient);
}

// ?? Program�n ana fonksiyonu (Men� Sistemi)
int main() {
    printf(" **Acil Servis Y�netim Sistemi** \n");
    
    while (1) {
        int choice;
        printf("\n1 - Yeni Hasta Ekle\n2 - Cikis\nSecim: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            addPatient();  // Yeni hasta ekleme i�lemi
        } else if (choice == 2) {
            printf(" Sistemden cikiliyor...\n");
            break;
        } else {
            printf(" Gecersiz secim! Lutfen tekrar deneyin.\n");
        }
    }
    
    return 0;
}

