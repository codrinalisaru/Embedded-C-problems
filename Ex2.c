/* defines of constants and macros */
#define MACRO   32
unsigned const char constant = 8;
/* variable definitions */
unsigned char sum_01=0, sum_02=0;
/* functiond definitions */

void function(void);

void function()
{
  int local;
  static int local_1;
  local =2;
  local_1 =3;
  local_1 ++;

}
void main()
{
  unsigned char variable = 7;
  /* using MACRO*/
  sum_01 = variable + MACRO;
  /* using const*/
  sum_02 = variable + constant;
  while(1);
} /* end main function */

