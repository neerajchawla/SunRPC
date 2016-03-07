CC = gcc
CFLAGS = -g -DRPC_SVC_FG
RPCGEN_FLAG = -C

all: assignment_client assignment_server

# the executables: assignment_client and assignment_server

assignment_client: assignment_client.o assignment_clnt.o assignment_xdr.o
	$(CC) -o assignment_client assignment_client.o assignment_clnt.o assignment_xdr.o -lnsl

assignment_server: assignment_server.o assignment_svc.o  assignment_xdr.o
	$(CC) -o assignment_server assignment_server.o assignment_svc.o assignment_xdr.o -lnsl

# object files for the executables 

assignment_server.o: assignment_server.c assignment.h
	$(CC) $(CFLAGS) -c assignment_server.c

assignment_client.o: assignment_client.c assignment.h
	$(CC) $(CFLAGS) -c assignment_client.c

# compile files generated by rpcgen

assignment_svc.o: assignment_svc.c assignment.h
	$(CC) $(CFLAGS) -c assignment_svc.c

assignment_clnt.o: assignment_clnt.c assignment.h
	$(CC) $(CFLAGS) -c assignment_clnt.c

assignment_xdr.o: assignment_xdr.c assignment.h
	$(CC) $(CFLAGS) -c assignment_xdr.c

# assignment.x produces assignment.h, assignment_clnt.c, assignment_svc.c, and assignment_xdr.c
# make sure we regenerate them if our interface (assignment.x) changes

assignment.h assignment_clnt.c assignment_svc.c assignment_xdr.c:	assignment.x
	rpcgen $(RPCGEN_FLAG) assignment.x

clean:
	rm -f assignment_client assignment_client.o assignment_server assignment_server.o assignment_clnt.* assignment_svc.* assignment.h
