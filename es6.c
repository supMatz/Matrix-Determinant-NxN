#include <stdio.h>
#define N 50

/* Data una matrice n*n restituire il determinante della matrice
 *
 * esempio esecuzione :
 * Dimensione : 2
 * Matrice :   1 2 3 4
 *             3 4 4 4
 *             2 1 4 4
 *
 * Determinante = -2
 */
long det(int A[N][N], int n) {
    int M[N][N];            /* spazio per il minore */
    int i, j, k, col, sign;
    long result;

    if (n == 1)
        return result;
    if (n == 2)
        return (long)A[0][0] * A[1][1] - (long)A[0][1] * A[1][0];

    result = 0;
    sign = 1;

    for(col = 0; col < n; col++){ /* parto dalla prima colonna  */
        for(i = 1; i < n; i++) { /*  parto dalla seconda colonna */
            k = 0;
            for(j = 0; j < n; j++) {
                if(j != col) {
                    M[i - 1][k] = A[i][j];
                    k++;
                }
            }
        }
        result += sign * A[0][col] * det(M, n-1);
        sign *= -1; /* ogni volta che cambio colonna inverto il segno */
    }

    return result;
}

int main(void) {
    int A[N][N];
    short dim, i, j;

    do {
        printf("[INPUT] Inserire N : ");
        if (scanf("%hd", &dim) != 1) {
            printf("[ERRORE] : valore non valido\n");
            return 1;
        }
    } while (dim <= 0 || dim > N);

    printf("[INPUT] Inserire la matrice %hd x %hd : ", dim, dim);
    for (i = 0; i < dim; i++) {
        for (j = 0; j < dim; j++) {
            if (scanf("%d", &A[i][j]) != 1) {
                printf("[ERRORE] : Cifra non valida in A[%d][%d]\n", i, j);
                return 1;
            }
        }
    }

    printf("[OUTPUT] Determinante = %ld\n", det(A, dim));
    return 0;
}
