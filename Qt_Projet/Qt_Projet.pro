QT += core
QT += widgets
QT += xml

QMAKE_CXXFLAGS = -std=c++11
QMAKE_LFLAGS = -std=c++11

HEADERS += \
    Relations.h \
    NoteEditeur.h \
    FenetrePrincipale.h \
    Notes.h \
    Manager.h \
    QNotes.h \
    RelationEditeur.h \
    NewNote.h

SOURCES += \
    main.cpp \
    Relations.cpp \
    NoteEditeur.cpp \
    FenetrePrincipale.cpp \
    Notes.cpp \
    Manager.cpp \
    QNotes.cpp \
    RelationEditeur.cpp \
    NewNote.cpp

