#include "morse_code.h"


bool data[30];
int8_t position = -1;
void set_digit(uint8_t digit);

void reset(){
  position = -1;
}

void set_code(uint8_t id){
  if (id == 0) return;
  uint8_t val = id%10;
  set_digit(val);
  if(id >= 10){
    val = (id/10)%10;
    set_digit(val);
    if(id>=100){
      val = (id/100);
      set_digit(val);
    }
  }
}

uint8_t get_time(){
  if (position < 0) return 0;
  if(data[position]){
    position --;
    return 3;
  }
  position --;
  return 1;
}


void set_digit(uint8_t digit){
  switch (digit) {
    case 1:
      data[++position] = 1;
      data[++position] = 1;
      data[++position] = 0;
      data[++position] = 1;
      data[++position] = 0;
      data[++position] = 1;
      data[++position] = 0;
      data[++position] = 1;
      data[++position] = 0;
      data[++position] = 0;
      break;
    case 2:
      data[++position] = 1;
      data[++position] = 1;
      data[++position] = 0;
      data[++position] = 1;
      data[++position] = 0;
      data[++position] = 1;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      break;

    case 3:
      data[++position] = 1;
      data[++position] = 1;
      data[++position] = 0;
      data[++position] = 1;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      break;

    case 4:
      data[++position] = 1;
      data[++position] = 1;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      break;

    case 5:
      data[++position] = 1;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      break;

    case 6:
      data[++position] = 1;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 1;
      break;

    case 7:
      data[++position] = 1;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 1;
      data[++position] = 0;
      data[++position] = 1;
      break;

    case 8:
      data[++position] = 1;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 1;
      data[++position] = 0;
      data[++position] = 1;
      data[++position] = 0;
      data[++position] = 1;
      break;
    case 9:
      data[++position] = 1;
      data[++position] = 0;
      data[++position] = 0;
      data[++position] = 1;
      data[++position] = 0;
      data[++position] = 1;
      data[++position] = 0;
      data[++position] = 1;
      data[++position] = 0;
      data[++position] = 1;
      break;
    case 0:
      data[++position] = 1;
      data[++position] = 1;
      data[++position] = 0;
      data[++position] = 1;
      data[++position] = 0;
      data[++position] = 1;
      data[++position] = 0;
      data[++position] = 1;
      data[++position] = 0;
      data[++position] = 1;
      break;
  }

}
