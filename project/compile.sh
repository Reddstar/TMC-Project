TARGETDIR="project"
CONTRACT="supervisor"

gcc -c  -I $CONTRACT"_controller_c" -I /usr/local/lib/heptagon/c -pipe  -I $TARGETDIR"_c" $TARGETDIR"_c"/_main.c -o $TARGETDIR"_c"/_main.o
gcc -c  -I $CONTRACT"_controller_c" -I /usr/local/lib/heptagon/c -pipe  -I $TARGETDIR"_c" $TARGETDIR"_c"/$TARGETDIR".c" -o $TARGETDIR"_c"/$TARGETDIR".o"
gcc -c  -I $CONTRACT"_controller_c" -I /usr/local/lib/heptagon/c -pipe  -I $TARGETDIR"_c" $CONTRACT"_controller_c"/$CONTRACT"_controller.c" -o $CONTRACT"_controller_c"/$CONTRACT"_controller.o"
gcc  -o $CONTRACT"_webservice" $TARGETDIR"_c"/_main.o $TARGETDIR"_c"/$TARGETDIR".o" $CONTRACT"_controller_c"/$CONTRACT"_controller.o"