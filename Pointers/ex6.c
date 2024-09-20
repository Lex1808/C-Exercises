struct node {
    int value;
    struct node *next;
};
struct node *first = NULL;

int count_occurrences(struct node *list, int n) {
    struct node *p;
    int count = 0;
    for (p = list; p != NULL; p = p->next) {
        if (p->value == n) {
            count++;
        }
    }
    return count;
}
