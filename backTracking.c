#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
int* p; //mang p
int n;  //so phan tu cua mang
int soHoanVi = 0;   //so nghiem
int UCV(int j, int k) {      //xem ung cu vien j co xep vao vi tri k duoc khong?
    if (j == k) {
        return 0;
    } else {
        for (int i = 1; i < k; i++) {
            if (j == p[i - 1]) {
                return 0;
            }
        }
        return 1;
    }
}
void GhiKQ() {    //show ket qua
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
}

void HoanVi(int i) {     //backtrack
    for (int j = 1; j <= n; j++) {
        if (UCV(j, i)) {
            p[i - 1] = j;
            if (i == n) {
                GhiKQ();
                soHoanVi++;
            } else {
                HoanVi(i + 1);
            }
        }
    }
}
int main() {
    printf("Dem so hoan vi. Nhap n: ");
    scanf("%d", &n);
    p = malloc(n * sizeof(int));
    HoanVi(1);
    printf("so hoan vi: %d",soHoanVi);
    free(p);
    return 0;
}
