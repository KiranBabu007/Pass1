#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
FILE *f1,*f2,*f3,*f4;
char label[20],opcode[20],operand[20],code[20],mne[20];
int start,locctr;
f1=fopen("input.dat","r");
f2=fopen("opcode.dat","r");
f3=fopen("symtab.dat","w");
f4=fopen("intermediate.dat","w");
fscanf(f1,"%s\t%s\t%s",label,opcode,operand);
if(strcmp(opcode,"START")==0){
start=atoi(operand);
locctr=start;
fprintf(f4,"\t%s\t%s\t%s\n",label,opcode,operand);
fscanf(f1,"%s\t%s\t%s",label,opcode,operand);
}
else
locctr=0;
while(strcmp(opcode,"END")!=0){
fprintf(f4,"%d",locctr);
if(strcmp(label,"**")!=0)
fprintf(f3,"%s\t%d\n",label,locctr);
fscanf(f2,"%s\t%s",code,mne);
while(!feof(f2)){
if(strcmp(code,opcode)==0){
locctr+=3;
break;
}
fscanf(f2,"%s\t%s",code,mne);
}
if(strcmp(opcode,"WORD")==0)
locctr+=3;
else if(strcmp(opcode,"RESW")==0)
locctr+=3*atoi(operand);
else if(strcmp(opcode,"RESB")==0)
locctr+=atoi(operand);
else if(strcmp(opcode,"BYTE")==0)
locctr++;
fprintf(f4,"\t%s\t%s\t%s\n",label,opcode,operand);
fscanf(f1,"%s\t%s%s",label,opcode,operand);
}
fprintf(f4,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
printf("Length is %d",locctr-start);
}
