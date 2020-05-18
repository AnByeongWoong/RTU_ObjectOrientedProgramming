#pragma once
#include "ItemSpec.h"
#include <string>

class GuitarSpec : public ItemSpec
{
public:
    enum class Type { ANY, ACOUSTIC, ELECTRIC };

    GuitarSpec() = default;
    GuitarSpec(const std::string & model, Type type)
        : ItemSpec(), _model(model), _type(type) { }

    bool matches(const ItemSpec & itemSpec) const override;

    std::string get_model() const { return _model; }
    Type get_type() const { return _type; }

    void send_to(std::ostream & os) const override;
private:
    std::string _model;
    Type _type;
};

