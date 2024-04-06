/* defines of constants and macros */
#define NUMAR_MAGIC   32
#define SUMA(a,b)     ((a)+(b))

/* variable definitions */
unsigned int suma_01, suma_02;

/* function declarations */
void functie_01(void);
unsigned int suma(unsigned char b, unsigned int a);

/* functiond definitions */
void main()
{
  unsigned char numar_01;
  unsigned int numar_02;

  numar_01 = 7;
  numar_02 = 15;
  suma_01 = SUMA(7,NUMAR_MAGIC);
  suma_02 = suma(numar_01, numar_02);

  if(suma_01 > suma_02)
  {
    functie_01();
  }
  else
  {
    suma_01 = suma_02 + NUMAR_MAGIC;
  }

  while(1)
  {
    ;
  }
} /* end main function */

void functie_01(void)
{
  ; /* do nothing */
}

unsigned int suma(unsigned char b, unsigned int a)
{
  unsigned int c;
  c = a + b;
  return c;
}
