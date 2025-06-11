/****************************************************************************
** Meta object code from reading C++ file 'pushboxdialog.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PushBox/pushboxdialog.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pushboxdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSPushBoxDialogENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSPushBoxDialogENDCLASS = QtMocHelpers::stringData(
    "PushBoxDialog",
    "backToSelection",
    "",
    "keyPressEvent",
    "QKeyEvent*",
    "event",
    "onExitGame",
    "onRestartGame",
    "onShowPopup"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSPushBoxDialogENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[14];
    char stringdata1[16];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[11];
    char stringdata5[6];
    char stringdata6[11];
    char stringdata7[14];
    char stringdata8[12];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSPushBoxDialogENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSPushBoxDialogENDCLASS_t qt_meta_stringdata_CLASSPushBoxDialogENDCLASS = {
    {
        QT_MOC_LITERAL(0, 13),  // "PushBoxDialog"
        QT_MOC_LITERAL(14, 15),  // "backToSelection"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 13),  // "keyPressEvent"
        QT_MOC_LITERAL(45, 10),  // "QKeyEvent*"
        QT_MOC_LITERAL(56, 5),  // "event"
        QT_MOC_LITERAL(62, 10),  // "onExitGame"
        QT_MOC_LITERAL(73, 13),  // "onRestartGame"
        QT_MOC_LITERAL(87, 11)   // "onShowPopup"
    },
    "PushBoxDialog",
    "backToSelection",
    "",
    "keyPressEvent",
    "QKeyEvent*",
    "event",
    "onExitGame",
    "onRestartGame",
    "onShowPopup"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSPushBoxDialogENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   45,    2, 0x0a,    2 /* Public */,
       6,    0,   48,    2, 0x0a,    4 /* Public */,
       7,    0,   49,    2, 0x0a,    5 /* Public */,
       8,    0,   50,    2, 0x0a,    6 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject PushBoxDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSPushBoxDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSPushBoxDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSPushBoxDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<PushBoxDialog, std::true_type>,
        // method 'backToSelection'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'keyPressEvent'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QKeyEvent *, std::false_type>,
        // method 'onExitGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onRestartGame'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onShowPopup'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void PushBoxDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PushBoxDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->backToSelection(); break;
        case 1: _t->keyPressEvent((*reinterpret_cast< std::add_pointer_t<QKeyEvent*>>(_a[1]))); break;
        case 2: _t->onExitGame(); break;
        case 3: _t->onRestartGame(); break;
        case 4: _t->onShowPopup(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PushBoxDialog::*)();
            if (_t _q_method = &PushBoxDialog::backToSelection; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *PushBoxDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PushBoxDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSPushBoxDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int PushBoxDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void PushBoxDialog::backToSelection()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
