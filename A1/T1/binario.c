#include<stdio.h> 

unsigned long long binario(unsigned long long); 

int main() 
{ 
   //int num; 
   unsigned long long num;
   printf("Introduce el numero que deseas convertir a binario:\n"); 
   //scanf("%d",&num);
   scanf("%llu",&num); 
   binario(num); 
    
   printf("\n"); 
   return 0; 
} 


unsigned long long binario(unsigned long long num) 
{ 
   //int aux;
   unsigned long long aux; 
    
   if(num==0) 
      return; 

   //aux=num%2;
   aux=num-((num>>1)<<1); 
   num=num>>1; 
   binario(num); 
   printf("%llu",aux); 
}
