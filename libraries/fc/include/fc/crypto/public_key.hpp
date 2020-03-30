#pragma once
#include <fc/crypto/elliptic.hpp>
#include <fc/crypto/elliptic_r1.hpp>
#include <fc/crypto/signature.hpp>
#include <fc/reflect/reflect.hpp>
#include <fc/reflect/variant.hpp>
#include <fc/static_variant.hpp>

namespace fc { namespace crypto {

namespace config {
constexpr const char* public_key_vast_prefix = "VAST";
constexpr const char* public_key_prefix[]   = { "K1", "R1" };
};  // namespace config

class public_key {
public:
    using storage_type = static_variant<ecc::public_key_shim, r1::public_key_shim>;

    public_key()                  = default;
    public_key(public_key&&)      = default;
    public_key(const public_key&) = default;
    
    public_key(const ecc::public_key_shim& ecc_key);
    public_key(const signature& c, const sha256& digest, bool check_canonical = true);

    public_key& operator=(const public_key&) = default;

    bool valid() const;

    // serialize to/from string
    explicit public_key(const string& base58str);
    explicit public_key(const char* base58str);
    explicit operator string() const;

private:
    storage_type _storage;

    public_key(storage_type&& other_storage)
        : _storage(forward<storage_type>(other_storage)) {}

    friend std::ostream& operator<<(std::ostream& s, const public_key& k);

    friend bool operator==(const public_key& p1, const public_key& p2);
    friend bool operator!=(const public_key& p1, const public_key& p2);
    friend bool operator<(const public_key& p1, const public_key& p2);
    
    friend struct reflector<public_key>;
    friend class private_key;
};  // public_key

}}  // namespace fc::crypto

namespace fc {
void to_variant(const crypto::public_key& var, variant& vo);
void from_variant(const variant& var, crypto::public_key& vo);
}  // namespace fc

FC_REFLECT(fc::crypto::public_key, (_storage));