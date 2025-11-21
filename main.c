#define MAXLEN 4

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "unistd.h"

int main(void) {
    char* buffer = (char*)malloc(MAXLEN);
    char* end = buffer;
    bool ok = false;
    short int result = 0;
    do {
        printf("Inserisci numero di processi da creare: ");
        fgets(buffer, MAXLEN, stdin);
        result = (short int)strtol(buffer, &end, 10);
        if (*(end + 1) != '\0' || end == buffer) {
            ok = false;
        } else ok = true;
    } while (!ok);
    int conteggio = 1;
    printf("Processo PID: %d\n",getpid());
    printf("!! Processo originale !!\n");
    pid_t pid;
    while (conteggio < result) {
        pid = fork();
        if (pid != 0) {
            printf("Processo creato con fork. PID: %d\n", pid);
            printf("Processo originale: %d\n", getppid());
            conteggio++;
        }
    }
    return 0;
}