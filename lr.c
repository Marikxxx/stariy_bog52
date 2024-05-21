#include "lr.h"
#define MAX_LENGTH 1000
#define SIZE 10
#define size1 3
#define size2 3

int sqroot(int num) {
    int x = num;
    int y = 0;
    while (1) {
        y = (x + num / x) / 2;
        if (x - y < 1)
            break;
        x = y;
    }
    return y;
}

void sort( int arr[][size2]) {
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2 - 1; j++) {
            int min_index = j;
            for (int k = j + 1; k < size2; k++) {
                if (arr[i][k] < arr[i][min_index]) {
                    min_index = k;
                }
            }
            // Меняем местами элементы j и min_index
            int temp = arr[i][j];
            arr[i][j] = arr[i][min_index];
            arr[i][min_index] = temp;
        }
    }
}
int laba1() {
    int a = 1, b = 4, c = 3, discriminant, x1, x2; // x^2 + 4x + 3 = 0
         discriminant = b * b - 4 * a * c;
         x1 = (-b + sqroot(discriminant)) / (2 * a);
    x2 = (-b - sqroot(discriminant)) / (2 * a);
    printf("%d, %d", x1, x2);
    return 0; }
 // n1/(n+1)^2 + n2/(n+1)^2 + ...
int laba2() {
    float sum = 0, rowElement = 1.0, eps;
    int numerator, denominator, n = 1, i;
    printf("eps = ");
    scanf("%f", &eps);
    printf("i = ");
    scanf("%d", &i);
    while (rowElement > eps && n <= i) {
        numerator = n;
        denominator = (n + 1) * (n + 1);
        rowElement = (float)numerator / denominator;
        sum += rowElement;
        n++;
    }
     printf("%f", sum);
     return 0;

}
int laba3() {
    char str[MAX_LENGTH];
    char longest_word[MAX_LENGTH];
    char shortest_word[MAX_LENGTH];
    char current_word[MAX_LENGTH] = "";
    int max_len = 0;
    int min_len = MAX_LENGTH;
    int current_len = 0;
    int i = 0;

    //printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);

    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\r' && str[i] != '\0') {
            current_word[current_len] = str[i];
            current_len++;

        } else {
            if (current_len > max_len) {max_len = current_len;
                for (int j = 0; j < current_len; j++) {
                    longest_word[j] = current_word[j];
                }longest_word[current_len] = '\0';
            }if (current_len < min_len && current_len > 0) {
                min_len = current_len;                for (int j = 0; j < current_len; j++) {
                    shortest_word[j] = current_word[j];                }
                shortest_word[current_len] = '\0';
                }
            current_len = 0;
            for (int j = 0; j < MAX_LENGTH; j++) {
                current_word[j] = '\0';            }
        }        i++;
    }
    printf("Самое длинное слово: %s\n", longest_word);
    printf("Самое короткое слово: %s\n", shortest_word);
    return 0;
}
int laba4() {
    char str[1000];
    int i, j;
    //printf("Введите строку: ");
    fgets(str, sizeof(str), stdin);
    // Убираем цифры
    for(i = 0, j = 0; str[i] != '\0'; i++){
        if(!(str[i] >= '0' && str[i] <= '9')){
            str[j++] = str[i]; // переносим символ в новую позицию
        }
    }
    str[j] = '\0'; // добавляем ноль в конец, чтобы обозначить конец строки
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] == ' '){
            str[i] = '\n';
        }    }
    printf("Результат: %s", str);
    return 0;
}


int laba5() {
    int arr[SIZE];
    int first_half_sum = 0, second_half_sum = 0;
    int i;

    printf("Введите элементы массива: ");
    for (i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < SIZE; i++) {
        if (i < SIZE / 2) {
            first_half_sum += arr[i];
        } else {
            second_half_sum += arr[i];
        }
    }

    for (i = 0; i < SIZE; i++) {
        if ((first_half_sum < second_half_sum && i < SIZE / 2) || (first_half_sum >= second_half_sum && i >= SIZE / 2)) {
            arr[i] = 0;
        }
    }

    // Выводим измененный массив
    printf("Результат: ");
    for (i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

int laba6() {
    int N, K, i, j;

    // Ввод размеров массива
    //printf("Введите количество строк (N): ");
    //scanf("%d", &N);
    //printf("Введите количество столбцов (K): ");
    //scanf("%d", &K);

    int arr[size1][size2];

    // Ввод элементов массива
    printf("Введите элементы массива:\n");
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    // Поиск минимального и максимального элементов и их строки
    int min_val = arr[0][0], max_val = arr[0][0];
    int min_row = 0, max_row = 0;
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr[i][j] < min_val) {
                min_val = arr[i][j];
                min_row = i;
            }
            if (arr[i][j] > max_val) {
                max_val = arr[i][j];
                max_row = i;
            }
        }
    }

    // Обнуление элементов, кроме строки с min и max
    if (min_row == max_row) { // Если min и max в одной строке
        for (int i = 0; i < size1; i++) {
            if (i != min_row) {
                for (int j = 0; j < size2; j++) {
                    arr[i][j] = 0;
                }
            }
        }
    } else { // Если min и max в разных строках, обнуляем весь массив
        for (int i = 0; i < size1; i++) {
            for (int j = 0; j < size2; j++) {
                arr[i][j] = 0;
            }
        }
    }

    sort(arr);

    // Вывод измененного массива
    printf("Измененный массив:\n");
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}

int laba7() {
long int N;
printf("Введите большое целое число: ");
scanf("%ld", &N);
for(int i = 0; i < sizeof(long int); i++) {
    int count = 0;
    unsigned char byte = (N >> (i * 8)) & 0xFF;
    for(int j = 0; j < 8; j++) {
        if(byte & 1) {
            count++;
        }
        byte >>= 1;
    }
    printf("Количество единиц в байте %d: %d\n", i, count);
}

return 0;
}
