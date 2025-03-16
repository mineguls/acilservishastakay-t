#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_HASTA 100

// Hasta yap�s�
typedef struct {
    char isim[50];
    int yas;
    int oncelik; // 1: Y�ksek, 2: Orta, 3: D���k
    int recete_no;
} Hasta;

// Hastalar� �ncelik s�ras�na g�re s�ralayan fonksiyon (Bubble Sort)
void hastalariSirala(Hasta hastalar[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (hastalar[j].oncelik > hastalar[j + 1].oncelik) { // K���k olan �ne gelsin
                Hasta temp = hastalar[j];
                hastalar[j] = hastalar[j + 1];
                hastalar[j + 1] = temp;
            }
        }
    }
}

int main() {
    Hasta hastalar[MAX_HASTA];
    int hasta_sayisi, i;

    printf("Kac hasta kaydedilecek? ");
    scanf("%d", &hasta_sayisi);
    getchar(); // Tampon temizleme

    srand(time(NULL)); // Rastgele re�ete no �retimi i�in

    // Hasta bilgilerini alma
    for (i = 0; i < hasta_sayisi; i++) {
        printf("\n%d. Hastanin ismi: ", i + 1);
        fgets(hastalar[i].isim, sizeof(hastalar[i].isim), stdin);
        hastalar[i].isim[strcspn(hastalar[i].isim, "\n")] = 0; // Yeni sat�r karakterini temizle

        printf("Yasi: ");
        scanf("%d", &hastalar[i].yas);
        getchar(); // scanf sonras� tampon temizleme

        printf("�ncelik (1: Y�ksek, 2: Orta, 3: D���k): ");
        scanf("%d", &hastalar[i].oncelik);
        getchar(); // scanf sonras� tampon temizleme

        hastalar[i].recete_no = rand() % 9000 + 1000; // 1000-9999 aras� re�ete no
    }

    // Hastalar� �ncelik s�ras�na g�re s�rala
    hastalariSirala(hastalar, hasta_sayisi);

    // Sonu�lar� yazd�rma
    printf("\n--- �ncelik S�ras�na G�re Hasta Listesi ---\n");
    for (i = 0; i < hasta_sayisi; i++) {
        printf("�sim: %s, Ya�: %d, �ncelik: %d, Re�ete No: %d\n", 
               hastalar[i].isim, hastalar[i].yas, hastalar[i].oncelik, hastalar[i].recete_no);
    }

    return 0;
}
