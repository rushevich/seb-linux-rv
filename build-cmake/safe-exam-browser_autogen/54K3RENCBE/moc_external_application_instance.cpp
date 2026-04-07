/****************************************************************************
** Meta object code from reading C++ file 'external_application_instance.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/applications/external_application_instance.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'external_application_instance.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN3seb12applications27ExternalApplicationInstanceE_t {};
} // unnamed namespace

template <> constexpr inline auto seb::applications::ExternalApplicationInstance::qt_create_metaobjectdata<qt_meta_tag_ZN3seb12applications27ExternalApplicationInstanceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "seb::applications::ExternalApplicationInstance",
        "terminated",
        "",
        "processId",
        "windowsChanged"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'terminated'
        QtMocHelpers::SignalData<void(qint64)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::LongLong, 3 },
        }}),
        // Signal 'windowsChanged'
        QtMocHelpers::SignalData<void()>(4, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ExternalApplicationInstance, qt_meta_tag_ZN3seb12applications27ExternalApplicationInstanceE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject seb::applications::ExternalApplicationInstance::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN3seb12applications27ExternalApplicationInstanceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN3seb12applications27ExternalApplicationInstanceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN3seb12applications27ExternalApplicationInstanceE_t>.metaTypes,
    nullptr
} };

void seb::applications::ExternalApplicationInstance::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ExternalApplicationInstance *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->terminated((*reinterpret_cast<std::add_pointer_t<qint64>>(_a[1]))); break;
        case 1: _t->windowsChanged(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ExternalApplicationInstance::*)(qint64 )>(_a, &ExternalApplicationInstance::terminated, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (ExternalApplicationInstance::*)()>(_a, &ExternalApplicationInstance::windowsChanged, 1))
            return;
    }
}

const QMetaObject *seb::applications::ExternalApplicationInstance::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *seb::applications::ExternalApplicationInstance::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN3seb12applications27ExternalApplicationInstanceE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int seb::applications::ExternalApplicationInstance::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void seb::applications::ExternalApplicationInstance::terminated(qint64 _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void seb::applications::ExternalApplicationInstance::windowsChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
