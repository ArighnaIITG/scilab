/*
 *  Scilab ( http://www.scilab.org/ ) - This file is part of Scilab
 *  Copyright (C) 2010-2010 - DIGITEO - Bruno JOFRET
 *
 *  This file must be used under the terms of the CeCILL.
 *  This source file is licensed as described in the file COPYING, which
 *  you should have received as part of this distribution.  The terms
 *  are also available at
 *  http://www.cecill.info/licences/Licence_CeCILL_V2-en.txt
 *
 */

#ifndef __LIST_HH__
#define __LIST_HH__

#include <list>
#include "container.hxx"

namespace types
{
class EXTERN_AST List : public Container
{
public :
    List();
    ~List();

protected :
    std::vector<InternalType *>*    getData();
    List(List *_oListCopyMe);
public :
    int                             getSize();

    void                            whoAmI(void)
    {
        std::cout << "types::List";
    };

    inline ScilabType               getType(void)
    {
        return ScilabList;
    }
    inline ScilabId                 getId(void)
    {
        return IdList;
    }

    /**
    ** append(InternalType *_typedValue)
    ** Append the given value to the end of the List
    */
    void                            append(InternalType *_typedValue);

    /**
    ** Clone
    ** Create a new List and Copy all values.
    */
    InternalType*                   clone();

    bool                            toString(std::wostringstream& ostr);

    bool                            isList()
    {
        return true;
    }

    InternalType*                   insert(typed_list* _pArgs, InternalType* _pSource);
    InternalType*                   extract(typed_list* _pArgs);

    virtual bool invoke(typed_list & in, optional_list & /*opt*/, int /*_iRetCount*/, typed_list & out, ast::ConstVisitor & /*execFunc*/, const ast::CallExp & /*e*/)
    {
        if (in.size() == 0)
        {
            out.push_back(this);
        }
        else
        {
            InternalType * _out = extract(&in);
            if (_out == NULL)
            {
                // invalid index
                return false;
            }

            List* pList = _out->getAs<types::List>();
            for (int i = 0; i < pList->getSize(); i++)
            {
                out.push_back(pList->get(i));
            }
            delete pList;
        }

        return true;
    }

    virtual bool isInvokable() const
    {
        return true;
    }

    virtual bool hasInvokeOption() const
    {
        return false;
    }

    virtual int getInvokeNbIn()
    {
        return -1;
    }

    virtual int getInvokeNbOut()
    {
        return -1;
    }

    virtual InternalType*           get(const int _iIndex);
    virtual bool                    set(const int _iIndex, InternalType* _pIT);

    /* return type as string ( double, int, cell, list, ... )*/
    virtual std::wstring            getTypeStr()
    {
        return L"list";
    }
    /* return type as short string ( s, i, ce, l, ... )*/
    virtual std::wstring            getShortTypeStr()
    {
        return L"l";
    }

    virtual bool                    operator==(const InternalType& it);

protected :
    std::vector<InternalType *>*    m_plData;
};
}

#endif /* __LIST_HH__ */