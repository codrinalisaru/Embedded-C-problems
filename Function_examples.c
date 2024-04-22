int max (int, int);
int suma (int, int, int);

void main(){
  int a = 1, b = 2, c = 1;
  int x;

  x = suma(44,44,11);
  x = max(3,5);

  x = suma(a,b,c);
  x = max(a,b);

  x = suma(3*a, max(a,b), 10);
  x = max(max(a,b),c);

}

int suma(int a, int b, int c){
  return a+b+c;
}

int max(int a, int b){
  if (a>b){
    return a;
  }
  else{
    return b;
  }
}
