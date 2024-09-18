void *my_malloc(size_t size) {
    size_t *p = malloc(size);
    if(p == NULL) {
        fprintf(stderr, "Error memory alocated;");
        exit(EXIT_FAILURE);
    }
    return p;
}
