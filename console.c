#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "unistd.h"
#include "stdbool.h"

#define START_SUCCESS "The console has successfully started!\nType /help for a list of commands.\n"

bool isRunning = 1;

void sendMessage(char *message){
    printf("%s\n", message);
}

void help(){
    sendMessage("This command pretty much exists.");
}

void onCommand(char *command){
    if(strcmp(command, "help") == 0){
        help();
    }else if(strcmp(command, "stop") == 0){
        sendMessage("Shutting down...");
        isRunning = 0;
    }else{
        sendMessage("Unknown command. Type /help for a list of commands.");
    }
}

void checkCommand(){
    char str[127];

    scanf("%99[^\n]", str);

    if(strlen(str) != 0){
        onCommand(str);
        stdin = freopen(NULL, "r", stdin);
    }
}

void startTickCounter(){
    while(isRunning){
        usleep(20000);
        checkCommand();
    }
}

int main(){
    printf(START_SUCCESS);
    startTickCounter();
    return 0;
}
