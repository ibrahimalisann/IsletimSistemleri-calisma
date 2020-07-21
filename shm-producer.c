//sprintf
#include <stdio.h>
//shm open
#include <sysman.h>
#include <sys/stat.h>
#include <fcntl.h>

//frtruncate metodu
#include <unistd.h>
#include <sys/types.h>

//strlen
#include <string.h>

int main(){

int shm_fd;
char *name="/OS";

char *mesaj_0="merhaba";

char *mesaj_1="dünya ";

const int SIZE=4096;

void *ptr;

//paylasılan bellek nesnesi olustur
shm_fd=shm_open(name,0_CREAT | 0_RDWR, 0666);

ftruncate(shm_fd,SIZE);

ptr = mmap(0,SIZE,PROT_WRITE,MAP_SHARED,shm_fd,0)

sprintf(ptr ,"%s" ,mesaj_0);
ptr+=strlen(mesaj_0)               //boyutu kadar kaydır

sprintf(ptr ,"%s" ,mesaj_1);
ptr+=strlen(mesaj_1)               //boyutu kadar kaydır


return 0;
}