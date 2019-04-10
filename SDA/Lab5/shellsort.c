#include <stdio.h>

#define MAX 7

int intArray[MAX] = {9,3,1,5,6,4,7};


void showOff() {
   int i;
   for(i = 0;i < MAX;i++) {
      printf("%d ",intArray[i]);
   }
}

void shellSort() {
   int inner, outer;
   int valueToInsert;
   int interval = 1;   
   int elements = MAX;
   int i = 0;
   
   while(interval <= elements/3) {
      interval = interval*3 +1;
   }

   while(interval > 0) {
      for(outer = interval; outer < elements; outer++) {
         valueToInsert = intArray[outer];
         inner = outer;
			
         while(inner > interval -1 && intArray[inner - interval] 
            >= valueToInsert) {
            intArray[inner] = intArray[inner - interval];
            inner -=interval;
         }
         
         intArray[inner] = valueToInsert;
      }
		
      interval = (interval -1) /3;
      i++;
   }          
}

int main() {
   printf("\nInitial: ");
   showOff();
   shellSort();
   printf("\nSorted: ");
   showOff();
   return 1;
}