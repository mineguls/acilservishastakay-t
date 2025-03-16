#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_HASTA 100

// Hasta yapýsý
typedef struct {
    char isim[50];
    int yas;
    int oncelik; // 1: Yüksek, 2: Orta, 3: Düþük
    int recete_no;
} Hasta;

// Hastalarý öncelik sýrasýna göre sýralayan fonksiyon (Bubble Sort)
void hastalariSirala(Hasta hastalar[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (hastalar[j].oncelik > hastalar[j + 1].oncelik) { // Küçük olan öne gelsin
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

    srand(time(NULL)); // Rastgele reçete no üretimi için

    // Hasta bilgilerini alma
    for (i = 0; i < hasta_sayisi; i++) {
        printf("\n%d. Hastanin ismi: ", i + 1);
        fgets(hastalar[i].isim, sizeof(hastalar[i].isim), stdin);
        hastalar[i].isim[strcspn(hastalar[i].isim, "\n")] = 0; // Yeni satýr karakterini temizle

        printf("Yasi: ");
        scanf("%d", &hastalar[i].yas);
        getchar(); // scanf sonrasý tampon temizleme

        printf("Öncelik (1: Yüksek, 2: Orta, 3: Düþük): ");
        scanf("%d", &hastalar[i].oncelik);
        getchar(); // scanf sonrasý tampon temizleme

        hastalar[i].recete_no = rand() % 9000 + 1000; // 1000-9999 arasý reçete no
    }

    // Hastalarý öncelik sýrasýna göre sýrala
    hastalariSirala(hastalar, hasta_sayisi);

    // Sonuçlarý yazdýrma
    printf("\n--- Öncelik Sýrasýna Göre Hasta Listesi ---\n");
    for (i = 0; i < hasta_sayisi; i++) {
        printf("Ýsim: %s, Yaþ: %d, Öncelik: %d, Reçete No: %d\n", 
               hastalar[i].isim, hastalar[i].yas, hastalar[i].oncelik, hastalar[i].recete_no);
    }

    return 0;
}
