/*
 *  Get a URL parameter
 *  Solution on ANSI C
 *  
 *  Check if parameter exists in query string and return it's value
 *  Usage:
 *  get_url_param("query?string=foo?bar=nothing", "string"); 
 *  
 *  Created by Guillermo Hernandez on 3/15/13
 *  https://github.com/0w3w
 *  http://www.linkedin.com/in/guillermohernandezmolina
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* get_url_param(char* qs, char* param){
	char *paramFound;
        char *val = (char*) malloc (1001);
	int sparam = sizeof(param);
	char paramt01[sparam+2];
	char paramt02[sparam+2];
	snprintf(paramt01, sizeof paramt01, "?%s=", param);
	snprintf(paramt02, sizeof paramt02, "&%s=", param);

        paramFound=strstr(qs, paramt01);
	if(paramFound == NULL){
		paramFound=strstr(qs, paramt02);
	}
        if(paramFound != NULL){
                paramFound++;
		int i = 0;
                while(*paramFound != '&' && *paramFound != '\0'){
                        if(i){
                                val[i-1]=*paramFound;
				i++;
                        }
                        if(*paramFound == '='){
                                i=1;
                        }
                        paramFound++;
                }
		if(i==1){
			return NULL;
		}else{
			val[i] = '\0';
			return val;
		}
        }else{
        	return NULL;
	}
}

int main(){
	printf("Param value exist: %s\n", get_url_param("?va=11&sp=0&fmy=0&q=&cg=1020&w=3&st=a&f=a&et=&ps=&pe=&ros=&roe=&ss=&se=","cg"));
	printf("Param value not exist: %s\n", get_url_param("?va=11&sp=0&fmy=0&q=&cg=1020&w=3&st=a&f=a&et=&ps=&pe=&ros=&roe=&ss=&se=","cas"));
	printf("Param value at last : %s\n", get_url_param("?va=11&sp=0&fmy=0&q=&cg=1020&w=3&st=a&f=a&et=&ps=&pe=&ros=&roe=&ss=&se=amor","se"));
	printf("Param value not at last : %s\n", get_url_param("?va=11&sp=0&fmy=0&q=&cg=1020&w=3&st=a&f=a&et=&ps=&pe=&ros=&roe=&ss=&se=","se"));
	printf("Param value begining : %s\n", get_url_param("?va=11&sp=0&fmy=0&q=&cg=1020&w=3&st=a&f=a&et=&ps=&pe=&ros=&roe=&ss=&se=","ca"));
	printf("Param value not begining : %s\n", get_url_param("?va=&sp=0&fmy=0&q=&cg=1020&w=3&st=a&f=a&et=&ps=&pe=&ros=&roe=&ss=&se=","ca"));
	printf("Param value for f : %s\n", get_url_param("?va=&sp=0&fmy=0&q=&cg=1020&w=3&st=a&f=a&et=&ps=&pe=&ros=&roe=&ss=&se=","f"));
	return 0;
}
