/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "assignment.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

outData *
register_1(inData *argp, CLIENT *clnt)
{
	static outData clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, REGISTER,
		(xdrproc_t) xdr_inData, (caddr_t) argp,
		(xdrproc_t) xdr_outData, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}

outData *
login_1(inData *argp, CLIENT *clnt)
{
	static outData clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, LOGIN,
		(xdrproc_t) xdr_inData, (caddr_t) argp,
		(xdrproc_t) xdr_outData, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}
