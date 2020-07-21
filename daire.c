
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define PI 3.14

float yariCap;                      //global degisken 

void* thread1(void* param) {                //void* parametre geri d�nd�r�yor void*parametle al�yoruz

    static  float cevre;
    cevre = 2 * PI * yariCap;
    printf("darinein cevresi:%.2f", cevre);
    printf("cm\n");

}
void* thread2(void* param) {
    static float alan;

    alan = PI * yariCap * yariCap;
    sleep(1);                                      //alani yazd�rmadan �nce 1 sn bekledik
    printf("dairenin alani :%.2f", alan);
    printf("cm\n");

}
int main()
{
    printf("yaricapi giriniz(cm)");
    scanf("%f", &yariCap);

    pthread_t t1;                                   //therad t�r�ndeki de�i�kenler
    pthread_t t2;

    pthread_create(&t1, NULL, thread1, NULL);  //Olu�turmak istedi�imiz thread,�zelliklerin al�naca�� de�i�ken ,thread ortam�nda �al��t�r�lmas� istenen fonksiyonun ad�,fonksiyona g�nderilmesi istenen parametre
    pthread_create(&t2, NULL, thread2, NULL);

    //thread'ler birbirlerini bekliyor 
    pthread_join(t1, NULL);                          // thredin adi,geri d�n�� de�eri olsun mu olmas�n m� yada nereye kaydedilsin
    pthread_join(t2, NULL);

    return 0;
}