#include <stdio.h>
#include <string.h>

#define MAX_M 105
#define MAX_LEN 64

int find(int idx, char dict[MAX_M][MAX_LEN], char book[MAX_LEN]) {
    for(int i = 0; i < idx; ++i) {
        if(strcmp(dict[i], book) == 0) {
            return i;
        }
    }
    return idx;
}

int main(void) {

#ifdef DEBUG
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
#endif

    int m;
    scanf("%d", &m);

    int author_idx = 0;
    char authors[MAX_M][MAX_LEN] = {0};
    char books[MAX_M][MAX_LEN] = {0};
    int book_to_author[MAX_M] = {0};

    for(int i = 0; i < m; ++i) {
        char input[MAX_LEN] = {0};
        scanf("%s%s", input, books[i]);
        int n = find(author_idx, authors, input);
        if(n == author_idx) {
            strcpy(authors[author_idx], input);
            author_idx++;
        }
        book_to_author[i] = n;
    }

#ifdef DEBUG
    printf("Read author-book successfully!\n");
#endif

    int sells[MAX_M] = {0};

    for(int i = 0; i < m; ++i) {
        char input[MAX_LEN] = {0};
        int se;
        scanf("%s%d", input, &se);
        int n = find(m, books, input);
        sells[book_to_author[n]] += se;
    }

    char most_popular[MAX_LEN] = {0};
    int max_sell = 0;
    for(int i = 0; i < author_idx; ++i) {
        if(
            max_sell < sells[i] || 
            (max_sell == sells[i] && strcmp(most_popular, authors[i]) > 0)
        ) {
            strcpy(most_popular, authors[i]);
            max_sell = sells[i];
        }
    }

    printf("%s %d\n", most_popular, max_sell);
    return 0;
}