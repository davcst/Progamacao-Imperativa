#include <stdio.h>
#include <string.h>

void merge(char *arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    char *L[n1], *R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (strcmp(L[i], R[j]) <= 0) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(char *arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    char *arr[] = {
    "Maju", 
    "Davi", 
    "Bernardo", 
    "Fernanda", 
    "Ziraldo", 
    "Carlinhos",
    "Aaron", 
    "Denysson", 
    "Arnaldo", 
    "Emanuel", 
    "Felipe", 
    "Juracy", 
    "Hellena", 
    "Geroncio", 
    "Timoteo",
    "Kenia",
    "Ana",
    "Zelda",
    "Hellen",
    "Vania", 
    "Neide",
    "Andre",
    "Hendrik",
    "Alisson",
    "Jurema"
    };

    int n = 25;

    printf("Lista de strings antes da ordenação:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("\nLista de strings após a ordenação:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }

    return 0;
}