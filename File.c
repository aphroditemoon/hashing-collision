#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TABLE_SIZE 10

typedef struct Node {
    char key[100];
    struct Node* next;
} Node;

typedef struct HashTable {
    char key[100];
    Node* chain;
} HashTable;

HashTable ht[TABLE_SIZE];

void initializationHT() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        strcpy(ht[i].key, "");
        ht[i].chain = NULL;
    }
}

int StoI(char key[]) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i++) {
        sum += key[i];
    }
    return sum;
}

int DivHash(char key[]) {
    return StoI(key) % TABLE_SIZE;
}

int MidSquareHash(char key[]) {
    int num = StoI(key);
    long square = (long)num * num;
    char str[20];
    sprintf(str, "%ld", square);

    int len = strlen(str);
    if (len < 4) return (num * num) % TABLE_SIZE; // Fallback lebih baik

    int mid = len / 2;
    int extracted = (str[mid - 1] - '0') * 10 + (str[mid] - '0');
    return extracted % TABLE_SIZE;
}

int FoldingHash(char key[]) {
    int sum = 0;
    for (int i = 0; key[i] != '\0'; i += 2) {
        int secondChar = (key[i + 1] != '\0') ? key[i + 1] : 0;
        sum += (key[i] * 10 + secondChar);
    }
    return sum % TABLE_SIZE;
}

int DigitExtractionHash(char key[]) {
    int num = StoI(key);
    char str[20];
    sprintf(str, "%d", num);

    int len = strlen(str);
    if (len < 3) return (num * 3) % TABLE_SIZE; // Fallback

    return ((str[1] - '0') * 10 + (str[2] - '0')) % TABLE_SIZE;
}

int RotatingHash(char key[]) {
    int num = StoI(key);
    return ((num << 5) | (num >> 27)) % TABLE_SIZE;
}

int keyExists(char key[], int (*hashFunction)(char[])) {
    int index = hashFunction(key);
    if (strcmp(ht[index].key, key) == 0) return 1;

    Node* temp = ht[index].chain;
    while (temp) {
        if (strcmp(temp->key, key) == 0) return 1;
        temp = temp->next;
    }
    return 0;
}

void LinearProbingInsert(char key[], int (*hashFunction)(char[])) {
    if (keyExists(key, hashFunction)) {
        printf("Key %s sudah ada dalam tabel!\n", key);
        return;
    }

    int index = hashFunction(key);
    int originalIndex = index;

    while (strcmp(ht[index].key, "") != 0) {  
        index = (index + 1) % TABLE_SIZE;  
        if (index == originalIndex) {  
            printf("Tabel penuh!\n");  
            return;  
        }  
    }  

    strcpy(ht[index].key, key);  
    printf("Key %s dimasukkan ke index %d (Linear Probing).\n", key, index);
}

void ChainingInsert(char key[], int (*hashFunction)(char[])) {
    if (keyExists(key, hashFunction)) {
        printf("Key %s sudah ada dalam tabel!\n", key);
        return;
    }

    int index = hashFunction(key);

    if (strcmp(ht[index].key, "") == 0) {  
        strcpy(ht[index].key, key);  
        printf("Key %s dimasukkan ke index %d (Chaining).\n", key, index);  
    } else {  
        Node* newNode = (Node*)malloc(sizeof(Node));  
        if (!newNode) {  
            printf("Gagal mengalokasikan memori!\n");  
            return;  
        }  
        strcpy(newNode->key, key);  
        newNode->next = ht[index].chain;  
        ht[index].chain = newNode;  
        printf("Collision! Key %s ditambahkan ke chain di index %d.\n", key, index);  
    }
}

int secondaryHash(char key[]) {
    return 7 - (StoI(key) % 7);
}

void RehashingInsert(char key[], int (*hashFunction)(char[])) {
    if (keyExists(key, hashFunction)) {
        printf("Key %s sudah ada dalam tabel!\n", key);
        return;
    }

    int index = hashFunction(key);
    int step = secondaryHash(key);
    int originalIndex = index;

    while (strcmp(ht[index].key, "") != 0) {
        index = (index + step) % TABLE_SIZE;
        if (index == originalIndex) {
            printf("Rehashing gagal, tabel penuh!\n");
            return;
        }
    }

    strcpy(ht[index].key, key);
    printf("Collision! Rehashing ke index %d.\n", index);
}

void displayHT() {
    printf("\nHash Table\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: %s", i, ht[i].key);

        if (ht[i].chain != NULL) {  
            Node* temp = ht[i].chain;  
            printf(" ->");  
            while (temp) {  
                printf(" %s", temp->key);  
                temp = temp->next;  
            }  
        }  
        printf("\n");  
    }
}

void freeMemory() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* temp = ht[i].chain;
        while (temp) {
            Node* toFree = temp;
            temp = temp->next;
            free(toFree);
        }
        ht[i].chain = NULL;
        strcpy(ht[i].key, ""); 
    }
}

int main() {
    int choice, hashChoice, collisionChoice;
    char key[100];

    initializationHT();  

    while (1) {  
        printf("Pilihlah Opsi Metode Hashing:\n");  
        printf("1. Division\n2. Mid-Square\n3. Folding\n4. Digit Extraction\n5. Rotating Hash\n6. Keluar\n");  
        printf("Masukkan pilihan anda: ");  
        scanf("%d", &hashChoice);  

        if (hashChoice == 6) break;  

        int (*hashFunction)(char[]);  
        switch (hashChoice) {  
            case 1: hashFunction = DivHash; break;  
            case 2: hashFunction = MidSquareHash; break;  
            case 3: hashFunction = FoldingHash; break;  
            case 4: hashFunction = DigitExtractionHash; break;  
            case 5: hashFunction = RotatingHash; break;  
            default: printf("Pilihan tidak sesuai.\n"); continue;  
        }  

        printf("\nPilihlah Opsi Metode Penanganan Collision:\n");  
        printf("1. Linear Probing\n2. Chaining\n3. Rehashing\n");  
        printf("Masukkan pilihan anda: ");  
        scanf("%d", &collisionChoice);  

        while (1) {  
            printf("Input key (string) atau ketik 'exit' untuk keluar: ");  
            scanf("%99s", key);  
            if (strcmp(key, "exit") == 0) break;  

            switch (collisionChoice) {  
                case 1: LinearProbingInsert(key, hashFunction); break;  
                case 2: ChainingInsert(key, hashFunction); break;  
                case 3: RehashingInsert(key, hashFunction); break;  
                default: printf("Pilihan tidak sesuai.\n"); continue;  
            }  
        }  

        displayHT();  
    }  

    freeMemory();  
    return 0;
}
