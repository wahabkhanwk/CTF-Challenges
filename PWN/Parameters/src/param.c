// pwn_parameters.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>

__attribute__((constructor))
void __constructor__(){
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
    alarm(0x10);
}

void win(uint32_t param_1, uint32_t param_2) {
    if (param_1 == 0xF23A && param_2 == 0xC1F) {
        FILE *fp = fopen("flag.txt", "r");
        if (fp == NULL) {
            perror("flag.txt not found");
            exit(1);
        }

        char flag[100];
        fgets(flag, sizeof(flag), fp);
        fclose(fp);

        printf("You win! Here's your flag: %s", flag);
    } else {
        puts("Wrong parameters!");
    }
}

void vuln() {
    char buffer[180];
    printf("Hope You Know How to Exploit 32-Binary \n");
    fflush(stdout);
    read(0, buffer, 512);
}

int main() {
    vuln();
    return 0;
}

