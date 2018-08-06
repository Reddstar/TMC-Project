/* --- Generated the 6/8/2018 at 10:53 --- */
/* --- heptagon compiler, version 1.03.00 (compiled thu. may. 3 2:35:29 CET 2018) --- */
/* --- Command line: /usr/local/bin/heptc -target c -target z3z -s supervisor project.ept --- */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "_main.h"

Project__supervisor_mem mem;
int main(int argc, char** argv) {
  int step_c;
  int step_max;
  int presence;
  int turn_on_l1;
  int turn_on_l2;
  int turn_on_rl;
  int turn_on_l;
  int turn_on_rac;
  int turn_on_lac;
  int turn_on_tv;
  int turn_on_wm;
  int do_open;
  Project__supervisor_out _res;
  step_c = 0;
  step_max = 0;
  if ((argc==2)) {
    step_max = atoi(argv[1]);
  };
  Project__supervisor_reset(&mem);
  while ((!(step_max)||(step_c<step_max))) {
    step_c = (step_c+1);
    
    printf("presence ? ");
    scanf("%d", &presence);;
    
    printf("turn_on_l1 ? ");
    scanf("%d", &turn_on_l1);;
    
    printf("turn_on_l2 ? ");
    scanf("%d", &turn_on_l2);;
    
    printf("turn_on_rl ? ");
    scanf("%d", &turn_on_rl);;
    
    printf("turn_on_l ? ");
    scanf("%d", &turn_on_l);;
    
    printf("turn_on_rac ? ");
    scanf("%d", &turn_on_rac);;
    
    printf("turn_on_lac ? ");
    scanf("%d", &turn_on_lac);;
    
    printf("turn_on_tv ? ");
    scanf("%d", &turn_on_tv);;
    
    printf("turn_on_wm ? ");
    scanf("%d", &turn_on_wm);;
    
    printf("do_open ? ");
    scanf("%d", &do_open);;
    Project__supervisor_step(presence, turn_on_l1, turn_on_l2, turn_on_rl,
                             turn_on_l, turn_on_rac, turn_on_lac, turn_on_tv,
                             turn_on_wm, do_open, &_res, &mem);
    printf("=> ");
    printf("%d ", _res.has_presence);
    printf("=> ");
    printf("%d ", _res.is_on_l1);
    printf("=> ");
    printf("%d ", _res.is_on_l2);
    printf("=> ");
    printf("%d ", _res.is_on_rl);
    printf("=> ");
    printf("%d ", _res.is_on_l);
    printf("=> ");
    printf("%d ", _res.is_tv_on);
    printf("=> ");
    printf("%d ", _res.is_working_wm);
    printf("=> ");
    printf("%d ", _res.is_w_opened);
    printf("=> ");
    printf("%d ", _res.working_state_rac);
    printf("=> ");
    printf("%d ", _res.working_state_lac);
    puts("");
    fflush(stdout);
  };
  return 0;
}

