#include <stdio.h>
#include <stdlib.h>

struct Item {
    int value;
    int weight;
};


int compare(const void *pa, const void *pb) {
    const struct Item *a = pa, *b = pb;
    double ra = (double)a->value / a->weight;
    double rb = (double)b->value / b->weight;
    return (ra < rb) - (ra > rb);
}


double fractionalKnapsack(struct Item items[], int n, int capacity) {
    qsort(items, n, sizeof(*items), compare);

    double total = 0.0;
    int curWeight = 0;

    for (int i = 0; i < n; i++) {
        if (curWeight + items[i].weight <= capacity) {
          
            curWeight += items[i].weight;
            total += items[i].value;
        } else {
           
            int remain = capacity - curWeight;
            if (remain > 0) {
                total += ((double)items[i].value / items[i].weight) * remain;
            }
            break;
        }
    }
    return total;
}

int main() {
    int n, cap;
    printf("Enter #items and knapsack capacity: ");
    if (scanf("%d %d", &n, &cap) != 2 || n <= 0 || cap <= 0) {
        fprintf(stderr, "Invalid input\n");
        return 1;
    }

    struct Item *items = malloc(n * sizeof *items);
    if (!items) {
        perror("alloc");
        return 1;
    }

    printf("Each line: value weight\n");
    for (int i = 0; i < n; i++) {
        if (scanf("%d %d", &items[i].value, &items[i].weight) != 2 ||
            items[i].weight <= 0) {
            fprintf(stderr, "Bad item #%d\n", i + 1);
            free(items);
            return 1;
        }
    }

    double maxVal = fractionalKnapsack(items, n, cap);
    printf("Maximum obtainable value = %.6f\n", maxVal);

    free(items);
    return 0;
}

