
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define PI 3.14

float yariCap;                      //global degisken 

void* thread1(void* param) {                //void* parametre geri döndürüyor void*parametle alýyoruz

    static  float cevre;
    cevre = 2 * PI * yariCap;
    printf("darinein cevresi:%.2f", cevre);
    printf("cm\n");

}
void* thread2(void* param) {
    static float alan;

    alan = PI * yariCap * yariCap;
    sleep(1);                                      //alani yazdýrmadan önce 1 sn bekledik
    printf("dairenin alani :%.2f", alan);
    printf("cm\n");

}
int main()
{
    printf("yaricapi giriniz(cm)");
    scanf("%f", &yariCap);

    pthread_t t1;                                   //therad türündeki deðiþkenler
    pthread_t t2;

    pthread_create(&t1, NULL, thread1, NULL);  //Oluþturmak istediðimiz thread,özelliklerin alýnacaðý deðiþken ,thread ortamýnda çalýþtýrýlmasý istenen fonksiyonun adý,fonksiyona gönderilmesi istenen parametre
    pthread_create(&t2, NULL, thread2, NULL);

    //thread'ler birbirlerini bekliyor 
    pthread_join(t1, NULL);                          // thredin adi,geri dönüþ deðeri olsun mu olmasýn mý yada nereye kaydedilsin
    pthread_join(t2, NULL);

    return 0;
}