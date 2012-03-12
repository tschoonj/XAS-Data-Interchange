/* read XDI file in C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "strutil.h"
#include "xdifile.h"

void show_syntax(void) {
  /* show command line syntax */
  printf("\nSyntax: xdi_reader filename\n");
}

/*-------------------------------------------------------*/
int main(int argc, char **argv) {
  XDIFile *xdifile;
  long  file_length, ilen, index, i, j, ret;
  long  ncol, nrows, nheader, nwords, ndict;
  int   is_newline, fnlen, mode;

  /* require 2 arguments! */
  if (argc < 2) {
    show_syntax();
    return 1;
  }

  /* read xdifile */
  xdifile = malloc(sizeof(XDIFile));
  ret = readxdi(argv[1], xdifile);
  if (ret < 0) {
    printf("Error reading XDI file %s!\n", argv[1], ret);
    return 1;
  }

  printf("#-----\nXDI FILE Read\nVERSIONS: %s|%s|\n" , 
	 xdifile->xdi_version, xdifile->extra_version);

  printf("Elem/Edge: %s|%s|\n",xdifile->element, xdifile->edge);
  printf("Filename: %s\n",xdifile->filename);
  printf("User Comments:\n%s\n====\n",xdifile->comments);
  printf("Metadata (%ld): \n", xdifile->nmetadata);
  for (i=0; i < xdifile->nmetadata; i++) {
    printf("  %s -> %s\n", xdifile->metadata[i].key, xdifile->metadata[i].val);
  }
  printf("#Arrays: ");
  for (j = 0; j < xdifile->narray_labels; j++ ) {
    printf(" %s, ", xdifile->array_labels[j]);
  }
  printf("\nArray Data: %ld\n", xdifile->narrays);
  for (j = 0; j < xdifile->narrays; j++ ) {
    printf(" J=%ld :", j);
    for (i = 0; i < 5; i++) {
       printf(" %f,", xdifile->array[j][i]);
    }
    printf("... \n");
  }
  free(xdifile);
  return 0;
}
