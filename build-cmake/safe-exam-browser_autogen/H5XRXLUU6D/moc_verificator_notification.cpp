/****************************************************************************
** Meta object code from reading C++ file 'verificator_notification.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/client/notifications/verificator_notification.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'verificator_notification.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.11.0. It"
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
struct qt_meta_tag_ZN3seb6client13notifications23VerificatorNotificationE_t {};
} // unnamed namespace

template <> constexpr inline auto seb::client::notifications::VerificatorNotification::qt_create_metaobjectdata<qt_meta_tag_ZN3seb6client13notifications23VerificatorNotificationE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "seb::client::notifications::VerificatorNotification",
        "activationRequested",
        "",
        "terminationRequested",
        "activate",
        "terminate"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'activationRequested'
        QtMocHelpers::SignalData<void()>(1, 2, QMC::AccessPublic, QMetaType::Void),
        // Signal 'terminationRequested'
        QtMocHelpers::SignalData<void()>(3, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'activate'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
        // Slot 'terminate'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<VerificatorNotification, qt_meta_tag_ZN3seb6client13notifications23VerificatorNotificationE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject seb::client::notifications::VerificatorNotification::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN3seb6client13notifications23VerificatorNotificationE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN3seb6client13notifications23VerificatorNotificationE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN3seb6client13notifications23VerificatorNotificationE_t>.metaTypes,
    nullptr
} };

void seb::client::notifications::VerificatorNotification::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<VerificatorNotification *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->activationRequested(); break;
        case 1: _t->terminationRequested(); break;
        case 2: _t->activate(); break;
        case 3: _t->terminate(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (VerificatorNotification::*)()>(_a, &VerificatorNotification::activationRequested, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (VerificatorNotification::*)()>(_a, &VerificatorNotification::terminationRequested, 1))
            return;
    }
}

const QMetaObject *seb::client::notifications::VerificatorNotification::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *seb::client::notifications::VerificatorNotification::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN3seb6client13notifications23VerificatorNotificationE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int seb::client::notifications::VerificatorNotification::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void seb::client::notifications::VerificatorNotification::activationRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void seb::client::notifications::VerificatorNotification::terminationRequested()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
