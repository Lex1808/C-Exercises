#include <stdio.h>
#include <ctype.h>

typedef struct Time {
    int days;
    int hours;
    int minutes;
    int seconds;
} time;

time split_time(long total_seconds) {
    time t;

    t.days = total_seconds / 86400;
    total_seconds %= 86400;
    t.hours = total_seconds / 3600;
    total_seconds %= 3600;
    t.minutes = total_seconds / 60;
    total_seconds %= 60;
    t.seconds = total_seconds;
    
    return t;
}

int main(void) {
    long seconds;
    char input_buffer[256];
    time total_time;

    while(1) {
        printf("Enter total seconds: ");
        if (fgets(input_buffer, sizeof(input_buffer), stdin) == NULL) {
            fprintf(stderr, "Input is too long\n");
            return -1;
        }

        int valid_number = 1;
        for(int i = 0; input_buffer[i] != '\n'; i++) {
            if(!isdigit(input_buffer[i])) {
                valid_number = 0;
            }
        }

        if (valid_number && sscanf(input_buffer, "%ld", &seconds) == 1) {
            total_time = split_time(seconds);
            break;
        } else {
            fprintf(stderr, "Invalid number. Enter only digits\n");
        }
    }
    
    printf("Convert to time format(Days:hours:minutes:seconds)\n");
    printf("Day: %d, %02d:%02d:%02d\n", total_time.days, total_time.hours, total_time.minutes, total_time.seconds);

    return 0;

}
