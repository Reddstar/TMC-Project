TARGETDIR="project"
CONTRACT="supervisor"

gcc -c  -I $CONTRACT"_controller_c" -I /usr/local/lib/heptagon/c -pipe  -I $TARGETDIR"_c" $TARGETDIR"_c"/_main.c -o $TARGETDIR"_c"/_main.o
gcc -c  -I $CONTRACT"_controller_c" -I /usr/local/lib/heptagon/c -pipe  -I $TARGETDIR"_c" $TARGETDIR"_c"/$TARGETDIR".c" -o $TARGETDIR"_c"/$TARGETDIR".o"
gcc -c  -I $CONTRACT"_controller_c" -I /usr/local/lib/heptagon/c -pipe  -I $TARGETDIR"_c" $CONTRACT"_controller_c"/$CONTRACT"_controller.c" -o $CONTRACT"_controller_c"/$CONTRACT"_controller.o"
gcc -I supervisor_controller_c -I /usr/local/lib/heptagon/c -c -o webservice.o webservice.c
gcc -o webservice $TARGETDIR"_c"/_main.o $TARGETDIR"_c"/$TARGETDIR.o /usr/lib/x86_64-linux-gnu/libmicrohttpd.so supervisor_controller_c/supervisor_controller.o