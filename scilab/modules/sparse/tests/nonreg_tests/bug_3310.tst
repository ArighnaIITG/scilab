// =============================================================================
// Scilab ( http://www.scilab.org/ ) - This file is part of Scilab
// Copyright (C) 2007-2008 - INRIA - Serge STEER <serge.steer@inria.fr>
//
//  This file is distributed under the same license as the Scilab package.
// =============================================================================

// <-- CLI SHELL MODE -->

// <-- ENGLISH IMPOSED -->

// <-- Non-regression test for bug 3310 -->
//
// <-- Bugzilla URL -->
// http://bugzilla.scilab.org/show_bug.cgi?id=3310
//
// <-- Short Description -->
// Wrong implementation of input arguments
A=[10,1;1,10];
// Suppose that the rhs is in myrhs instead of b
myrhs=[11;11];
[xcomputed, flag, err, iter, res]=conjgrad(A,myrhs);
xexpected=[1;1];
assert_checkequal(xcomputed, xexpected);

