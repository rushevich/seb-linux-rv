/****************************************************************************
** Meta object code from reading C++ file 'browser_view.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/browser/engine/browser_view.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'browser_view.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN3seb7browser6engine11BrowserViewE_t {};
} // unnamed namespace

template <> constexpr inline auto seb::browser::engine::BrowserView::qt_create_metaobjectdata<qt_meta_tag_ZN3seb7browser6engine11BrowserViewE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "seb::browser::engine::BrowserView",
        "urlChanged",
        "",
        "QUrl",
        "url",
        "titleChanged",
        "title",
        "newWindowRequested",
        "targetUrl",
        "openerUrl"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'urlChanged'
        QtMocHelpers::SignalData<void(const QUrl &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Signal 'titleChanged'
        QtMocHelpers::SignalData<void(const QString &)>(5, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 6 },
        }}),
        // Signal 'newWindowRequested'
        QtMocHelpers::SignalData<void(const QUrl &, const QUrl &)>(7, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 8 }, { 0x80000000 | 3, 9 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<BrowserView, qt_meta_tag_ZN3seb7browser6engine11BrowserViewE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject seb::browser::engine::BrowserView::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN3seb7browser6engine11BrowserViewE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN3seb7browser6engine11BrowserViewE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN3seb7browser6engine11BrowserViewE_t>.metaTypes,
    nullptr
} };

void seb::browser::engine::BrowserView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<BrowserView *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->urlChanged((*reinterpret_cast<std::add_pointer_t<QUrl>>(_a[1]))); break;
        case 1: _t->titleChanged((*reinterpret_cast<std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->newWindowRequested((*reinterpret_cast<std::add_pointer_t<QUrl>>(_a[1])),(*reinterpret_cast<std::add_pointer_t<QUrl>>(_a[2]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (BrowserView::*)(const QUrl & )>(_a, &BrowserView::urlChanged, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (BrowserView::*)(const QString & )>(_a, &BrowserView::titleChanged, 1))
            return;
        if (QtMocHelpers::indexOfMethod<void (BrowserView::*)(const QUrl & , const QUrl & )>(_a, &BrowserView::newWindowRequested, 2))
            return;
    }
}

const QMetaObject *seb::browser::engine::BrowserView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *seb::browser::engine::BrowserView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN3seb7browser6engine11BrowserViewE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int seb::browser::engine::BrowserView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void seb::browser::engine::BrowserView::urlChanged(const QUrl & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void seb::browser::engine::BrowserView::titleChanged(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}

// SIGNAL 2
void seb::browser::engine::BrowserView::newWindowRequested(const QUrl & _t1, const QUrl & _t2)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 2, nullptr, _t1, _t2);
}
QT_WARNING_POP
