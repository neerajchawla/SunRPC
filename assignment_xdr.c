/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "assignment.h"

bool_t
xdr_inData (XDR *xdrs, inData *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_int (xdrs, &objp->mode))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->user, 256,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->pass, 256,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_outData (XDR *xdrs, outData *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_int (xdrs, &objp->rCode))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->rString, 256,
		sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	return TRUE;
}
