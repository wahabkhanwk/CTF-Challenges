#include <stdio.h>
#include <string.h>

#define MAX_KEY_LEN 100
__attribute__((constructor))
void __constructor__(){
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    setbuf(stderr, NULL);
    alarm(0x10);
}
const char* correct_key = "FGzeWqLu";
const char* duplicate_keys[] = {
    "FGzeHEuo", "FGzeXQGD", "FGzeWmVL", "FGzeWMfd",
    "FGzeWURb", "FGzeWuBJ", "FGzeZQEZ", "FGzeJamV",
    "FGzeJIiH"
};
const int duplicate_key_count = sizeof(duplicate_keys) / sizeof(duplicate_keys[0]);

int is_duplicate(const char* key) {
    for (int i = 0; i < duplicate_key_count; ++i) {
        if (strcmp(key, duplicate_keys[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char key[MAX_KEY_LEN];

    printf("Welcome To ISB Police License Checker\n");
    printf("Kaala Khan Aka DK, Enter Your License:\n\n");

    // DK Art
    printf("    Aja Beta Aja     <-----   O\n");
    printf("Tu tu aj                      |\n");
    printf("      Gaya               -----|-----\n");
    printf("                              /\\ \n");
    printf("                             /  \\ \n");
    printf("           ______\n");
    printf("          /|_||_\\`.__\n");
    printf("         (   _    _ _\\\n");
    printf("         =`-(_)--(_)-'\n");
    printf("\n");

    printf("Enter Key: ");
    fgets(key, sizeof(key), stdin);
    
    // Remove trailing newline
    key[strcspn(key, "\n")] = 0;

    if (strcmp(key, correct_key) == 0) {
        printf("✅ License Verified! Here's your reward:\n");

        FILE *flag_file = fopen("flag.txt", "r");
        if (flag_file == NULL) {
            perror("❌ Could not read flag.txt");
            return 1;
        }

        char flag[256];
        fgets(flag, sizeof(flag), flag_file);
        fclose(flag_file);

        printf("🏁 Flag: %s\n", flag);
    } else if (is_duplicate(key)) {
        printf("🚨 You are Caught While Submitting a Duplicated Key! Time for Jail!\n");
    } else {
        printf("❌ Wrong Key. No Flag For You. Better Luck Next Drift.\n");
    }

    return 0;
}
