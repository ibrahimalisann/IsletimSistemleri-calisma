
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {
	int fd[2];
	int SIZE=20;
	char buf[SIZE];
	if (pipe(fd) == -1) {
		printf("pipe hata \n");
	}

	pid_t pid = fork();
		if (pid == 0) {		//Cocuk süreç kısmı
			read(fd[0], buf, SIZE);
				printf("Cocuk sürecin aldigi mesaj:%s \n", buf);
				printf("Cocuk sürecin gönderdigi mesaj:Universitesi\n");
		}else
		{
			write(fd[1], "Dumlupinar", SIZE);		//Anne sürec mesajı yazıyor

			wait(NULL);
			close(fd[1]);
			return 0;
		}
}