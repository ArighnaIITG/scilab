// =============================================================================
// Scilab ( http://www.scilab.org/ ) - This file is part of Scilab
// Copyright (C) 2013 - Scilab Enterprises - Charlotte HECQUET
//
//  This file is distributed under the same license as the Scilab package.
// =============================================================================
//
// <-- CLI SHELL MODE -->
//
// <-- Non-regression test for bug 12779 -->
//
// <-- Bugzilla URL -->
// http://bugzilla.scilab.org/show_bug.cgi?id=12779
//
// <-- Short Description -->
// Function "savewave" has a miscoding in the internal function "write_wavedat"
//
t=soundsec(0.5);
s=sin(2*%pi*440*t)+sin(2*%pi*220*t)/2+sin(2*%pi*880*t)/2;
t(11026)=0.500001;
nc=size(t,2);
nc=nc+1;

assert_checktrue(execstr("savewave(TMPDIR+''/bug_12779.wav'',s, 22050, 2);", "errcatch")==0);
