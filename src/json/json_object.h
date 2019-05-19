#ifndef JSON_OBJECT_H
#define JSON_OBJECT_H

#include "../global.h"
#include "json_value.h"
#include <string>
#include <map>

TOOSKA_BEGIN_NAMESPACE(core)
class string_renderer;
TOOSKA_END_NAMESPACE

TOOSKA_BEGIN_NAMESPACE(json)
class json_object : public json_value
{
    std::map<std::string, json_value*> _values;

public:
    json_object();

    virtual ~json_object();
    void insert(const std::string &name, json_value *value);
    json_value *get(const std::string &name);

    json_value *operator[](const std::string &name);

private:
    void render(core::string_renderer &r);

    friend class json_document;
};

TOOSKA_END_NAMESPACE

#endif // JSON_OBJECT_H
