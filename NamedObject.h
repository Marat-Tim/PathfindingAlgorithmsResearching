#ifndef GRAPHS__NAMEDOBJECT_H_
#define GRAPHS__NAMEDOBJECT_H_

#include <string>
#include <utility>

template <class T>
class NamedObject {
public:
    NamedObject(const T &object, std::string name) : object_(object), name_(std::move(name)) {
    }

    T getObject() const {
        return object_;
    }

    T operator->() const {
        return object_;
    }

    std::string getName() const {
        return name_;
    }

private:
    T object_;

    std::string name_;
};

#endif  // GRAPHS__NAMEDOBJECT_H_
