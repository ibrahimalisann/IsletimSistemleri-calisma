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



const int SIZE=4096;

void *ptr;

//paylasılan bellek nesnesi olustur
shm_fd=shm_open(name,0_RDONLY, 0666);



ptr = mmap(0,SIZE,PROT_READ,MAP_SHARED,shm_fd,0);

printf("%s\n",(char *)ptr);             //ptr nin göstermiş olduğu alanı ekrana direkt yazıcak

 shm_unlink(name);             	     // açmış olduğunu paylaşılan bellek kısmını geriye vermiş olacak
return 0;
}