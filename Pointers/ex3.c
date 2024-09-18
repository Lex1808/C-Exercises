int *create_array(int n, int initial_value) {
    int *parray;

    parray = malloc(n * sizeof(int));
    if(parray == NULL) {
        fprintf(stderr, "Memory allocated error.");
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        parray[i] = initial_value;
    }

    return parray;
}
