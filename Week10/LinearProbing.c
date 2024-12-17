#include <stdio.h>
#define MAX 100

struct Employee {
    int k;
    char n[50];
};

struct Employee ht[MAX];
int ts;

void init() {
    for (int i = 0; i < MAX; i++) ht[i].k = -1;
}

int hash(int k) {
    return k % ts;
}

void insert(int k, char n[]) {
    int idx = hash(k);
    while (ht[idx].k != -1) {
        idx = (idx + 1) % ts;
    }
    ht[idx].k = k;
    for (int i = 0; n[i] != '\0' && i < 49; i++) {
        ht[idx].n[i] = n[i];
    }
    ht[idx].n[49] = '\0';
}

void display() {
    for (int i = 0; i < ts; i++) {
        if (ht[i].k != -1)
            printf("Idx %d: Key = %d, Name = %s\n", i, ht[i].k, ht[i].n);
        else
            printf("Idx %d: Empty\n", i);
    }
}

int main() {
    int n;
    printf("Enter table size (max size %d): ", MAX);
    scanf("%d", &ts);

    if (ts > MAX) ts = MAX;

    init();

    printf("Enter number of employees: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        int k;
        char name[50];
        printf("Enter key and name for employee %d: ", i + 1);
        scanf("%d", &k);
        getchar();
        gets(name);
        insert(k, name);
    }

    display();

    return 0;
}
