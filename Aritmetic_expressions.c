void main(){
  int a = 5;
  int b = 0x0E;
  int x,y,z,t;
  float f;

  x=2*(a+b); //x=38
  y=2*a+b; //y=28

  x=17/5; //x=3
  y=17%5; //y=2

  f=17/5; //f=3.0
  f=17.0/5; //f=3.2

  a=5;
  x=++a; //a=6, x=6

  a=5; 
  x=a++; //x=5, a=6

  a=5;
  x=a--; x=5, a=4
  y=(++x)+(--a); //x=6, a=3, y=9
  z=(a++)+(++x)+(y--); //x=7, z=3+7+9, a=4, y=8
}
