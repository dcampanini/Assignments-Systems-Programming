#include <stdlib.h>
#include <stdio.h>
// Programa aca el juego de la vida


// función para pasar a binario
unsigned long long binario(unsigned long long); 

// Parte a
unsigned long long transicion(unsigned long long m) {
  unsigned long long c1,c2,c3,c4,c5,c6,c7,c8,c9;
  unsigned long long f1,f2,f3,f4,f5,f6,f7,f8,f9;
  unsigned long long suma;
  unsigned long long m1=m;
  int d1,d2,d3,d4,d5,d6,d7,d8,d9;
  for(int i=0;i<8;i++)
  {
    for(int j=0;j<8;j++)
    {
      if(i<=6 && j<=6 && i>0 && j>0 )
      {
        d1=(i+1)<<3;f1=(m>>d1);c1=(f1>>(j+1))&1;
        d2=(i+1)<<3;f2=(m>>d2);c2=(f2>>(j))&1;
        d3=(i+1)<<3;f3=(m>>d3);c3=(f3>>(j-1))&1;
        d4=(i)<<3;f4=(m>>d4);c4=(f4>>(j+1))&1;
        d5=(i)<<3;f5=(m>>d5);c5=(f5>>(j))&1;
        d6=(i)<<3;f6=(m>>d6);c6=(f6>>(j-1))&1;
        d7=(i-1)<<3;f7=(m>>d7);c7=(f7>>(j+1))&1;
        d8=(i-1)<<3;f8=(m>>d8);c8=(f8>>(j))&1;
        d9=(i-1)<<3;f9=(m>>d9);c9=(f9>>(j-1))&1;
        suma=c1+c2+c3+c4+c6+c7+c8+c9;
        //printf("i=%i,j=%i,c1=%8llx\n",i,j,c1);
        //printf("m=%8llx\n",m);
        if(c5==0 && suma==3)
        {
          m1=m1|(j<<d5);
          //m1=binario(m1);
          //printf("m1=%8llx\n",m1);
          //printf("m1=%llu\n",m1);         
        } 
      } 
    }
  }
  return m1;   
}


// función para extraer bits
unsigned long long extraer(unsigned long long n,int ls, int li)
{
    return (n<<ls)>>(64-li);
}


// Parte b
int main(int argc, char **argv) {
    if (argc!=10) {
    fprintf(stderr, "uso: %s <iteraciones> <fila0> <fila1> ... <fila7>\n",
            argv[0]);
    exit(1);
  }
  int k= atoi(argv[1]);// k = numero de transiciones ingresada por consola

  unsigned long long x= 0;
  for (int i= 0; i<8; i++) {
    char *fila= argv[i+2];
    for (int j= 0; j<8; j++)
      x = ( x<<1 ) + fila[j]-'0';
  }
  // printiar la salida de la fun transicion
  unsigned long long out;
  out=transicion(x);
  printf("salida transicion=%8llx\n",out);  
  
  //printf("transiciones= %d, matriz inicial= %8llx (en hexadecimal)\n", k, x);
  //x=binario(x);  
  //printf("matriz inicial=%llu (en binario) \n",x);
  
  unsigned long long fila6;
  int ls6=8;
  int li6=15;  
  fila6=extraer(x,ls6,li6);
  printf("matriz=%8llx (en binario)\n",fila6);
  return 0;
}

// Otras funciones que necesite
unsigned long long binario(unsigned long long num) 
{ 
   //int aux;
   unsigned long long aux; 
    
   if(num==0) 
     return 0; 

   //aux=num%2;
   aux=num-((num>>1)<<1); 
   num=num>>1; 
   binario(num); 
   //printf("%llu",aux);
   return aux; 
}
