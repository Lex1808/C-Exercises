char *duplicate(char *str) {
    char *copyString;
    
    copyString = malloc(strlen(str) + 1);
    if (copyString == NULL) {
        fprintf(stderr, "Memory allocate failure.");
        exit(EXIT_FAILURE);
    }
    strcpy(copyString, str);

    return copyString;
}
