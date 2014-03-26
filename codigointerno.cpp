#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <signal.h>

using namespace std;

int cont = 0;

void pintar (int sig) {
  if(cont == 0) {
    cont = 2;
  }
  else if(cont == 1) {
    cont = 0;
  }
  else if(cont == 2) {
    cont = 1;
  }
}

int main () {
   signal(SIGUSR1, pintar);
   //Criando o filho
   pid_t idProcesso;
   idProcesso = fork();
   switch(idProcesso) {
   case -1:
       cout << "O programa nao funcionou corretamente!" << endl;
       exit(1);
       break;
   case 0:
       //Processo filho
       while(1) {
           if (cont == 0) {
              cout << "Vermelho" << endl;
           }
           else if (cont == 1) {
              cout << "Amarelo" << endl;
           }
           else {
              cout << "Verde" << endl;
           }
           sleep(1);
       }
       exit(0);
       break;
   default:
       //Processo pai
       kill(idProcesso, SIGUSR1);
       while(1) {
           sleep(4);
           kill(idProcesso, SIGUSR1);
           sleep(2);
           kill(idProcesso, SIGUSR1);
           sleep(3);
           kill(idProcesso, SIGUSR1);
       }
   }
   cout << "O programa finalizou!" << endl;
}