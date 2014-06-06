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


#ifndef CSAFILEROOT_HPP
#define CSAFILEROOT_HPP

#include "CSANode.hpp"

namespace csa{ namespace ast{

class CSAFileRoot : public CSANode{

public:
    CSAFileRoot(const std::string& file, SourceLocation* endOfFile);

    std::string content() const;
    std::string identifier() const;

private:
    std::string m_identifier;
};

inline std::string CSAFileRoot::content() const{
    return std::string("file \"") + m_identifier + "\"";
}

inline std::string CSAFileRoot::identifier() const{
    return m_identifier;
}

}}//namespace

#endif // CSAFILEROOT_HPP
