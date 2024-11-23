// Ashton Johnson 11797181
// This program plays the game "24" using an input of four integers from 1 to 10.
// It grabs the four integers and sorts them in ascending order.
// Using that array, findNext() is used to generate an array of all 24 permutations.
// calculate() is used to check all permutations with all orders of operands for a formula that yields 24.
// If a solution is found, the program types out the mathematical formula used to achieve it.
// If a sollution isn't found, it states that.

#include "permute.h"
#include <stdio.h>
#include <stdlib.h>

    //{{1, 2, 3},   (((   )  )  )
    //{1, 3, 2},    ((   )  (   ))
    //{2, 1, 3},    ((  (   ))  )
    //{2, 3, 1},    (  ((   )  ))
    //{3, 2, 1}};   (  (  (   )))

int calculate(int array[24][4], int soln[4], int ops[3], int* z) {
  for (int a=0; a<24; ++a) { //for each permutation
    double total=0;
    int zz;
    for (int i=0; i<4; ++i) { //for each combination of operands (000 to 333)
      for (int j=0; j<4; ++j) {
        for (int k=0; k<4; ++k) {
          ops[0] = i;
          ops[1] = j;
          ops[2] = k;
          for (zz=0; zz<5; ++zz) {

            if (zz==0) {
              total = array[a][0];
              for (int b=0; b<3; ++b) { //1, 2, 3
                switch(ops[b]) {
                  case 0:
                    total+=(double)array[a][b+1];
                    break;
                  case 1:
                    total-=(double)array[a][b+1];
                    break;
                  case 2:
                    total*=(double)array[a][b+1];
                    break;
                  case 3:
                    total/=(double)array[a][b+1];
                    break;
                }
              }
              if ((23.9999<total) && (total<24.0001)) {
                break;
              }
            }

            else if (zz==1) { //1, 3, 2
              double temp;
              total=0;
              switch(ops[0]) {
                case 0:
                  total=array[a][0]+(double)array[a][1];
                  break;
                case 1:
                  total=array[a][0]-(double)array[a][1];
                  break;
                case 2:
                  total=array[a][0]*(double)array[a][1];
                  break;
                case 3:
                  total=array[a][0]/(double)array[a][1];
                  break;
              }
              switch(ops[2]) {
                case 0:
                  temp=array[a][2]+(double)array[a][3];
                  break;
                case 1:
                  temp=array[a][2]-(double)array[a][3];
                  break;
                case 2:
                  temp=array[a][2]*(double)array[a][3];
                  break;
                case 3:
                  temp=array[a][2]/(double)array[a][3];
                  break;
              }
              switch(ops[1]) {
                case 0:
                  total+=(double)temp;
                  break;
                case 1:
                  total-=(double)temp;
                  break;
                case 2:
                  total*=(double)temp;
                  break;
                case 3:
                  if (temp==0) break;
                  total/=(double)temp;
                  break;
              }
              if ((23.9999<total) && (total<24.0001)) {
                break;
              }
            }

            else if (zz==2) { //2, 1, 3
              double temp;
              total=0;
              switch(ops[1]) {
                case 0:
                  temp=array[a][1]+(double)array[a][2];
                  break;
                case 1:
                  temp=array[a][1]-(double)array[a][2];
                  break;
                case 2:
                  temp=array[a][1]*(double)array[a][2];
                  break;
                case 3:
                  temp=array[a][1]/(double)array[a][2];
                  break;
              }
              switch(ops[0]) {
                case 0:
                  total=array[a][0]+(double)temp;
                  break;
                case 1:
                  total=array[a][0]-(double)temp;
                  break;
                case 2:
                  total=array[a][0]*(double)temp;
                  break;
                case 3:
                  if (temp==0) break;
                  total=array[a][0]/(double)temp;
                  break;
              }
              switch(ops[2]) {
                case 0:
                  total+=(double)array[a][3];
                  break;
                case 1:
                  total-=(double)array[a][3];
                  break;
                case 2:
                  total*=(double)array[a][3];
                  break;
                case 3:
                  total/=(double)array[a][3];
                  break;
              }
              if ((23.9999<total) && (total<24.0001)) {
                break;
              }
            }

            else if (zz==3) { //2, 3, 1
              total=0;
              switch(ops[1]) {
                case 0:
                  total=array[a][1]+(double)array[a][2];
                  break;
                case 1:
                  total=array[a][1]-(double)array[a][2];
                  break;
                case 2:
                  total=array[a][1]*(double)array[a][2];
                  break;
                case 3:
                  total=array[a][1]/(double)array[a][2];
                  break;
              }
              switch(ops[2]) {
                case 0:
                  total+=(double)array[a][3];
                  break;
                case 1:
                  total-=(double)array[a][3];
                  break;
                case 2:
                  total*=(double)array[a][3];
                  break;
                case 3:
                  total/=(double)array[a][3];
                  break;
              }
              switch(ops[0]) {
                case 0:
                  total=array[a][0]+(double)total;
                  break;
                case 1:
                  total=array[a][0]-(double)total;
                  break;
                case 2:
                  total=array[a][0]*(double)total;
                  break;
                case 3:
                  if (total==0) break;
                  total=array[a][0]/(double)total;
                  break;
              }
              if ((23.9999<total) && (total<24.0001)) {
                break;
              }
            }

            else if (zz==4) { //3, 2, 1
              total=0;
              switch(ops[2]) {
                case 0:
                  total=array[a][2]+(double)array[a][3];
                  break;
                case 1:
                  total=array[a][2]-(double)array[a][3];
                  break;
                case 2:
                  total=array[a][2]*(double)array[a][3];
                  break;
                case 3:
                  total=array[a][2]/(double)array[a][3];
                  break;
              }
              switch(ops[1]) {
                case 0:
                  total=array[a][1]+(double)total;
                  break;
                case 1:
                  total=array[a][1]-(double)total;
                  break;
                case 2:
                  total=array[a][1]*(double)total;
                  break;
                case 3:
                  if (total==0) break;
                  total=array[a][1]/(double)total;
                  break;
              }
              switch(ops[0]) {
                case 0:
                  total=array[a][0]+(double)total;
                  break;
                case 1:
                  total=array[a][0]-(double)total;
                  break;
                case 2:
                  total=array[a][0]*(double)total;
                  break;
                case 3:
                  if (total==0) break;
                  total=array[a][0]/(double)total;
                  break;
              }
              if ((23.9999<total) && (total<24.0001)) {
                break;
              }
            }
          }
          if ((23.9999<total) && (total<24.0001)) { //if a permutation's solution has been found, send it to main()
            for (int d=0; d<4; ++d) soln[d] = array[a][d];
            *z=zz;
            return 1;
          }
        }
      }
    }
  }
  return 0;
}





int main() {
  int permutes[24][4];
  int solution[4] = {9, 9, 9, 9};
  int permute[4];
  int operands[3] = {0, 0, 0};
  int z=0;
  char ops[] = "+-*/";
  printf("Enter 4 integers ranging from 1 through 10: ");
  for (int i=0; i<4; ++i) {          //get numbers
    scanf("%d", &permute[i]);
  }

  for (int i=0; i<4; ++i) {          //sort array
      int min = permute[i], k=i;
      for (int j=i+1; j<4; ++j) {
         if (permute[j]<min) {
            k=j;
            min=permute[j];
         }
      }
      int temp = permute[i];
      permute[i] = permute[k];
      permute[k] = temp;
   }

   for (int g=0; g<4; ++g) {         //generate the 24 permutations
     permutes[0][g] = permute[g];
   }
   for (int f=1; f<24; ++f) {
     findNext(4, permute);
     for (int g=0; g<4; ++g) {
       permutes[f][g] = permute[g];
     }
   }

   if (calculate(permutes, solution, operands, &z)==1) {
     if (z==0) {
       printf("((%d%c%d)%c%d)%c%d=24\n", solution[0], ops[operands[0]], solution[1], ops[operands[1]], solution[2], ops[operands[2]], solution[3]);
     }
     else if (z==1) {
       printf("(%d%c%d)%c(%d%c%d)=24\n", solution[0], ops[operands[0]], solution[1], ops[operands[1]], solution[2], ops[operands[2]], solution[3]);
     }
     else if (z==2) {
       printf("(%d%c(%d%c%d))%c%d=24\n", solution[0], ops[operands[0]], solution[1], ops[operands[1]], solution[2], ops[operands[2]], solution[3]);
     }
     else if (z==3) {
       printf("%d%c((%d%c%d)%c%d)=24\n", solution[0], ops[operands[0]], solution[1], ops[operands[1]], solution[2], ops[operands[2]], solution[3]);
     }
     else if (z==4) {
       printf("%d%c(%d%c(%d%c%d))=24\n", solution[0], ops[operands[0]], solution[1], ops[operands[1]], solution[2], ops[operands[2]], solution[3]);
     }
   }
   else if (calculate(permutes, solution, operands, &z)==0) {
     printf("no solution\n");
   }

  return 0;
}
