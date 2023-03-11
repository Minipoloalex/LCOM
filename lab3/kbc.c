#include "kbc.h"
#include "utils.c"

void (wait)(uint8_t *attemps){
    tickdelay(micros_to_ticks(WAIT_KBC));
    (*attemps)--;
}

int (read_KBC_status)(uint8_t *status){
  return(util_sys_inb(KBC_STATUS_REG, status));
}

int (read_KBC_output)(int8_t port, uint8_t* output){
  /*
  1- Verificar se o output buffer está cheio
  2- Verificar erros de Paridade ou Timeout
  3- Se sim, lê-se (port 0x60 e conteúdo em *output)
  */

  uint8_t status;

  uint8_t attemps = MAX_ATTEMPS;
  while(attemps){

    // error reading status
    if(read_KBC_status(&status)){
      return EXIT_FAILURE;
    }

    // 1
    if(status & FULL_OUT_BUF){
      
      // 2
      if((status & PARITY_ERR) || (status & TIMEOUT_ERR)){
        return EXIT_FAILURE;
      }

      // 3
      if(util_sys_inb(port, output)){
        return EXIT_FAILURE;
      }

      return 0;
    }

    wait(&attemps);
  }

  return 1;
}

int (write_KBC_command)(uint8_t port, uint8_t* cmd_byte){
  uint8_t status;
  uint8_t attemps = MAX_ATTEMPS;

  while(attemps){

    /*
    1- Verificar se o input buffer está cheio
    2- Se não, escreve-se
    */

    // error reading status
    if(read_KBC_status(&status)){
      return EXIT_FAILURE;
    }

    // 1
    if((status & FULL_IN_BUF)==0){
      
      // 2
      if(util_sys_outb(port, cmd_byte)){
        return EXIT_FAILURE;
      }

      return 0;
    }

    wait(&attemps);
  }

  return 1;
}