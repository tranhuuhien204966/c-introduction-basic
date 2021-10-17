void CharReadWrite(FILE *fin, FILE *fout)
{w
int c;
while ((c=fgetc(fin)) != EOF){
if islower(c) c=toupper(c);
if isupper(c) c=tolower(c);
fputc(c, fout); 
putchar(c); 

}
}
