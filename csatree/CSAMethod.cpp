#include "CSAMethod.hpp"
#include "CSAClass.hpp"
#include "AnnotatedTokenSet.hpp"
#include "TokenClassifier.hpp"
#include "SourceLocation.hpp"
#include "clang-c/Index.h"

#include <QDebug>

namespace csa{ namespace ast{

CSAMethod::CSAMethod(
        AnnotatedTokenSet *tokenSet,
        TokenClassifier* classifier,
        SourceLocation* cursorLocation,
        SourceLocation* rangeStartLocation,
        SourceLocation* rangeEndLocation,
        CSANode* parent)

    : CSANode("method", cursorLocation, rangeStartLocation, rangeEndLocation, parent){

    if ( tokenSet->size() == 0 ){
        CXType type          = clang_getCursorType(tokenSet->cursor());
        CXString typeStr     = clang_getTypeSpelling(type);
        const char* cTypeStr = clang_getCString(typeStr);
        m_identifier         = cTypeStr;
        clang_disposeString(typeStr);
    }

    bool spaceFlag = false;

    for ( AnnotatedTokenSet::Iterator it = tokenSet->begin(); it != tokenSet->end(); ++it ){
        CXToken t = *it;
        CXString tSpelling = clang_getTokenSpelling(tokenSet->translationUnit(), t);
        CXTokenKind tKind  = clang_getTokenKind(t);
        if ( tKind == CXToken_Punctuation && std::string(clang_getCString(tSpelling)) == "("){

            m_identifier += clang_getCString(tSpelling);
            int numargs = clang_Cursor_getNumArguments(tokenSet->cursor());
            for ( int i = 0; i < numargs; ++i ){

                CXCursor crs                      = clang_Cursor_getArgument(tokenSet->cursor(), i);
                AnnotatedTokenSet* cursorTokenSet = classifier->findTokenSet(crs);

                if ( cursorTokenSet ){
                    bool argSpaceFlag = false;
                    for ( AnnotatedTokenSet::Iterator it = cursorTokenSet->begin(); it != cursorTokenSet->end(); ++it ){
                        CXToken t = *it;
                        CXString tArgSpelling = clang_getTokenSpelling(tokenSet->translationUnit(), t);
                        CXTokenKind tArgKind  = clang_getTokenKind(t);
                        if ( tArgKind == CXToken_Punctuation ){

                            m_identifier += clang_getCString(tArgSpelling);

                            if ( std::string(clang_getCString(tArgSpelling)) == "&" || std::string(clang_getCString(tArgSpelling)) == "*" )
                                m_identifier += " ";
                            argSpaceFlag    = false;
                        } else {
                            if ( argSpaceFlag ){
                                m_identifier += std::string(" ");
                                argSpaceFlag = false;
                            }
                            m_identifier += clang_getCString(tArgSpelling);
                            argSpaceFlag     = true;
                        }
                        clang_disposeString(tArgSpelling);
                    }
                    if ( i != numargs - 1 )
                        m_identifier += ", ";
                }
            }

        } else if ( tKind != CXToken_Punctuation || std::string(clang_getCString(tSpelling)) != "," ){
            if ( tKind == CXToken_Punctuation ){

                m_identifier += clang_getCString(tSpelling);

                if ( std::string(clang_getCString(tSpelling)) == "&" || std::string(clang_getCString(tSpelling)) == "*" )
                    m_identifier += " ";
                spaceFlag    = false;
            } else {
                if ( spaceFlag ){
                    m_identifier += std::string(" ");
                    spaceFlag = false;
                }
                m_identifier += clang_getCString(tSpelling);
                spaceFlag     = true;
            }
        }
        clang_disposeString(tSpelling);
    }

}

}}// namespace
