#include <string.h>
#include <stdlib.h>
#include "desplazar.h"

void desplazar(char *str, int from, int nbytes, int by) {
	//printf("str inicial= %s\n",str );
	int lens=strlen(str);
	int cby=1;
	int n=0;
	if(by>0){
		char *p=str+lens+1;
		char *q1=str+from+nbytes-1;
		while(n!=nbytes){
			p--;
			if(p==q1){
				while(cby<=by && *p++){
					cby++;
				}
				//printf("%d\n", cby);
				if(cby-1==by && *p){
					//printf("%s\n",p );
					*p=*q1;
					//printf("%s\n",p );
					q1--;
					n++;
					cby=1;
				}
				else{
					q1--;
					n++;
					cby=1;
				}
			}
		}
	}
	else if(by<0){
		char *p=str;
		char *qi=str;
		char *q1=str+from;
		while(n!=nbytes){
			p++;
			if(p==q1){
				while(cby<=abs(by) && p-->=qi){
					cby++;
				}
				if(cby-1==abs(by) && p>=qi){
					*p=*q1;
					q1++;
					n++;
					cby=1;
				}
				else{
					q1++;
					n++;
					cby=1;
				}
			}
		}
	}
	else;
}

char *desplazamiento(char *str, int from, int nbytes, int by) {
	int lens=strlen(str);
	char *new=malloc(lens*sizeof(char)+1);
	char dest[lens+1];
	strcpy(dest,str );
	//printf("dest=%s\n",dest );
	desplazar(dest,from,nbytes,by);
	//printf("salida desplazar desde desplazamiento=%s\n",dest );
	char *p=dest;
	char *pn=new;
	*pn=*p;
	while(*p++){
		pn++;
		*pn=*p;
	}
	return new;
}
