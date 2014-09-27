/* Vault is a lightweight and simple crypt library. No dependencies. BOOST licensed.
 * - rlyeh
 */

#pragma once

#include <string>

namespace vault
{
    namespace encrypt
    {
        // @todo: provide more encrypting algorithms in here.
        // [...]
    }
    namespace decrypt
    {
        // @todo: provide more decrypting algorithms in here.
        // [...]
    }
    namespace swap
    {
        // @todo: provide more swapping algorithms in here.
        std::string ARC4( const std::string &text, const std::string &passkey );
    }

    using swap::ARC4;
}
