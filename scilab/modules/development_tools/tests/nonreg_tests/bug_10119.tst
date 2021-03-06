// =============================================================================
// Scilab ( http://www.scilab.org/ ) - This file is part of Scilab
// Copyright (C) 2011 - DIGITEO - Michael Baudin
//
//  This file is distributed under the same license as the Scilab package.
// =============================================================================

// <-- CLI SHELL MODE -->

// <-- Non-regression test for bug 10119 -->
//
// <-- Bugzilla URL -->
// http://bugzilla.scilab.org/show_bug.cgi?id=10119
//
// <-- Short Description -->
// assert_checkequal does not support sparse complex doubles


value = sprand(100, 100, 0.01) + sprand(100, 100, 0.01) * %i;
value2 = sprand(100, 100, 0.01) + sprand(100, 100, 0.01) * %i;
instr = "assert_checkequal(value, value2)";
ierr = execstr(instr,"errcatch");
if ierr <> 10000 then pause,end;
//
value = sprand(1, 1, 0.01) + sprand(1, 1, 0.01) * %i;
value2 = sprand(1, 1, 0.01) + sprand(1, 1, 0.01) * %i;
instr = "assert_checkequal(value, value2)";
ierr = execstr(instr,"errcatch");
if ierr <> 10000 then pause,end;
