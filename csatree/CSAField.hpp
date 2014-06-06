/****************************************************************************
**
** Copyright (C) 2014 Dinu SV.
** (contact: mail@dinusv.com)
** This file is part of C++ Snippet Assist application.
**
** GNU General Public License Usage
** 
** This file may be used under the terms of the GNU General Public License 
** version 3.0 as published by the Free Software Foundation and appearing 
** in the file LICENSE.GPL included in the packaging of this file.  Please 
** review the following information to ensure the GNU General Public License 
** version 3.0 requirements will be met: http://www.gnu.org/copyleft/gpl.html.
**
****************************************************************************/


#ifndef CSAFIELD_HPP
#define CSAFIELD_HPP

#include "CSANode.hpp"

namespace csa{ namespace ast{

class CSAField : public CSANode{

public:
    CSAField(AnnotatedTokenSet* tokenSet, SourceLocation* cursorLocation, SourceLocation* rangeStartLocation, SourceLocation* rangeEndLocation, CSANode* parent = 0);

    std::string content() const;
    std::string identifier() const;

private:
    std::string m_identifier;
};

inline std::string CSAField::identifier() const{
    return m_identifier;
}

inline std::string CSAField::content() const{
    return m_identifier;
}

}}// namespace

#endif // CSAFIELD_HPP
