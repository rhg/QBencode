#include "QBencode.h"

QBencode::QBencode(QObject *parent) : QObject(parent)
{

}

QString QBencode::from() {
    return QString::fromUtf8(mBencode.str, mBencode.len);
}

void QBencode::setFrom(QString source) {
    if (source != from()) {
        auto str = source.toUtf8();
        bencode_init(&mBencode, str.data(), str.length());
        emit fromChanged();
    }
}

QBencode::Type QBencode::type() {
    if (bencode_is_int(&mBencode)) {
        return Type::Int;
    } else if (bencode_is_string(&mBencode)) {
        return Type::String;
    } else if (bencode_is_list(&mBencode)) {
        return Type::List;
    } else if (bencode_is_dict(&mBencode)) {
        return Type::Dict;
    } else {
        return Type::Unknown;
    }
}
