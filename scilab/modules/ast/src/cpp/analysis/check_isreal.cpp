/*
 *  Scilab ( http://www.scilab.org/ ) - This file is part of Scilab
 *  Copyright (C) 2014-2015 - Scilab Enterprises - Calixte DENIZET
 *
 * Copyright (C) 2012 - 2016 - Scilab Enterprises
 *
 * This file is hereby licensed under the terms of the GNU GPL v2.0,
 * pursuant to article 5.3.4 of the CeCILL v.2.1.
 * This file was originally licensed under the terms of the CeCILL v2.1,
 * and continues to be available under such terms.
 * For more information, see the COPYING file which you should have received
 * along with this program.
 *
 */

// This file has been generated, so don't modify it by hand !!

#include "checkers/Checkers.hxx"

namespace analysis
{
TIType Checkers::check_isreal(GVN & gvn, const TIType & in0)
{
    switch (in0.type)
    {
        case TIType::COMPLEX :
        {
            return TIType(gvn, TIType::BOOLEAN, 1, 1);
        }
        case TIType::DOUBLE :
        {
            return TIType(gvn, TIType::BOOLEAN, 1, 1);
        }
        default :
            return TIType(gvn);
    }
}

TIType Checkers::check_isreal(GVN & gvn, const TIType & in0, const TIType & in1)
{
    switch (in0.type)
    {
        case TIType::COMPLEX :
        {
            if (in1.type == TIType::DOUBLE)
            {
                if (in1.rows == 1 && in1.cols == 1)
                {
                    return TIType(gvn, TIType::BOOLEAN, 1, 1);
                }
            }
            else
            {
                return TIType(gvn);
            }
            return TIType(gvn);
        }
        case TIType::DOUBLE :
        {
            if (in1.type == TIType::DOUBLE)
            {
                if (in1.rows == 1 && in1.cols == 1)
                {
                    return TIType(gvn, TIType::BOOLEAN, 1, 1);
                }
            }
            else
            {
                return TIType(gvn);
            }
            return TIType(gvn);
        }
        default :
            return TIType(gvn);
    }
}

} // namespace analysis