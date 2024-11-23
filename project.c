#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 700


void symgen(int n, int m[max][max]) {
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i == j) {
                m[i][j] = 1;
            } else {
                int value = rand() % 2;
                m[i][j] = value;
                m[j][i] = value;
            }
        }
    }
}
void antisymgen(int n, int m[max][max]) {
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                m[i][j] = 0;
            } else {
                int value = rand() % 2;
                m[i][j] = value;
                m[j][i] = 1 - value;
            }
        }
    }
}
void trangen(int n, int m[max][max]) {
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                m[i][j] = 1;
            } else {
                m[i][j] = rand() % 2;
            }
        }
    }


    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (m[i][k] == 1 && m[k][j] == 1) {
                    m[i][j] = 1;
                }
            }
        }
    }
}


void printm(int n, int m[max][max]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}


int symmetricm(int n,int m[max][max]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] != m[j][i]) {
                return 0;
            }
        }
    }

    return 1;

}

int anti_symmetric(int n, int m[max][max]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] && m[j][i] && i != j) {

                return 0;
            }
        }
    }

    return 1;

}
int transitive(int n, int m[max][max]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (m[i][j] && m[j][k] && !m[i][k]) {

                    return 0;
                }
            }
        }
    }

    return 1;
}

int equivalence(int n, int m[][max]) {
    return symmetricm(n,m) && transitive(n,m);
}


int function(int n, int m[max][max]) {
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (m[i][j]) {
                count++;
            }
        }
        if (count != 1) {
            return 0;
        }
    }
    return 1;
}


int main () {
 int n;
  clock_t start,end;
  double cpu_time_m;
  double cpu_time_f;
    start=clock();


 printf("Enter the dimension value(n):");
 scanf("%d",&n);
 int m[max][max];
srand(time(NULL));
    int x=rand()% 3;

     switch(x) {
    case 0 :
    symgen(n,m);
    break;
    case 1 :
    antisymgen(n,m);
    break;
    case 2 :
    trangen(n,m);
    break;

    }

    printf("\nRandom Matrix:");
    printf("\n---------------\n\n");
    printm(n,m);


printf("\nVerifying the relation metrix:");
printf("\n------------------------------\n\n");

printf("The dimension of the metrix is : %d\n\n",n);

    if (symmetricm(n, m)) {
        printf("The relation is symmetric.\n");
    } else {
        printf("The relation is not symmetric.\n");
    }

    if (anti_symmetric(n,m)) {
        printf("The relation is anti-symmetric.\n");
    } else {
        printf("The relation is not anti-symmetric.\n");
    }

    if (transitive(n, m)) {
        printf("The relation is transitive.\n");
    } else {
        printf("The relation is not transitive.\n");
    }

    if (equivalence(n,m)) {
        printf("The relation is an equivalence relation.\n");
    } else {
        printf("The relation is not an equivalence relation.\n");
    }
    end = clock();
    cpu_time_m = ((double) (end - start)) / CLOCKS_PER_SEC;


     start=clock();
     if (function(n,m)) {
        printf("The relation represents a function.\n");
    } else {
        printf("The relation does not represent a function.\n");
    }

    end = clock();
    cpu_time_f = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\nComputation Time:");
printf("\n------------------\n\n");
    printf("verification time for relation: %.2f milliseconds\n", cpu_time_m * 1000);
    printf("verification time for function: %.2f milliseconds\n", cpu_time_f * 1000);

return 0;
}
