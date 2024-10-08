/*****************************************************
 * Write a program that asks the user to enter        *
 * an international dialing code and then             *
 * looks it up in the country_codes array.            *  
 * If it finds the code, the program should           *
 * display the name of the corresponding country:     *
 * If not: the program should print an error message. *
 ******************************************************/

#include <stdio.h>
#include <ctype.h>


#define ARRAY_LEN(x) ((int)(sizeof((x)) / sizeof((x)[0])))

const struct dialog_code {
   char *country;
   int code;
} country_codes[] =
    {{"Argentina",            54}, {"Bangladesh",     889},
     {"Brazil",               55}, {"Burma (Myanmar)", 95},
     {"China",                86}, {"Colombia",        57},
     {"Congo, Dem. Rep. of", 243}, {"Egypt",           20},
     {"Ethiopia",            251}, {"France",          33},
     {"Germany",              49}, {"India",           91},
     {"Indonesia",            62}, {"Iran",            98},
     {"Italy",                39}, {"Japan",           81},
     {"Mexico",               52}, {"Nigeria",        234},
     {"Pakistan",             92}, {"Philippines",     63},
     {"Poland",               48}, {"Russia",           7},
     {"South Africa",         27}, {"South Korea",     82},
     {"Spain",                34}, {"Sudan",          249},
     {"Thailand",             66}, {"Turkey",          90},
     {"Ukraine",             380}, {"United Kingdom",  44},
     {"United States",         1}, {"Vietnam",         84}};

void enter_code(int *ptr_code) {
   char buffer[256];
   printf("Enter country code: ");
   if(fgets(buffer, sizeof(buffer), stdin) == NULL) {
      fprintf(stderr, "Invalid value\n");
      return;
   }
   int valid_num = 1;
   for (int i = 0; buffer[i] != '\n'; i++) {
      if (!isdigit(buffer[i])) {
         valid_num = 0;
         break;
      }
   }

   if (valid_num && sscanf(buffer, "%d", ptr_code) == 1) {
      return;
   }
   else {
      fprintf(stderr, "Enter only digits\n");
   }
}

int main(void) {
   int *code;
   enter_code(code);

   for (int i = 0; i < ARRAY_LEN(country_codes); i++) {
      if (country_codes[i].code == *code) {
         printf("Country: %s, Code: %d\n", country_codes[i].country, *code);
         return 0;
      }
   }

   fprintf(stderr,"Country not found\n");


   return 0;
}
