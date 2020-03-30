/**
 *  @file
 *  @copyright defined in vast/LICENSE.txt
 */
#pragma once
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <libvast/vast.h>
#include <fc/io/raw.hpp>

#define CATCH_AND_RETURN(err)         \
    catch(fc::exception& e) {         \
        vast_set_last_error(e.code()); \
        return err;                   \
    }                                 \
    catch(...) {                      \
        vast_set_last_error(-1);       \
        return err;                   \
    }

template <typename T>
vast_data_t*
get_vast_data(const T& val) {
    auto rsz = fc::raw::pack_size<T>(val);
    auto sz  = sizeof(vast_data_t) + rsz;

    auto data = (vast_data_t*)malloc(sz);
    data->sz  = rsz;

    auto ds = fc::datastream<char*>(data->buf, rsz);
    fc::raw::pack(ds, val);

    return data;
}

template <typename T>
int
extract_data(vast_data_t* data, T& val) {
    auto ds = fc::datastream<char*>(data->buf, data->sz);
    try {
        fc::raw::unpack(ds, val);
    }
    CATCH_AND_RETURN(VAST_INVALID_BINARY)

    return VAST_OK;
}

inline char*
strdup(const std::string& str) {
    auto s = (char*)malloc(str.size() + 1); // add '\0'
    memcpy(s, str.data(), str.size());
    s[str.size()] = '\0';
    return s;
}
