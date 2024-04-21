void main(){
  int i;
  int x;

  i=3;
  if (i<=10){
    x = 7;
  }

  i = 3;
  if (i>10){
    x = 7;
  }
  else{
    x = 123;
  }

  i = 3;
  switch(i){
    case 1: x = 7; break;
    case 5: x = 18; break;
    case 3: x = 44; break;
    default: x = 123;
  };

  i = 3;
  while(i<=4){
    x = i;
    i++;
  }

  i = 1;
  do{
    x = i;
    i++;
  }while(i<=4);

  for(i = 1; i<=10; i=i+2){
    x=i;
  }
  
  for(i = 2; i<=10; i=i+2){
    x=i;
  }

  for(i = 8; i>=3; i--){
    x=i;
  }
}
