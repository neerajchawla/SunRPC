/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "assignment.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void addUser(inData *argp);
bool isRegisteredUsername(inData *argp);
bool isValidUser(inData *argp);
int getUserCount();

outData *
register_1_svc(inData *argp, struct svc_req *rqstp)
{
	static outData  result;
	FILE *fp = fopen("./database.db","r");
	if(fp == NULL){
		inData arg;
		strcpy(arg.user, "admin");
		strcpy(arg.pass, "admin");
		addUser(&arg);
	}

	if(!isRegisteredUsername(argp))
	{	
		addUser(argp);
		result.rCode = 1;
		strcpy(result.rString, "Registration successful\n");
	}
	else {
		result.rCode = 0;
		strcpy(result.rString, "Username already exists. Try a different one\n");
	}

	return &result;
}

outData *
login_1_svc(inData *argp, struct svc_req *rqstp)
{
	static outData  result;
	// Create DB, if not present
	FILE *fp = fopen("./database.db","r");
	if(fp == NULL){
		inData arg;
		strcpy(arg.user, "admin");
		strcpy(arg.pass, "admin");
		addUser(&arg);
	}

	if((strcmp("admin", argp->user)) == 0 && (strcmp("admin", argp->pass)) == 0) {
		int count = getUserCount();
		result.rCode = 1;
		sprintf(result.rString, "Welcome admin! Number of registered users are %d\n", count);
	}
	else {
		if(isValidUser(argp)) {	
			result.rCode = 1;
			sprintf(result.rString, "Welcome %s!\n", argp->user);
		}
		else {
			result.rCode = 0;
			sprintf(result.rString, "Unable to login. Please check the credentials.\n", argp->user);
		}
	}
	return &result;
}

void addUser(inData *argp) {
   char* delimiter = ">>>>";
   FILE *fp = fopen("./database.db","ab");
   if(fp != NULL) {
       char data[517]  = "";
       strcpy(data,argp->user);
       strcat(data,delimiter);
       strcat(data,argp->pass);
       strcat(data,"\n");
       fputs(data,fp);
       fclose(fp);
   }
}

bool isRegisteredUsername(inData *argp) {
    FILE *fp;
    char* delimiter = ">>>>";
    char* tokens;
    char temp[517];
    int read;
    fp = fopen("./database.db","r");
    if(fp == NULL){
	return FALSE;
    }
    while(fgets(temp, 517, fp) != NULL) {
	tokens = strtok(temp, delimiter );
	if (tokens != NULL)
	{
		if((strcmp(tokens, argp->user)) == 0) {
		    fclose(fp);
		    return TRUE;
		}
	}
    }
    fclose(fp);
    return FALSE;
}

bool isValidUser(inData *argp) {
    FILE *fp;
    char* delimiter = ">>>>";
    char* tokens;
    char temp[517];
    char input[517];
    fp = fopen("./database.db","r");
    if(fp == NULL){
	return FALSE;
    }

    strcpy(input,argp->user);
    strcat(input,delimiter);
    strcat(input,argp->pass);
    strcat(input,"\n");
    while(fgets(temp, 517, fp) != NULL) {
	if((strcmp(temp, input)) == 0) {
	    fclose(fp);
	    return TRUE;
	}
    }
    fclose(fp);
    return FALSE;
}

int getUserCount() {
    FILE *fp;
    char* delimiter = ">>>>";
    char* tokens;
    char temp[517];
    int count = 0;

    fp = fopen("./database.db","r");
    if(fp == NULL){
	return FALSE;
    }
	
    while(fgets(temp, 517, fp) != NULL) {
	count++;
    }
    fclose(fp);
    return count;
}