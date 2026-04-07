/****************************************************************************
** Meta object code from reading C++ file 'window_list_popup.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.11.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/ui/taskbar/controls/window_list_popup.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'window_list_popup.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN3seb2ui7taskbar15WindowListPopupE_t {};
} // unnamed namespace

template <> constexpr inline auto seb::ui::taskbar::WindowListPopup::qt_create_metaobjectdata<qt_meta_tag_ZN3seb2ui7taskbar15WindowListPopupE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "seb::ui::taskbar::WindowListPopup",
        "windowSelected",
        "",
        "BrowserWindow*",
        "window"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'windowSelected'
        QtMocHelpers::SignalData<void(BrowserWindow *)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<WindowListPopup, qt_meta_tag_ZN3seb2ui7taskbar15WindowListPopupE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject seb::ui::taskbar::WindowListPopup::staticMetaObject = { {
    QMetaObject::SuperData::link<TaskbarPopup::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN3seb2ui7taskbar15WindowListPopupE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN3seb2ui7taskbar15WindowListPopupE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN3seb2ui7taskbar15WindowListPopupE_t>.metaTypes,
    nullptr
} };

void seb::ui::taskbar::WindowListPopup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<WindowListPopup *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->windowSelected((*reinterpret_cast<std::add_pointer_t<BrowserWindow*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (WindowListPopup::*)(BrowserWindow * )>(_a, &WindowListPopup::windowSelected, 0))
            return;
    }
}

const QMetaObject *seb::ui::taskbar::WindowListPopup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *seb::ui::taskbar::WindowListPopup::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN3seb2ui7taskbar15WindowListPopupE_t>.strings))
        return static_cast<void*>(this);
    return TaskbarPopup::qt_metacast(_clname);
}

int seb::ui::taskbar::WindowListPopup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TaskbarPopup::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void seb::ui::taskbar::WindowListPopup::windowSelected(BrowserWindow * _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}
QT_WARNING_POP
