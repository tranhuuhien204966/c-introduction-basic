void LineReadWrite(FILE *fin, FILE *fout)
{
char buff[MAX_LEN]; 
int len;
while (fgets(buff, MAX_LEN, fin) != NULL) 
{
len = strlen(buff);
fprintf(fout, "%d %s", len, buff);
printf("%s", buff);
}
}

