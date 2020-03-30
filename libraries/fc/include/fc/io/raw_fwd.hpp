#pragma once
#include <array>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <variant>
#include <vector>

#include <boost/multiprecision/detail/number_base.hpp>

#include <fc/container/deque_fwd.hpp>
#include <fc/container/flat_fwd.hpp>
#include <fc/container/small_vector_fwd.hpp>
#include <fc/io/varint.hpp>

namespace google {

template<class Key, class T, class HashFcn, class EqualKey, class Alloc>
class dense_hash_map;

}  // namespace google

namespace fc {

class time_point;
class time_point_sec;
class variant;
class variant_object;
class path;

template<typename... Types>
class static_variant;

template<typename ENUM, typename... ARGS>
struct variant_wrapper;

template<typename IntType, typename EnumType>
class enum_type;

namespace ecc {
class public_key;
class private_key;
}  // namespace ecc

template<typename Storage>
class fixed_string;

namespace raw {
template<typename T>
inline size_t pack_size(const T& v);

template<typename Stream, typename Storage>
inline void pack(Stream& s, const fc::fixed_string<Storage>& u);
template<typename Stream, typename Storage>
inline void unpack(Stream& s, fc::fixed_string<Storage>& u);

template<typename Stream, typename IntType, typename EnumType>
inline void pack(Stream& s, const fc::enum_type<IntType, EnumType>& tp);
template<typename Stream, typename IntType, typename EnumType>
inline void unpack(Stream& s, fc::enum_type<IntType, EnumType>& tp);

template<typename Stream, typename T>
inline void pack(Stream& s, const std::set<T>& value);
template<typename Stream, typename T>
inline void unpack(Stream& s, std::set<T>& value);
template<typename Stream, typename T>
inline void pack(Stream& s, const std::unordered_set<T>& value);
template<typename Stream, typename T>
inline void unpack(Stream& s, std::unordered_set<T>& value);

template<typename Stream, typename... T>
void pack(Stream& s, const static_variant<T...>& sv);
template<typename Stream, typename... T>
void unpack(Stream& s, static_variant<T...>& sv);

template<typename Stream, typename... T>
void pack(Stream& s, const std::variant<T...>& var);
template<typename Stream, typename... T>
void unpack(Stream& s, std::variant<T...>& var);

template<typename Stream, typename ENUM, typename... ARGS>
void pack(Stream& s, const variant_wrapper<ENUM, ARGS...>& vw);
template<typename Stream, typename ENUM, typename... ARGS>
void unpack(Stream& s, variant_wrapper<ENUM, ARGS...>& vw);

template<typename Stream, typename T>
inline void pack(Stream& s, const std::deque<T>& value);
template<typename Stream, typename T>
inline void unpack(Stream& s, std::deque<T>& value);

template<typename Stream, typename K, typename V, typename ... Others>
inline void pack(Stream& s, const std::unordered_map<K, V, Others...>& value);
template<typename Stream, typename K, typename V, typename ... Others>
inline void unpack(Stream& s, std::unordered_map<K, V, Others...>& value);

template<typename Stream, typename K, typename V>
inline void pack(Stream& s, const std::map<K, V>& value);
template<typename Stream, typename K, typename V>
inline void unpack(Stream& s, std::map<K, V>& value);

template<typename Stream, typename K, typename V, typename ... Others>
inline void pack(Stream& s, const google::dense_hash_map<K, V, Others...>& value);
template<typename Stream, typename K, typename V, typename ... Others>
inline void unpack(Stream& s, google::dense_hash_map<K, V, Others...>& value);

template<typename Stream, typename K, typename V>
inline void pack(Stream& s, const std::pair<K, V>& value);
template<typename Stream, typename K, typename V>
inline void unpack(Stream& s, std::pair<K, V>& value);

template<typename Stream, typename... Types>
inline void pack(Stream& s, const std::tuple<Types...>& value);
template<typename Stream, typename... Types>
inline void unpack(Stream& s, std::tuple<Types...>& value);

template<typename Stream, typename T, std::size_t S>
inline auto pack(Stream& s, const std::array<T, S>& value)
    -> std::enable_if_t<std::is_trivially_copyable_v<T>>;
template<typename Stream, typename T, std::size_t S>
inline auto pack(Stream& s, const std::array<T, S>& value)
    -> std::enable_if_t<!std::is_trivially_copyable_v<T>>;
template<typename Stream, typename T, std::size_t S>
inline auto unpack(Stream& s, std::array<T, S>& value)
    -> std::enable_if_t<std::is_trivially_copyable_v<T>>;
template<typename Stream, typename T, std::size_t S>
inline auto unpack(Stream& s, std::array<T, S>& value)
    -> std::enable_if_t<!std::is_trivially_copyable_v<T>>;

template<typename Stream>
inline void pack(Stream& s, const variant_object& v);
template<typename Stream>
inline void unpack(Stream& s, variant_object& v);
template<typename Stream>
inline void pack(Stream& s, const variant& v);
template<typename Stream>
inline void unpack(Stream& s, variant& v);

template<typename Stream>
inline void pack(Stream& s, const path& v);
template<typename Stream>
inline void unpack(Stream& s, path& v);

template<typename Stream, typename T>
void unpack(Stream& s, std::optional<T>& v);
template<typename Stream, typename T>
void unpack(Stream& s, const T& v);
template<typename Stream, typename T>
void pack(Stream& s, const std::optional<T>& v);

template<typename Stream>
void unpack(Stream& s, time_point&);
template<typename Stream>
void pack(Stream& s, const time_point&);
template<typename Stream>
void unpack(Stream& s, time_point_sec&);
template<typename Stream>
void pack(Stream& s, const time_point_sec&);
template<typename Stream>
void unpack(Stream& s, std::string&);
template<typename Stream>
void pack(Stream& s, const std::string&);
template<typename Stream>
void unpack(Stream& s, fc::ecc::public_key&);
template<typename Stream>
void pack(Stream& s, const fc::ecc::public_key&);
template<typename Stream>
void unpack(Stream& s, fc::ecc::private_key&);
template<typename Stream>
void pack(Stream& s, const fc::ecc::private_key&);

template<typename Stream, typename T>
inline void pack(Stream& s, const T& v);
template<typename Stream, typename T>
inline void unpack(Stream& s, T& v);

template<typename Stream, typename T>
inline void pack(Stream& s, const std::vector<T>& v);
template<typename Stream, typename T>
inline void unpack(Stream& s, std::vector<T>& v);

template<typename Stream>
inline void pack(Stream& s, const signed_int& v);
template<typename Stream>
inline void unpack(Stream& s, signed_int& vi);

template<typename Stream>
inline void pack(Stream& s, const unsigned_int& v);
template<typename Stream>
inline void unpack(Stream& s, unsigned_int& vi);

template<typename Stream>
inline void pack(Stream& s, const char* v);
template<typename Stream>
inline void pack(Stream& s, const std::vector<char>& value);
template<typename Stream>
inline void unpack(Stream& s, std::vector<char>& value);

template<typename Stream>
inline void pack(Stream& s, const bool& v);
template<typename Stream>
inline void unpack(Stream& s, bool& v);

template<typename T>
inline std::vector<char> pack(const T& v);
template<typename T>
inline T unpack(const std::vector<char>& s);
template<typename T>
inline T unpack(const char* d, uint32_t s);
template<typename T>
inline void unpack(const char* d, uint32_t s, T& v);

template<typename Stream, typename T>
void pack(Stream& s, const boost::multiprecision::number<T>& n);
template<typename Stream, typename T>
void unpack(Stream& s, boost::multiprecision::number<T>& n);

}  // namespace raw
}  // namespace fc
