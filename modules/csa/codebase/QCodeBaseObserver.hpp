/****************************************************************************
**
** Copyright (C) 2014-2015 Dinu SV.
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


#ifndef QCODEBASEOBSERVER_HPP
#define QCODEBASEOBSERVER_HPP

#include "QCSAGlobal.hpp"

namespace csa{

namespace ast{
class QASTNode;
class QASTFile;
}

class Q_CSA_EXPORT QCodeBaseObserver{

public:
    QCodeBaseObserver();
    virtual ~QCodeBaseObserver();

    virtual void clearAndReset() = 0;
    virtual void setSelected(ast::QASTNode* node) = 0;
    virtual void parse(const QList<ast::QASTFile*>& root) = 0;
};

}// namespace

#endif // QCODEBASEOBSERVER_HPP
