#include "./header.h"
#include "./colors.h"
#include "./view/debug.c"

int main(){
    s_configuration config = Config();

    printf("\nversion: %d\nname: %s\nemail: %s\n", 
        config.version, 
        config.name, 
        config.email
    );

    #include "./clearFree.c"
    return 0;
}
