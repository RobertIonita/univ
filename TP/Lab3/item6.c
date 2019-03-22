#include <stdio.h>

#define MAX 100

typedef struct {
    char row[MAX];
} text;

typedef struct {
    char word[MAX];
} line;


int read(text *t) {
    FILE * f;
    int i = 0;
    if ((f = fopen("TP/Lab3/item6.txt", "rt")) == NULL) {
        printf("error");
    } else {
        while (!feof(f)) {
            fscanf(f, "%s", t[i].row);
            i++;
        }
        fclose(f);
    }
    return i;
}

char separators[] = ",.;!";

int matches(char str[4], char ch) {
    int i;

    for (i = 0;  i < 4; i++) {
        if ( str[i] == ch) return 1;
    }
    return 0;
}

int split(text *t, line *str, int n) {
    int i, j,
        count = 0, letter = 0;
    if (matches(separators, t[0].row[0])) count--;

    for(i = 0; i < n; i++) {
        for(j = 0; t[i].row[j] != '\0'; j++) {
            if ( matches(separators, t[i].row[j]) ) {
                count++;
                letter = 0;
            } else {
                str[count].word[letter++] = t[i].row[j];
            }
        }
    }
    if ( matches(separators, t[i-1].row[j-1]) ) {
        return count;
    } else {
        return count+1;
    }
}

int compare(char (*first)[], char (*second)[]) {
    int i;
    for (i = 0; (*first)[i] != '\0' || (*second)[i] != '\0'; i++) {

        if ( (*first)[i] < (*second)[i]) {
            return 1;
        } else if ( (*first)[i] > (*second)[i]) {
            return -1;
        }
    }
    return 0;
}

void showOff(line *t, int n) {
    printf("\n%s",
        t[n].word
    );
}

void sort(line *words, int counter) {
    int i, sorted;
    line clone;
    do {
        sorted = 1;
        for (i = 0; i < counter; i++) {
            if (compare(&words[i].word, &words[i + 1].word) < 0) {
                sorted = 0;
                clone = words[i];
                words[i] = words[i + 1];
                words[i + 1] = clone;
            }
        }
    } while (!sorted);
}
void delete(line *words, int *counter, char (*desired)[]) {
    int i, j;
    for (i = 0; i <= *counter; i++) {
        if (compare(&words[i].word, desired) == 0) {
            (*counter)--;
            for (j = i++; j <= *counter; j++) {
                words[j] = words[j + 1];
            }
            i--;
        }
    }
}


void removeDublicated(line * words, int *counter) {
    int clean = 0,
        i;
    for(i = 0; i < *counter; i++) {
        if (compare(&words[i].word, &words[i+1].word) == 0) {
            delete(words, counter, &words[i].word);
        }
    }
    
}



int main(void) {
    text main_row[MAX];
    line main_line[MAX];

    int nr, i,
        count;

    nr = read(main_row);
    count = split(main_row, main_line, nr);

    sort(main_line, count);
    removeDublicated(main_line, &count);

    for (i = 0; i <= count; i++) {
        showOff(main_line, i);
    }
}