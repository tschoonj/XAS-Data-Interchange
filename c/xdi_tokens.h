/*
   Tokens used in XDI File
*/

#define TOK_VERSION  "XDI/"           /* XDI version marker -- required on line 1 */
#define TOK_COMM     "#"              /* comment character, at start of line */
#define TOK_DELIM    ":"              /* delimeter between metdata key and value */
#define TOK_EDGE     "element.edge"   /* absorbption edge name */
#define TOK_ELEM     "element.symbol" /* atomic symbol of absorbing element */
#define TOK_COLUMN   "column."        /* column label (followed by integer <= 64) */
#define TOK_DSPACE   "mono.d_spacing" /* mono d_spacing, in Angstroms */
#define TOK_USERCOM_0 "///"           /* start multi-line user comment */
#define TOK_USERCOM_1 "---"           /* end multi-line user comment */

#define ERR_NOEDGE -32
#define ERR_NOELEM -31
#define ERR_NOARR_INDEX -22
#define ERR_NOARR_NAME  -21

/* Notes:
   1. The absorption edge must be one of those listed in ValidEdges below
   2. The element symbol must be one of those listed in ValidElems below
*/
static char *ValidEdges[] =
  {"K", "L", "L1", "L2", "L3",
   "M", "M1", "M2", "M3", "M4", "M5",
   "N", "N1", "N2", "N3", "N4", "N5", "N6", "N7",
   "O", "O1", "O2", "O3", "O4", "O5", "O6", "O7"};

/*  "P", "P1", "P2", "P3", "P4", "P5", "P6", "P7"}; */

static char *ValidElems[] =
  {"H",  "He", "Li", "Be", "B",  "C",  "N",  "O",
   "F",  "Ne", "Na", "Mg", "Al", "Si", "P",  "S",
   "Cl", "Ar", "K",  "Ca", "Sc", "Ti", "V",  "Cr",
   "Mn", "Fe", "Co", "Ni", "Cu", "Zn", "Ga", "Ge",
   "As", "Se", "Br", "Kr", "Rb", "Sr", "Y",  "Zr",
   "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd",
   "In", "Sn", "Sb", "Te", "I",  "Xe", "Cs", "Ba",
   "La", "Ce", "Pr", "Nd", "Pm", "Sm", "Eu", "Gd",
   "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Hf",
   "Ta", "W",  "Re", "Os", "Ir", "Pt", "Au", "Hg",
   "Tl", "Pb", "Bi", "Po", "At", "Rn", "Fr", "Ra",
   "Ac", "Th", "Pa", "U",  "Np", "Pu", "Am", "Cm",
   "Bk", "Cf", "Es", "Fm", "Md", "No", "Lr", "Rf",
   "Db", "Sg", "Bh", "Hs", "Mt", "Ds", "Rg", "Cn"};

/*
   could add these additional elements:
   "UUt","Fl", "Uup", "Lv", "Uus", "Uuo"
*/

