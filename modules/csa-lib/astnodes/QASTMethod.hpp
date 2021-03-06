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


#ifndef QASTMETHOD_HPP
#define QASTMETHOD_HPP

#include "QCSAGlobal.hpp"
#include "QASTNode.hpp"

namespace csa{

class QTokenClassifier;

namespace ast{

class Q_CSA_EXPORT QASTMethod : public QASTNode{

public:
    QASTMethod(
            QAnnotatedTokenSet* tokenSet,
            QTokenClassifier* classifier,
            QSourceLocation* cursorLocation,
            QSourceLocation* rangeStartLocation,
            QSourceLocation* rangeEndLocation,
            QASTNode* parent = 0);

    virtual QString description() const;

public slots:
    virtual QList<QObject*> arguments() const;
    virtual QString prop(const QString& key) const;

private:
    QString m_returnType;

    bool    m_isStatic;
    bool    m_isVirtual;
    bool    m_isPureVirtual;
    bool    m_isConst;
    bool    m_isInline;

    QList<csa::ast::QASTNode*> m_arguments;
};

inline QString QASTMethod::prop(const QString& key) const{
    if ( key == "returnType" )
        return m_returnType;
    return QASTNode::prop(key);
}

}}// namespace

#endif // QASTMETHOD_HPP
