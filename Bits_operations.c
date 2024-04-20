void main(){
  unsigned char a=0b00001010;
  unsigned char x;

  a = 0b11111111;
  x = ~0b11001010; //bits negation

  //AND
  x = 0b11001010 &
      0b10011011;
  //x=0b10001010

  //OR
  x = 0b11001010 |
      0b10011011;
  //x=0b11011011;

  //XOR
  x = 0b11001010 ^
      0b10011011;
  //x=0b01010001

  //bits shifting
  x = 0b11111111 << 3; //x=0b11111000
  x = 0b11111111 >> 4; //x=0b00001111
}
