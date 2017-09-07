void main()
{
int i,j;
clrscr();
for(i=1;i<=4;i++)
{
for(j=1;j<=7;j++)
{
if(j>i&&i+j<8)
{
printf(" ");

}
else
{
printf("*");
}}
printf("\n");
}
getch();
}