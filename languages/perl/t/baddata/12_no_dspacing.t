#!/usr/bin/perl  -I../../blib/lib -I../../blib/arch

## test the no XDI line bad data example

use Test::More tests => 3;

use strict;
use warnings;
use File::Basename;
use File::Spec;

my $epsi = 0.001;

BEGIN { use_ok('Xray::XDI') };

my $here = dirname($0);
my $file = File::Spec->catfile($here, '..', '..', '..', '..', 'baddata', 'bad_12.xdi');
my $xdi  = Xray::XDI->new(file=>$file);

ok(($xdi->errorcode>0), 'bad_12.xdi flagged as ok');
ok(($xdi->errormessage =~ m{no mono.d_spacing}), 'correctly identified missing d-spacing');


open(my $COV, '>>', 'coverage.txt');
print $COV 12, $/;
close $COV;
