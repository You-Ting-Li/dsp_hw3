/*
 * testBinaryCounts --
 *	test binary count I/O
 */

#ifndef lint
static char Copyright[] = "Copyright (c) 2006 SRI International.  All Rights Reserved.";
static char RcsId[] = "@(#)$Header: /home/srilm/devel/lm/src/RCS/testBinaryCounts.cc,v 1.1 2006/09/03 00:22:43 stolcke Exp $";
#endif

#ifdef PRE_ISO_CXX
# include <iostream.h>
#else
# include <iostream>
using namespace std;
#endif

#include "Boolean.h"
#include "Counts.h"
#include "File.h"
#include "option.h"

char *inFile = 0;
char *outFile = 0;

static Option options[] = {
    { OPT_STRING, "read", (void *)&inFile, "input file" },
    { OPT_STRING, "write", (void *)&outFile, "output file" },
};

int
main(int argc, char **argv)
{
    FILE *in, *out;

    Opt_Parse(argc, argv, options, Opt_Number(options), 0);

    if (inFile) {
	File f(inFile, "r");

	long long unsigned count;
	while (readBinaryCount(f, count)) {
	    printf("%llu\n", count);
	}
    }

    if (outFile) {
	File f(outFile, "w");

	long long unsigned count;
	while (scanf("%llu", &count) == 1) {
	    writeBinaryCount(f, count);
	}
    }

    exit(0);
}



