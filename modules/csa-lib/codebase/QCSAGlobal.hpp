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


#ifndef QCSAGLOBAL_HPP
#define QCSAGLOBAL_HPP

#include <qglobal.h>

#ifndef Q_CSA_STATIC
#  ifdef Q_CSA_LIB
#    define Q_CSA_EXPORT Q_DECL_EXPORT
#  else
#    define Q_CSA_EXPORT Q_DECL_IMPORT
#  endif
#else
#  define Q_CSA_EXPORT
#endif

#endif // QCSAGLOBAL_HPP
