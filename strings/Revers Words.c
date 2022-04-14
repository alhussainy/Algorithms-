#include <stdio.h>

/******************************************************************
* Name          : string_size
* Description   : calculates string size 
* Inputs        : pointer to string
* Output        : size of string
*******************************************************************/
int string_size(char *str){
    int strSize=0;
    while(*str){
        strSize++;
        str++;
    }
    return strSize;
}

/******************************************************************
* Name          : string_subReverse
* Description   : Reverses part of string 
* Inputs        : pointer to string
*                 start index
*                 end index
* Output        : none
*******************************************************************/
void string_subReverse(char*str,int start,int end){
    char temp;
    for(;start < end;start++,end--){
        temp = str[start];
        str[start] = str[end];
        str[end]=temp;
    }
}

/******************************************************************
* Name          : string_reverse
* Description   : Reverses words order of the string 
* Inputs        : pointer to string
*                 size of string
* Output        : none
*******************************************************************/
void string_reverse(char *str,int strSize){
    int i;
    char temp;
    for(i=0;i<strSize/2;i++){
        temp=str[i];
        str[i]=str[strSize-i-1];
        str[strSize-i-1]= temp;
    }
    int start=0,end=0;

    for(i=0;i<strSize;i++){

        if(str[i]== ' ' ){
                end = i-1;
        }else if( str[i+1]=='\0'){
                end = i;
        }
        if(end > start){
            string_subReverse(str,start,end);
           end= start = i+1;
        }
    }

}

int main(){
    char sen[]="Hello world again";
    string_reverse(sen,string_size(sen));
    printf("%s",sen);

    return 0;
}
