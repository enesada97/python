#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int fd1[2]; //anneden çocuğa
    int fd2[2]; //çocuktan anneye
    char message1[] = "Dumlupinar\n";
    char message2[] = "Üniversitesi\n";
    char buf[20];
    //Not:pipe tek yönlü olduğu için 2 tane tanımladık.
    pipe(fd1);
    pipe(fd2);
    int processId;
    if ((processId = fork()) == -1)
    {
        printf("hata");
    }
    if (processId == 0) //çocuk süreç
    {
        //çocuk ana sürece mesaj gönderir
        close(fd2[0]); //çocuk okuma kanalı kapat
        printf("çocuk süreç yazıyor.\n");
        write(fd2[1], message2, strlen(message2) + 1);
        //anneden gelen mesajı oku
        close(fd2[1]); //çocuk yazma kanalı kapat
        printf("çocuk süreç okuyor.\n");
        read(fd1[0], buf, sizeof(buf));
        printf("çocuk sürecin aldığı mesaj : %s\n", buf);
    }
    else //anne süreç
    {

        //anne çocuk sürece mesaj gönderir
        close(fd1[0]); //anne okuma kanalı kapat
        printf("anne süreç yazıyor.\n");
        write(fd1[1], message1, strlen(message1) + 1);
        wait(NULL);
        //çocuktan gelen mesajı oku
        close(fd2[1]); //anne yazma kanalı kapat
        printf("anne süreç okuyor.\n");
        read(fd2[0], buf, sizeof(buf));
        printf("anne sürecin aldığı mesaj : %s\n", buf);
    }
    return 0;
}