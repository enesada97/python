#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
float pi =3.14;
float yaricap=0;

void *alan(void *args){
  float alan;
  alan = pi*yaricap*yaricap;
    printf("Cemberin alani: %f\n",alan);
}

void *cevre(void *args){
  float cevre;
  cevre=(yaricap*pi)*2;
    printf("Cemberin cevresi: %f\n",cevre);
}
int main ()
{
  printf("Cemberin yaricapini giriniz:");
  scanf("%f",&yaricap);
  printf("Girdiginiz yaricap degeri: %f\n",yaricap);
  pthread_t t;
  pthread_t t2;
  
  pthread_create(&t,NULL, alan,NULL);
  pthread_create(&t2,NULL, cevre,NULL);
  pthread_exit(NULL);
}