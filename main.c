#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[200];
    fgets(s,200,stdin);
    s[strcspn(s,"\n")]='\0';
    int i,j,n=0,count=0;
    char s1[200];
    char rs[200][200];
    for (i=0;i<strlen(s);i++)
    {
        if (s[i]>='A'&&s[i]<='z')
        {
            s1[n]=s[i];
            n++;
            if ((i+1)==strlen(s)||s[i+1]>'z'||s[i+1]<'A')
            {
                s1[n]='\0';
                strcpy(rs[count],s1);
                count++;
                n=0;
            }
        }
    }
    char c[200];
    for (i=0;i<count-1;i++)
        for (j=0;j<count-1-i;j++)
            if (strcmp(rs[j],rs[j+1])>0)
            {
                strcpy(c,rs[j+1]);
                strcpy(rs[j+1],rs[j]);
                strcpy(rs[j],c);
            }
    for (i=0;i<count-1;i++)
        printf("%s\n",rs[i]);
    printf("%s",rs[i]);
    return 0;
}
